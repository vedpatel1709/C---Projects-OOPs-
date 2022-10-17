/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/07/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CONFIRM_ORDER_H
#define SDDS_CONFIRM_ORDER_H

#include <iostream>

#include "Toy.h"

using namespace std;
namespace sdds {
    class ConfirmOrder {
    private:
        const Toy** m_Toy = nullptr;
        size_t m_ToyNumber = 0;
    public:
        ConfirmOrder() {};
        ~ConfirmOrder();
        ConfirmOrder& operator = (const ConfirmOrder& Order);
        ConfirmOrder(const ConfirmOrder& Order);
        ConfirmOrder& operator = (ConfirmOrder&& Order);
        ConfirmOrder(ConfirmOrder&& Order);
        ConfirmOrder& operator += (const Toy& Toy);
        ConfirmOrder& operator -= (const Toy& Toy);
        friend ostream& operator << (ostream& ostr,
            const ConfirmOrder& Order);
    };
}
#endif // !SDDS_CONFIRM_ORDER_H