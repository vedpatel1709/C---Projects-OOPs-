/* Name: Patel Ved Rajendrakumar
   Section: OOP244 NAA
   ID:149409203
   Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Bus.h"
using namespace std;
namespace sdds
{

    void Bus::NotInService()//c
    {
        m_numOfSeats = -1;
        m_numOfPassengers = -1;
    }

    Bus::Bus(int numSeats, int numPassengers)//c
    {
        if ((numSeats % 2 == 0) && (numSeats >= 10 && numSeats <= 40) && (numPassengers >= 0 && numPassengers <= numSeats))
        {
            m_numOfSeats = numSeats;
            m_numOfPassengers = numPassengers;
        }
        else
        {
            NotInService();
        }
    }

    void Bus::drawBus(ostream& ostr, int seats, int psng) const//c
    {
        int i, p;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " " << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " " << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-" << "O---'" << endl;
    }



   std::ostream& Bus::display(std::ostream& ostr) const//c
    {
        if (*this)
        {
            drawBus(ostr, m_numOfSeats, m_numOfPassengers);
            cout << "Total Fare Price: ";
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_numOfPassengers * priceOfBusTicket<<endl;
        }
        else
        {
            ostr << "Out of service!" << endl;
        }
        return ostr;
    }

    std::istream& Bus::read(std::istream& istr)//c
    {
        istr >> m_numOfSeats;
        istr.ignore();
        istr >> m_numOfPassengers;
        if (((m_numOfSeats % 2 == 0) && m_numOfSeats >= 10 && m_numOfSeats <= 40 && m_numOfPassengers >= 0 && m_numOfPassengers <= m_numOfSeats))
        {
            //m_numOfPassengers;
            //m_numOfSeats;
        }
        else {
            NotInService();
        }
        return istr;
    }


    Bus::operator bool() const//c
    {
        if (m_numOfSeats > 0) {
            return true;
        }
        else {
            return false;
        }
    }

    Bus::operator int() const//c
    {
        if (*this) {
            return m_numOfPassengers;
        }
        else {
            return -1;
        }
    }

    Bus::operator double() const//c
    {
        if (*this) {
            return m_numOfPassengers * priceOfBusTicket;
        }
        else {
            return -1.0;
        }
    }


    bool Bus::operator--()//c
    {
        if (*this && m_numOfPassengers > 0)
        {
            m_numOfPassengers--;
            return true;
        }
        else {
            return false;
        }
    }

    bool Bus::operator--(int)//c
    {
        return operator--();
    }

    bool Bus::operator++()//c
    {
        if (*this && m_numOfPassengers < m_numOfSeats)
        {
            m_numOfPassengers++;
            return true;
        }
        else {
            return false;
        }
    }

    bool Bus::operator++(int)//c
    {
        return operator++();
    }


    Bus& Bus::operator=(int value)//c
    {
        m_numOfPassengers = value;
        if (m_numOfPassengers > m_numOfSeats)
        {
            NotInService();
        }
        return *this;
    }

    Bus& Bus::operator+=(int value)//c
    {
        if (*this) {
            m_numOfPassengers += value;
        }
        if (m_numOfPassengers > m_numOfSeats) {
            NotInService();
        }
        return *this;
    }

    Bus& Bus::operator+=(Bus& right)
    {
        if (*this && right.m_numOfSeats > 0)
        {
            m_numOfPassengers += right.m_numOfPassengers;
            if (m_numOfPassengers > m_numOfSeats)
            {
                right.m_numOfPassengers = m_numOfPassengers - m_numOfSeats;
                m_numOfPassengers = m_numOfSeats;
            }
            else {
                right.m_numOfPassengers = 0;
            }
        }
        return *this;
    }


    bool Bus::operator==(const Bus& right) const
	{
		bool index = false;

		if (*this && (right) && int(right) == int(*this))
			index = true;
		return index;
	}


    int operator+(int left, const Bus& right)
    {
        if (right) {
            left += int(right);
        }
        return left;
    }

    std::ostream& operator<<(ostream& ostr, const Bus& right)
    {
        return right.display(ostr);
    }

    std::istream& operator>>(istream& istr, Bus& right)
    {
        return right.read(istr);
    }

}