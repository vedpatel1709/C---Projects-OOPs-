/*
* Name: Patel Ved Rajendrakumar
* Date: 25th november, 2021
* SEction: NAA
* ID: 149409203
* Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _DEFINE_SECURE_NO_WARNINGS
#include<iostream>
#include"Contact.h"
#include "Utils.h"
using namespace std;

namespace sdds
{

	Contact::Contact(const Contact& copyFrom) :Person(copyFrom)
	{
		delAlloCopy(m_address, copyFrom.m_address);
		delAlloCopy(m_city, copyFrom.m_city);

		strCpy(m_province, copyFrom.m_province);
		strCpy(m_postalCode, copyFrom.m_postalCode);

	}

	Contact& Contact::operator=(const Contact& RightOperand)
	{
		Person::operator=(RightOperand);

		delAlloCopy(m_address, RightOperand.m_address);
		delAlloCopy(m_city, RightOperand.m_city);

		strCpy(m_province, RightOperand.m_province);
		strCpy(m_postalCode, RightOperand.m_postalCode);

		return *this;

	}

	void Contact::operator~()
	{
		Person::operator~();
		delete[] m_address;
		m_address = nullptr;

		delete[] m_city;
		m_city = nullptr;
	}

	std::istream& Contact::read(std::istream& istr)
	{
		~*this;
		Person::read(istr);

		m_address = dynRead(istr, ',');
		m_city = dynRead(istr, ',');

		istr.getline(m_province, 3, ',');
		istr.getline(m_postalCode, 7, '\n');

		if (istr.fail()) {
			~*this;
		}

		return istr;
	}

	std::ostream& Contact::write(std::ostream& ostr)const
	{
		if (*this)
		{
			Person::write(ostr);
			ostr << endl << m_address << endl;
			ostr << m_city << " " << m_province << endl;

			int i;
			for (i = 0; i < 3; i++)
			{
				ostr << m_postalCode[i];
			}

			ostr << " ";

			for (i = 3; i < 6; i++)
			{
				ostr << m_postalCode[i];
			}

			ostr << endl;

		}
		return ostr;
	}

	Contact::operator bool()const
	{
		return Person::operator bool() && m_address && m_address[0] && m_city && m_city[0];
	}

	Contact:: ~Contact()
	{
		~*this;
	}
}