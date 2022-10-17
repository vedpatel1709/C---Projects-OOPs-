/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_LINE_LABEL_H
#define SDDS_LINE_LABEL_H
#include <iostream>
#include "labelShape.h"
namespace sdds
{
	class lineLabel : public labelShape
	{
		int m_length;
	public:
		lineLabel();
		lineLabel(const char* label, int length);
		void drawShape(std::ostream& ostr) const;
		void readShape(std::istream& istr);
	};

};
#endif

