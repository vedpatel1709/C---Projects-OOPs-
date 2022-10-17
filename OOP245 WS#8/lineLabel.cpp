/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include <iomanip>
#include "lineLabel.h"
using namespace std;
namespace sdds
{
	lineLabel::lineLabel()
	{
		m_length = 0;
	}

	lineLabel::lineLabel(const char* label, int length) :labelShape(label)
	{
		if (length > 0) {
			m_length = length;
		}
	}

	void lineLabel::readShape(std::istream& istr)
	{
		labelShape::readShape(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}
	void lineLabel::drawShape(std::ostream& ostr) const
	{
		if (m_length > 0 && label())
		{
			ostr << label() << endl;
			ostr << setw(m_length);
			ostr << setfill('=');
			ostr << '=';
			ostr << setfill(' ');
		}
	}


}