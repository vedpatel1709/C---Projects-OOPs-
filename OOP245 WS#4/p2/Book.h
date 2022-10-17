/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NDD
Workshop 4 part 2
Date: 10th october,2021
*/

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_Book_H
#define SDDS_Book_H
#include "Chapter.h"

namespace sdds {
    class Book {
        char* m_name;
        int m_noOfChapter;
        Chapter* m_chapter = nullptr;
    public:
        Book();
        Book(const char* name, int noOfChapter,
            const Chapter* city);
        void setEmpty();
        bool isEmpty() const;
        void setName(const char* name);
        ~Book();
        Book& addChapter(const char* Chapter_name, int noOfPages);
        void display() const;
    };
}
#endif