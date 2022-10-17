/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NDD
Workshop 6 part 1
Date: 10th october,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sdds
{
    bool Contact::validPhone(int areaCode, int exchangeCode, int num)const
    {
        if (areaCode >= 100 && areaCode <= 999 && exchangeCode >= 100 && exchangeCode <= 999 && num >= 0 && num <= 9999) {
            return true;
        }
        else {
            return false;
        }
    }


    void Contact::setEmpty()
    {
        m_name = nullptr;
    }

    void Contact::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    void Contact::extractChar(std::istream& istr, char ch)const
    {
        if (istr.peek() != ch)
            istr.setstate(ios::failbit);
        else
            istr.get();
    }

    std::ostream& Contact::printPhoneNumber(std::ostream& ostr)const
    {
        ostr << "(" << m_area << ") " << m_exchangeCode << "-";
        ostr.width(4);
        ostr.fill('0');
        ostr.setf(ios::right);
        ostr << m_number;
        ostr.unsetf(ios::right);
        ostr.fill(' ');
        return ostr;
    }

    void Contact::set(const char* name, int areaCode, int exchangeCode, int number)
    {
        if (name && name[0] && validPhone(areaCode, exchangeCode, number))
        {
            allocateAndCopy(name);
            m_area = areaCode;
            m_exchangeCode = exchangeCode;
            m_number = number;
        }
        else
        {
            delete[] m_name;
            setEmpty();
        }
    }

    Contact::Contact(const char* name, int areaCode, int excahngeCode, int number)
    {
        set(name, areaCode, excahngeCode, number);
    }

    Contact::Contact(const Contact& cnt)
    {
        if (cnt) {
            set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
        }
    }

    Contact& Contact::operator=(const Contact& cnt)
    {
        if (this != &cnt) {
            set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
        }
        return *this;
    }

    Contact::~Contact()
    {
        delete[] m_name;
    }

    Contact::operator bool() const
    {
        return m_name != nullptr;
    }

    std::ostream& Contact::print(std::ostream& ostr, bool toFile) const
    {
        if (*this)
        {
            if (toFile)
            {
                ostr << m_name << ',';
                printPhoneNumber(ostr);
            }
            else
            {
                ostr.width(50);
                ostr.setf(ios::left);
                ostr.fill('.');
                ostr << m_name;
                ostr.unsetf(ios::left);

                printPhoneNumber(ostr);
            }
        }
        return ostr;
    }

    std::istream& Contact::read(std::istream& istr)
    {
        char name[MaxNameLength];
        int A = -1, B = -1, C = -1;
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        extractChar(istr, '(');
        istr >> A;
        extractChar(istr, ')');
        extractChar(istr, ' ');
        istr >> B;
        extractChar(istr, '-');
        istr >> C;
        extractChar(istr, '\n');
        if (istr.fail()) {
        }
        else {
            set(name, A, B, C);
        }
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Contact& cnt)
    {
        if (cnt) {
            cnt.print(ostr, false);
        }
        else {
            ostr << "Invalid Phone Record";
        }
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Contact& cnt)
    {
        return cnt.read(istr);
    }
}