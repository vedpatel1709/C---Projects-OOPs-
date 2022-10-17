/*
* Name: Patel Ved Rajendrakumar
* Date: 25th november, 2021
* SEction: NAA
* ID: 149409203
* Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include<iostream>
#include "Person.h"
namespace sdds
{
	class Contact : public Person
	{
		char* m_address{};
		char* m_city{};
		char m_province[3];
		char m_postalCode[7];

	public:
		Contact() {};
		Contact(const Contact& copyFrom);

		Contact& operator=(const Contact& RightOperand);

		virtual ~Contact();
		virtual std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;

		virtual operator bool()const;
		virtual void operator~();
	};
}
#endif