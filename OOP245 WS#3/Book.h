// name  : Patel Ved Rajendrakumar
// ID    : 149409203
// email :vrpatel33@myseneca.ca
//section:OOP244 NDD
// workshop-3 part-1

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<cstring>

#ifndef _SDDS_BOOK_H_
#define _SDDS_BOOK_H_

using namespace std;
namespace sdds {

    class Book {

    private:
        char m_title[51];
        //will hold 50 charactors
        int m_SKU;
        //Stock Keeping Unit number,
        int m_daysOnLoan;
        //The number of days on loan.
        void setEmpty();
        double penalty() const;

    public:
        void set(const char* book_title, int SKU, int loanDays);
        bool isEmpty() const;
        bool hasPenalty() const;
        bool subTitle(const char* substr) const;
        void display() const;

    };
}
#endif