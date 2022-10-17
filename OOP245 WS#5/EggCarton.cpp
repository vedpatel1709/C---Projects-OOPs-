/* Name: Patel Ved Rajendrakumar
   Section: OOP244 NAA
   ID:149409203
   Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds {

    void EggCarton::setBroken()
    {
        m_size = -1;
        m_noOfEggs = -1;
    }

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
        if ((size % 6 == 0) && (size >= 6 && size <= 36) && (noOfEggs >= 0 && noOfEggs <= size))
        {
            m_size = size;
            m_noOfEggs = noOfEggs;
            m_jumbosize = jumboSize;

        }
        else
            setBroken();


    }
    ostream& EggCarton::display(std::ostream& ostr) const {
        if (*this)
        {
            int cartonWidth = m_size == 6 ? 3 : 6;
            for (int i = 0; i < m_size; i++) {
                cout << ((i < m_noOfEggs) ? (m_jumbosize ? 'O' : 'o') : '~');
                if ((i + 1) % cartonWidth == 0) cout << endl;
            }
        }
        else {
            ostr << "Broken Egg Carton!" << endl;
        }

        return ostr;
    }

    istream& EggCarton::read(std::istream& istr) {
        char type;
        istr >> type;
        if (type == 'j') {
            m_jumbosize = true;
        }
        else {
            m_jumbosize = false;
        }
        istr.ignore();
        istr >> m_size;
        istr.ignore();
        istr >> m_noOfEggs;

        int flag = 0;
        flag = (!((m_size % 6 == 0) && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size));
        if (flag)
            setBroken();
        return istr;
    }

    EggCarton:: operator bool() const {
        if (m_size > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    EggCarton::operator int() const {
        int val = -1;
        if (*this) {
            val = m_noOfEggs;
        }
        return val;
    }
    EggCarton::operator double() const {
        double val = -1.0;
        if (*this)
        {
            if (m_jumbosize) {
                val = (m_noOfEggs * JumboEggWieght) / 1000.0;
            }
            else {
                val = (m_noOfEggs * RegularEggWieght) / 1000.0;
            }
        }
        return val;
    }

    EggCarton& EggCarton::operator--() {
        if (*this && m_noOfEggs > 0) {
            m_noOfEggs--;
        }
        return *this;
    }
    EggCarton EggCarton:: operator--(int) {
        EggCarton temp = *this;
        operator--();
        return temp;
    }
    EggCarton& EggCarton::operator++() {
        if (*this) m_noOfEggs++;
        if (m_noOfEggs > m_size) {
            setBroken();
        }
        return *this;
    }
    EggCarton EggCarton::operator++(int) {
        EggCarton temp = *this;
        operator++();
        return temp;
    }

    EggCarton& EggCarton::operator=(int value) {
        m_noOfEggs = value;
        if (m_noOfEggs > m_size) {
            setBroken();
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(int value) {
        if (*this)m_noOfEggs += value;
        if (m_noOfEggs > m_size) {
            setBroken();
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(EggCarton& right) {
        if (*this)
        {
            m_noOfEggs += right.m_noOfEggs;
            if (m_noOfEggs > m_size)
            {
                right.m_noOfEggs = m_noOfEggs - m_size;
                m_noOfEggs = m_size;
            }
            else
                right.m_noOfEggs = 0;
        }
        return *this;
    }
    bool EggCarton::operator==(const EggCarton& right) const {
        bool index = false;
        double diff = double(*this) - double(right);
        if (diff > -0.001 && diff < 0.001)
            index = true;
            return index;
    }
    int operator+(int left, const EggCarton& right) {
        if (right) left += int(right);
        return left;

    }
   
    ostream& operator<<(ostream& ostr, const EggCarton& right) {
        return right.display(ostr);

    }
   
    istream& operator>>(istream& istr, EggCarton& right) {
        return right.read(istr);
    }
}
