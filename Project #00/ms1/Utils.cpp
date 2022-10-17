/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "Menu.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {

    Date::operator bool() const {
        return m_ErrorCode == 0 ? true : false;
    }
    int Date::operator-(const Date& Ro) const {
        return (*this).daysSince0001_1_1() - Ro.daysSince0001_1_1();
    }
    bool Date::operator==(const Date& Ro) const {
        return (*this).daysSince0001_1_1() == Ro.daysSince0001_1_1();
    }
    bool Date::operator!=(const Date& Ro) const {
        return (*this).daysSince0001_1_1() != Ro.daysSince0001_1_1();
    }
    bool Date::operator>=(const Date& Ro) const {
        return (*this).daysSince0001_1_1() >= Ro.daysSince0001_1_1();

    }
    bool Date::operator<=(const Date& Ro) const {
        return (*this).daysSince0001_1_1() <= Ro.daysSince0001_1_1();
    }
    bool Date::operator<(const Date& Ro) const {
        return (*this).daysSince0001_1_1() < Ro.daysSince0001_1_1();
    }
    bool Date::operator>(const Date& Ro) const {
        return (*this).daysSince0001_1_1() > Ro.daysSince0001_1_1();
    }

    std::istream& Date::read(std::istream& istr = std::cin) {
        cin >> m_year;
        cin.ignore();
        cin >> m_mon;
        cin.ignore();
        cin >> m_day;
        if (cin.fail()) {
            m_ErrorCode = CIN_FAILED;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            validate();
        }
        return cin;
    }
    std::ostream& Date::write(std::ostream& os = std::cout)const {
        if (bad()) {
            cout << dateStatus();
        }
        else {
            cout << m_year;
            cout << '/';
            cout.fill('0');
            cout.width(2);
            cout << m_mon;
            cout << '/';
            cout.width(2);
            cout << m_day;
            cout.fill(' ');
        }
        return cout;
    }
}