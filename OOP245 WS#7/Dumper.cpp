/*
Name: Patel Ved Rajendrakumar
Email: vrpatel33@myseneca.ca
Student ID: 149409203
Date:10th november,2021
Section:OOP244 NAA
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{
	Dumper::Dumper(const char* plate_number, int built_year, double capacity, const char* current_address) : VehicleBasic(plate_number, built_year)
	{
		(*this).m_capacity_kg = capacity;
		(*this).m_cargo_kg = 0;
		(*this).NewAddress(current_address);
	}

	bool Dumper::loaddCargo(double cargo)
	{
		if ((*this).m_cargo_kg + cargo <= (*this).m_capacity_kg)
		{
			(*this).m_cargo_kg += cargo;
			return true;
		}
		else {
			return false;
		}
	}

	bool Dumper::unloadCargo()
	{
		if ((*this).m_cargo_kg > 0) {
			(*this).m_cargo_kg = 0;
			return true;
		}
		else {
			return false;
		}
	}

	std::istream& Dumper::read(std::istream& istr)
	{
		VehicleBasic::read(istr);
		cout << "Capacity: ";
		istr >> (*this).m_capacity_kg;
		cout << "Cargo: ";
		istr >> (*this).m_cargo_kg;
		return istr;
	}

	std::ostream& Dumper::write(std::ostream& ostr) const
	{
		VehicleBasic::write(ostr);
		ostr << " | ";
		ostr << (*this).m_cargo_kg << "/" << (*this).m_capacity_kg;
		return ostr;
	}

	istream& operator>>(istream& istr, Dumper& Ro)
	{
		return Ro.read(istr);
	}

	ostream& operator<<(ostream& ostr, const Dumper& Ro)
	{
		return Ro.write(ostr);
	}
}
