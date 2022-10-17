/*
 Name: Patel Ved Rajendrakumar
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 30th may,2022
 Id: 149409203
 */

 /*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include<iostream>
#include<string>
#include<utility>
#include<string>

#include "Pair.h"

using namespace std;
namespace sdds {

    bool Pair::Same(const Pair& left, const Pair& right) {
        return left.m_key == right.m_key;
    }
        
    Pair::Pair() : m_key{ "" }, m_value{ "" }{};

    ostream& Pair::display(ostream& os) const {
        os.width(20);
        os.setf(ios::right);
        os << getKey();
        os.setf(ios::left);
        os << ": " << getValue();
        return os;
    } 

    bool Pair::operator==(const Pair& pair)const{
        return m_key == pair.getKey();
    }

    ostream& operator<<(ostream& ostr, const Pair& pair) {
        return pair.display(ostr);
    }
}