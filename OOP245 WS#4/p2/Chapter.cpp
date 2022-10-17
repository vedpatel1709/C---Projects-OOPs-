/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NDD
Workshop 4 part 2
Date: 10th october,2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<cstring>

#include"Chapter.h"

using namespace std;

namespace sdds {
    Chapter::Chapter() {
        setEmpty();
    }

    void Chapter::setEmpty() {
        m_ChapterName[0] = '\0';
        m_pages = 0;
    }

    Chapter::Chapter(const char* name, int page) {
        if (name != nullptr && strlen(name) > 0 && page > 0) {
            strcpy(m_ChapterName, name);
            m_pages = page;
        }
        else {
            setEmpty();
        }
    }

    void Chapter::display() const {
        if (!isEmpty()) {
            cout.width(50);
            cout.fill('.');
            cout.setf(ios::left);
            cout << m_ChapterName;
            cout.unsetf(ios::left);

            cout.fill(' ');
            cout.width(4);
            cout.setf(ios::right);
            cout << m_pages << endl;
            cout.unsetf(ios::right);
            cout.fill(' ');
        }
        else {
            cout << "invalid Chapter" << endl;
        }
    }

    bool Chapter::isEmpty() const {

        if ((m_ChapterName[0] == '\0') && (m_pages < 1)) {
            return true;
        }
        else {
            return false;
        }
    }

    int& Chapter::getPage() {
        return m_pages;
    }

    char* Chapter::getName() {
        return m_ChapterName;
    }
}