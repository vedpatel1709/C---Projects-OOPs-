/* Name: Patel Ved Rajendrakumar
   Section: OOP244 NAA
   ID:149409203
   Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
using namespace std;

namespace sdds {
    const double priceOfBusTicket = 125.34;

    class Bus {

        int m_numOfSeats;
        int m_numOfPassengers;
        void NotInService();
        void drawBus(ostream& ostr, int seats, int psng) const;

    public:
        Bus(int numSeats = 20, int numPassengers = 0);

        std::ostream& display(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);

        operator bool() const;
        operator int() const;
        operator double() const;

        bool operator--();
        bool operator--(int);
        bool operator++();
        bool operator++(int);

        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);

        bool operator==(const Bus& right) const;

    };

    int operator+(int left, const Bus& right);
    std::ostream& operator<<(ostream& ostr, const Bus& right);
    std::istream& operator>>(istream& istr, Bus& right);


}
#endif