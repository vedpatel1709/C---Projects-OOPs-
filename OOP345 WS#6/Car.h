/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>

#include "Vehicle.h"
#include "Autoshop.h"

using namespace std;
namespace sdds {
	class Car : public Vehicle {
		std::string maker{};
		char cnd{};
		double TopSpeed{};
public:
		Car() = default;
		explicit Car(std::istream& in); 
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		~Car() override = default;
	};
} 
#endif