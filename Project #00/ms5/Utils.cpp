/* 
Citation and Sources...
Final Project Milestone 5
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
-----------------------------------------------------------



Name: Patel Ved Rajendrakumar
Id: 149409203
Section:NAA
Email:vrpatel33@myseneca.ca
*/

#include "Utils.h"
using namespace std;
namespace sdds
{
    int getInt()
    {
        int x;
        cin >> x;
        while (cin.fail() || cin.get() != '\n')
        {
            if (cin.fail())
                cout << "Invalid Selection, try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> x;
        }
        return x;
    }
    int getIntRange(int min, int max)
    {
        int x = getInt();
        while (x < min || x > max)
        {
            cout << "Invalid Selection, try again: ";
            x = getInt();
        }
        return x;
    }
}