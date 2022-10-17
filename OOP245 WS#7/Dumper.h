/*
Name: Patel Ved Rajendrakumar
Email: vrpatel33@myseneca.ca
Student ID: 149409203
Date:10th november,2021
Section:OOP244 NAA
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper : public VehicleBasic
	{
		double m_capacity_kg; 
		double m_cargo_kg;  

	public:
		Dumper(const char* plate, int year, double capacity, const char* address);

		bool loaddCargo(double cargo);
		bool unloadCargo();

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& istr, Dumper& Ro);
	std::ostream& operator<<(std::ostream& ostr, const Dumper& Ro);
}
#endif
