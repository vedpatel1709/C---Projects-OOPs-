/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NDD
Workshop 4 part 2
Date: 10th october,2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstring>

#include"Book.h"

using namespace std;

namespace sdds {
    Book::Book() {
        setEmpty();
    }

    Book::Book(const char* name, int numChapters,
        const Chapter* chapters) {
        setEmpty();
        if (name != nullptr && name[0] != '\0' && chapters != nullptr && numChapters > 0)

        {
            //m_noOfChapter;
            setName(name);
            m_noOfChapter = numChapters;
            m_chapter = new Chapter[m_noOfChapter];
            int i = 0;
            for (i = 0; i < m_noOfChapter; i++) {
                m_chapter[i] = chapters[i];
            }
        }
    }
    void Book::setName(const char* name) {
        delete[] m_name;

        if (name != nullptr && name[0] != '\0') {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        else {
            delete[] m_chapter;
            setEmpty();
        }
    }

    void Book::setEmpty() {
        m_name = nullptr;
        m_chapter = nullptr;
        m_noOfChapter = 0;
    }

    bool Book::isEmpty() const {
        if (m_name == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    Book::~Book() {
        delete[] m_name;
        m_name = nullptr;
        delete[] m_chapter;
        m_chapter = nullptr;
    }

    Book& Book::addChapter(const char* Chapter_name, int noOfPages) {
        if (Chapter_name[0] != '\0' && noOfPages >= 1 && noOfPages <= PAGES) {

            Chapter* new_temp_ch = new Chapter[m_noOfChapter + 1];
            for (int i = 0; i < m_noOfChapter; i++) {
                new_temp_ch[i] = m_chapter[i];
            }
            delete[] m_chapter;
            strcpy(new_temp_ch[m_noOfChapter].getName(), Chapter_name);
            new_temp_ch[m_noOfChapter].getPage() = noOfPages;
            m_chapter = new_temp_ch;
            m_noOfChapter++;
        }
        return *this;
    }

    void Book::display() const {
        int count = 0;
        int i;
        for (i = 0; i < m_noOfChapter; i++) {
            if (m_chapter[i].isEmpty()) {
                count++;
            }
            else {}
        }
        if (!isEmpty() && (count == 0)) {
            cout << "Book Name: " << m_name << endl;
            cout << "No of Chapters: " << m_noOfChapter << endl;
            cout.width(51);
            cout.setf(ios::left);
            cout << "Chapter name" << "Pages";
            cout << endl;
            for (int i = 0; i < m_noOfChapter; i++) {
                m_chapter[i].display();
            }
        }
        else {
            cout << "Invalid Book object" << endl;
        }
    }
}