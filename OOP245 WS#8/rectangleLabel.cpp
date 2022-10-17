/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip>
#include <cstring>
#include "rectangleLabel.h"
using namespace std;
namespace sdds
{
	rectangleLabel::rectangleLabel()
	{
		m_width = 0;
		m_spaces = 0;
	}


	rectangleLabel::rectangleLabel(const char* label, int width, int spaces) :labelShape(label)
	{
		m_width = width;
		m_spaces = spaces;
		int value = strlen(label) + spaces + 2;
		if (width < value)
		{
			m_width = 0;
		}
	}

	void rectangleLabel::drawShape(std::ostream& os) const
	{
		if (m_width > 0 && m_spaces > 0)
		{
			os << setfill('+') << '+';
			os << setw(m_width - 2) << setfill('-') << '-' << setfill(' ') << setfill('+') << '+' << endl;
			os << setfill('|') << '|';
			os << setw(m_spaces) << setfill(' ') << ' ' << setw(m_width - m_spaces - 2);
			os.setf(ios::left);
			os << label() << '|' << endl;
			os << setfill('+') << '+';
			os << setw(m_width - 2) << setfill('-') << '-';
			os << setfill('+') << '+';

		}
	}
	void rectangleLabel::readShape(std::istream& is)
	{
		labelShape::readShape(is);
		is >> m_width;
		is.ignore();
		is >> m_spaces;
		is.ignore(1000, '\n');
	}

}