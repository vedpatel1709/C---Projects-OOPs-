/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------


Name: Patel Ved Rajendrakumar
Id: 149409203
Section:NAA
Email:vrpatel33@myseneca.ca
*/
#pragma once
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include "Publication.h"
namespace sdds
{
    class Book : public Publication
    {
        char* m_author;

    public:
        Book();

        //rule of three
        Book(const Book& src);
        Book& operator=(const Book& src);
        ~Book();

        char type() const;
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        void set(int member_id);
        operator bool() const;
    };
}
#endif //! SDDS_BOOK_H__
