/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments and taken help from preet Jaiminkumar dave (NAA) in run and const char operator with int parametre function.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"

#include <iostream>

#include <cstring>

#include <iomanip>

using namespace std;
namespace sdds {

    MenuItem::MenuItem() {
        m_content = nullptr;
    }

    MenuItem::MenuItem(const char* content) {
        if (content != nullptr) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            m_content = nullptr;
        }
    }

    MenuItem::operator const char* () const {
        return m_content;
    }
    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    void MenuItem::display() const {
        cout << m_content;
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
    }

    // Menu class started

    Menu::Menu() {
        m_title.m_content = nullptr;
        m_items[0] = nullptr;
        m_numOfItems = 0;
    }

    Menu::Menu(const char* title) {

        if (title != nullptr) {
            m_title.m_content = new char[strlen(title) + 1];

            strcpy(m_title.m_content, title);
            for (int i = 0; i < m_numOfItems; i++) {

                delete m_items[i];
                m_items[i] = nullptr;
            }
            m_numOfItems = 0;
        }
    }

    void Menu::display_title(std::ostream& cout) const {

        if (m_title != nullptr)
            cout << m_title.m_content;
    }

    void Menu::display() const {

        if (m_title.m_content != nullptr)
            cout << m_title.m_content << ':' << endl;

        if (m_numOfItems > 0) {
            for (int i = 1; i <= m_numOfItems; i++) {
                cout.width(2);
                cout.setf(ios::right);
                cout << i;

                cout << "- ";
                cout << m_items[i - 1]->m_content << endl;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
    }

    std::ostream& Menu::read(ostream& cout) const {
        if (m_title != nullptr)
            cout << m_title.m_content;
        return cout;
    }

    std::ostream& operator << (std::ostream& cout,const Menu& Ro) {
        Ro.display_title(cout);
        return cout;
    }

    Menu& Menu::operator << (const char* menuitemConent) {
        if (menuitemConent != nullptr && m_numOfItems < MAX_MENU_ITEMS) {
            m_items[m_numOfItems] = new MenuItem(menuitemConent);
            m_numOfItems++;
        }
        return *this;
    }

    Menu::operator bool() const {
        return (!isEmpty());
    }

    Menu::operator int() const {
        return m_numOfItems;
    }

    Menu::operator unsigned int() const {
        return m_numOfItems;
    }

    void Menu::setEmpty() {
        delete[] m_title;
        m_title.m_content = nullptr;
        for (int i = 0; i < m_numOfItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
        m_numOfItems = 0;
    }

    bool Menu::isEmpty() const {
        return m_title == nullptr;
    }

    const char* Menu::operator[](int index) const {
        return *m_items[index % m_numOfItems];
    }

    int Menu::operator~() const {
        return run();
    }

    int Menu::run() const {
        display();
        bool flag = false;
        int temp = 0;
        do {
            if (!(cin >> temp) || temp < 0 || temp > m_numOfItems) {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Invalid Selection, try again: ";

            }
            else
                flag = true;
        } while (!flag);
        return temp;
    }

    Menu::~Menu() {

        delete[] m_title;
        m_title.m_content = nullptr;

        for (int i = 0; i < m_numOfItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }
}