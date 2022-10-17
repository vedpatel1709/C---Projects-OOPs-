/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/07/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iomanip>
#include <iostream>
#include <string>
#include "Toy.h"

using namespace std;
namespace sdds {
    void sdds::Toy::update(int numItems) {
        m_NoOfItems = numItems;
    }

    Toy::Toy(const string& toy) {
        string StringToy = toy; // creating temp string StringToy which will be assigned to parameter
        string t_IdOfTheToy, t_NameOfToy, t_NoOfItems, t_PriceOfTheToy;
        t_IdOfTheToy = StringToy.substr(0, StringToy.find(":"));
        StringToy.erase(0, StringToy.find(":") + 1);
        t_NameOfToy = StringToy.substr(0, StringToy.find(":"));
        StringToy.erase(0, StringToy.find(":") + 1);
        t_NoOfItems = StringToy.substr(0, StringToy.find(":"));
        StringToy.erase(0, StringToy.find(":") + 1);
        t_PriceOfTheToy = StringToy.substr(0, StringToy.find(":"));
        StringToy.erase(0, StringToy.find(":") + 1);
        t_NameOfToy.erase(0, t_NameOfToy.find_first_not_of(' '));
        t_NameOfToy.erase(t_NameOfToy.find_last_not_of(' ') + 1);
        m_IdOfTheToy = stoi(t_IdOfTheToy);
        m_NameOfToy = t_NameOfToy;
        m_NoOfItems = stoi(t_NoOfItems);
        m_PriceOfTheToy = stod(t_PriceOfTheToy);
    }


    ostream& operator << (ostream& ostr, const Toy& ty) {
        double TotalWithOutTax = ty.m_PriceOfTheToy * double(ty.m_NoOfItems);
        double Tax = TotalWithOutTax * ty.m_SalesTax;

        ostr << "Toy";
        ostr << setw(8) << ty.m_IdOfTheToy << ":";
        ostr << right << setw(18) << ty.m_NameOfToy;
        ostr << setw(3) << ty.m_NoOfItems;
        ostr << " items" << setw(8) << fixed << setprecision(2) << ty.m_PriceOfTheToy;
        ostr << "/item  subtotal:" << setw(7) << fixed << setprecision(2) << TotalWithOutTax;
        ostr << " tax:" << setw(6) << fixed << setprecision(2) << Tax;
        ostr << " total:" << setw(7) << fixed << setprecision(2) << (TotalWithOutTax + Tax) << endl;
        return ostr;
    }
}