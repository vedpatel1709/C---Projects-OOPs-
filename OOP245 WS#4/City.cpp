/*
* Name: Patel Ved Rajendrakumar
* Section: OOP244 NAA
* Email:vrpatel33@myseneca.ca
* student ID: 149409203
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include"City.h"

using namespace std;
namespace sdds {
	City::City(){
		setEmpty();
	}

	City::City(const char* name, int population) {
		setEmpty();
		if (name != nullptr && strlen(name) > 0 && population >= 0) {
			strcpy(m_cityName, name);
			m_population = population;
		}
	}
	void City::setEmpty() {
		m_cityName[0] = '\0';
		m_population = -1;
	}
	void City::setCityName(const char* name) {
		if (name != nullptr) {
			strcpy(m_cityName, name);
		}
		else {
			m_cityName[0]='\0';
		}
	}
	void City::setPopulation(int population) {
		if ( population >= 0 && population < POPULATION) {
			m_population = population;
		}
		else {
			m_population = -1;
		}
	}
	void City::addPopulation(int population) {
		m_population+= population ;
		if (m_population > POPULATION) {
			m_population = POPULATION;
		}
		else {
		}
	}
	bool City::isEmpty() const {
		if ((strlen(m_cityName) == 0) || (m_population < 0)) {
			return true;
		}
		else {
			return false;
		}
	}

	int City::getPeople() const {
		return m_population;
	}
	void City::display()const {
		if (!isEmpty()) {
			cout << "|";
			cout.width(30);
			cout.unsetf(ios::right);
			//cout.fill(' ');
			//cout.setf(ios::fixed);
			cout.setf(ios::left);
			cout << m_cityName;
			cout << " | ";
			cout.width(10);
			//cout.fill(' ');
			//cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout << m_population;
			cout.unsetf(ios::right);
			cout << " | " << endl;
		}
		else {
			cout << "invalid city" << endl;
		}
	}

	/*void City::display() const {

		if (!isEmpty())
			cout << "|" << left << setw(30) << m_cityName << " | " << right << setw(10) << m_population << " | " << endl;
		else
			cout << "invalid city" << endl;
	}*/


}