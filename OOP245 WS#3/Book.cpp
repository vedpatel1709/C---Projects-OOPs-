// name  : Patel Ved Rajendrakumar
// ID    : 149409203
// email :vrpatel33@myseneca.ca
//section:OOP244 NDD
// workshop-3 part-1
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include<cstring>

#include"Book.h"

using namespace std;
namespace sdds {
    const double PENALTY = 1.5; 
    const int MAXLOAN = 15; 

    double Book::penalty() const {
        double value = 0;
        if (hasPenalty()) {
            value = (m_daysOnLoan - MAXLOAN) * PENALTY;
        }
        return value;
    }

    void Book::setEmpty() {
        m_title[0] = '\0';
        m_SKU = 0;
        m_daysOnLoan = 0;
    }

    void Book::set(const char* book_title, int SKU, int loanDays) {
        if ((book_title != nullptr && book_title[0] != '\0') && SKU > 0 && loanDays > 0) {
            strcpy(m_title, book_title);
            m_SKU = SKU;
            m_daysOnLoan = loanDays;
        }
        else {
            setEmpty();
        }
    }

    bool Book::isEmpty() const {
        if (m_title[0] == '\0' && m_SKU == 0 && m_daysOnLoan == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Book::hasPenalty() const {
        if (m_daysOnLoan > MAXLOAN) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Book::subTitle(const char* substr) const {
        if (strstr(m_title, substr) != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    // learned to use cout.width, cout.fill, cout.setf, cout.prcision from google by my self.
    void Book::display() const {
        if (!isEmpty()) { // Title
            cout.width(49); // cout.width is used to call width to announce space of the array
            cout.fill(' ');
            cout.setf(ios::left);
            cout << m_title;
            //SKU
            cout.width(8);
            cout.fill(' ');
            cout.setf(ios::left);

            cout << m_SKU;
            //NUMBER OF DAYS ON LOAN
            cout.width(10);
            cout.fill(' ');
            cout.setf(ios::left);
            cout << m_daysOnLoan;
            if (hasPenalty()) { // Penalty
                cout.width(7);
                cout.setf(ios::fixed);
                cout.setf(ios::right);
                cout.precision(2);
                cout << penalty();
                cout.unsetf(ios::right);
            }
            cout << endl;

        }
        else
            cout << "Invalid Library book" << endl;
    }
}