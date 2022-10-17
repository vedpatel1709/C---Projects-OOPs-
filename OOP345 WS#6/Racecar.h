/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
	class Racecar : public Car {
		double m_booster{ 0 };
   public:
		explicit Racecar(std::istream& in);
		void display(std::ostream& out) const override;
		double topSpeed() const;
	};
} 
#endif