/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "labelShape.h"
namespace sdds
{
	class rectangleLabel : public labelShape
	{
		int m_width;
		int m_spaces;
	public:
		rectangleLabel();
		rectangleLabel(const char* label, int width, int spaces);
		void readShape(std::istream& istr);
		void drawShape(std::ostream& ostr) const;
	};

}
#endif
