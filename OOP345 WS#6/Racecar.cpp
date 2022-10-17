/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#include "Autoshop.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string t_boost; 
		getline(in, t_boost, '\n'); 
		m_booster = std::stod(t_boost); 
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);  	
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}
}