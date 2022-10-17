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
#include "baseShape.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const baseShape& shape)
	{
		shape.drawShape(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, baseShape& shape)
	{
		shape.readShape(istr);
		return istr;
	}
}