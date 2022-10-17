/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

/*
Name: Patel Ved Rajendrakumar
Id: 149409203
Section:NAA
Email:vrpatel33@myseneca.ca
*/

// file takem from milestone 3
#define _CRT_SECURE_NO_WARNINGS
#include "Streamable.h"
namespace sdds
{
    std::istream& operator>>(std::istream& is, Streamable& Stream)
    {
        Stream.read(is);
        return is;
    }
    std::ostream& operator<<(std::ostream& os, const Streamable& Stream)
    {
        if (Stream)
        {
            Stream.write(os);
        }
        return os;
    }
}