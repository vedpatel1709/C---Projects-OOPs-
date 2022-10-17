// name  : Patel Ved Rajendrakumar
// ID    : 149409203
// email :vrpatel33@myseneca.ca
//section:OOP244 NDD
// workshop-3 part-1
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include<cstring>

#include "Book.h"

#ifndef SDDS_LIBRARY_H
#define SDDS_LIBRARY_H

namespace sdds {
    class Library {
    private:
        char m_name[31]; //31 char in array
        Book* m_books; // pointer of book
        int m_sizeOfBooksArray;
        int m_addedBooks;

        void setEmpty();
        bool isEmpty() const;
        void header(const char* title) const;
        void footer() const;

    public:

        void initialize(const char* name, int noOfBooks);
        bool addBook(const char* book_title, int sku, int loanDays);
        void clear();
        void display(const char* substr);
        void display(bool overdueOnly = false) const;

    };
}

#endif