/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef sdds_Utilities_H
#define sdds_Utilities_H

#include "Car.h"

#include<iostream>
#include<cstring>
#include<sstream>

#include "Racecar.h"
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
} 
#endif