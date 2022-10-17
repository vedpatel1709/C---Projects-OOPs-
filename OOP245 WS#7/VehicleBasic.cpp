/*
Name: Patel Ved Rajendrakumar
Email: vrpatel33@myseneca.ca
Student ID: 149409203
Date:10th november,2021
Section:OOP244 NAA
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{
	VehicleBasic::VehicleBasic(const char* plate_number, int built_year)
	{
		(*this).m_built_year = built_year;
		strcpy((*this).m_currentAddress, "Factory");
		strcpy((*this).m_licensePlate, plate_number);
	}

	void VehicleBasic::NewAddress(const char* address)
	{
		cout << "|" << right << setw(8) << (*this).m_licensePlate;
		cout << "| |";
		cout << setw(20) << right << (*this).m_currentAddress;
		cout << " ---> ";
		cout << setw(20) << left << address;
		cout << "|\n";
		strcpy((*this).m_currentAddress, address);
	}

	ostream& VehicleBasic::write(ostream& ostr) const
	{
		ostr << "| ";
		ostr << (*this).m_built_year;
		ostr << " | ";
		ostr << (*this).m_licensePlate;
		ostr << " | ";
		ostr << (*this).m_currentAddress;
		return ostr;
	}

	istream& VehicleBasic::read(istream& istr)
	{
		cout << "Built year: ";
		istr >> (*this).m_built_year;
		cout << "License plate: ";
		istr >> (*this).m_licensePlate;
		cout << "Current location: ";
		istr >> (*this).m_currentAddress;
		return istr;
	}

	ostream& operator<<(ostream& ostr, const VehicleBasic& Ro)
	{
		return Ro.write(ostr);
	}

	istream& operator>>(istream& istr, VehicleBasic& Ro)
	{
		return Ro.read(istr);
	}
}

