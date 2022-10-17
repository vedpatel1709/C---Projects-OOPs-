/*
Name: Patel Ved Rajendrakumar
Email: vrpatel33@myseneca.ca
Student ID: 149409203
Date:10th november,2021
Section:OOP244 NAA
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	class VehicleBasic
	{
		char m_licensePlate[10];
		char m_currentAddress[22];
		int m_built_year; 

	public:
		VehicleBasic(const char* plate_number, int built_year);
		void NewAddress(const char* address);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& istr, VehicleBasic& Ro);
	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& Ro);
}

#endif