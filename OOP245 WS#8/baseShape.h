/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds
{
	class baseShape
	{
	public:
		virtual void drawShape(std::ostream& os) const = 0;
		virtual void readShape(std::istream& is) = 0;
		virtual ~baseShape() {};

	};
	std::ostream& operator<<(std::ostream& os, const baseShape& shape);
	std::istream& operator>>(std::istream& is, baseShape& shape);
}
#endif

