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

#include "Utilities.h"


using namespace std;

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* ptr = nullptr;			
		std::string temp;
		getline(in, temp);
		temp.erase(0, temp.find_first_not_of(' '));
		std::stringstream line(temp);

		if (!temp.empty()) {
			if (toupper(temp[0]) == 'C') {
				ptr = new Car(line);
			}
			else if (toupper(temp[0]) == 'R') {
				ptr = new Racecar(line);
			}
			else {
				std::string tag{};
				getline(line, tag, ',');
				throw "Unrecognized record type: [" + tag + "]";
			}
		}
		else {
			ptr = nullptr;
		}
		return ptr;
	}
} 