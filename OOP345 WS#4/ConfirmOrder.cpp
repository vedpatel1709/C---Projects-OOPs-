/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/07/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <string>

#include "ConfirmOrder.h"
using namespace std;
namespace sdds {

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& Order) {
		*this = Order;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& Order) {
		if (this != &Order) {
			m_ToyNumber = Order.m_ToyNumber;
			delete[] m_Toy;
			m_Toy = new const Toy * [m_ToyNumber];
			for (size_t i = 0; i < m_ToyNumber; i++) {
				m_Toy[i] = Order.m_Toy[i];
			}
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& Order){
		if (this != &Order) {
			m_ToyNumber = Order.m_ToyNumber;
			delete[] m_Toy;
			m_Toy = Order.m_Toy;
			Order.m_Toy = nullptr;
			Order.m_ToyNumber = 0;
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& Toy)
	{
		bool Index = false;
		for (size_t i = 0; i < m_ToyNumber; i++) {
			if (m_Toy[i] == &Toy) {
				Index = true;
			}
		}
		if (Index) {
			for (size_t i = 0; i < m_ToyNumber; i++) {
				if (m_Toy[i] == &Toy) {
					m_Toy[i] = nullptr;
				}
			}
			m_ToyNumber--;
		}
		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& Order){
		*this = move(Order);
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& T) {
		bool Index = false;
		for (size_t i = 0; i < m_ToyNumber; i++) {
			if (m_Toy[i] == &T) {
				Index = true;
			}
		}
		if (!Index) {
			const Toy** temp = nullptr;
			temp = new const Toy * [m_ToyNumber + 1];
			for (size_t i = 0; i < m_ToyNumber; i++) {
				temp[i] = m_Toy[i];
			}
			temp[m_ToyNumber] = &T;
			m_ToyNumber++;

			delete[] m_Toy;
			m_Toy = temp;
		}
		return *this;
	}

	ostream& operator<<(ostream& ostr, const ConfirmOrder& Order) {
		ostr << "--------------------------" << endl;
		ostr << "Confirmations to Send" << endl;
		ostr << "--------------------------" << endl;
		if (Order.m_ToyNumber == 0) {
			ostr << "There are no confirmations to send!\n";
		}
		else {
			for (size_t i = 0; i < Order.m_ToyNumber; i++) {
				if (Order.m_Toy[i] != nullptr) {
					ostr << *Order.m_Toy[i];
				}
			}
		}
		ostr << "--------------------------\n";
		return ostr;
	}

	ConfirmOrder::~ConfirmOrder() {
		delete[] m_Toy;
		m_Toy = nullptr;
	}
}