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
#include"Country.h"
using namespace std;
namespace sdds {
	
	Country::Country() {
		setEmpty();
	}
	Country::Country(const char* name, int noOfCity, const City* cities) {
		setEmpty();
		if (name != nullptr && strlen(name) !=0 && noOfCity > 0 && noOfCity <= MAX_CITY) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_noOfCity = noOfCity;
			m_city = new City[noOfCity];
			for (int i = 0; i < noOfCity; i++) {
				m_city[i] = cities[i];
			}
		}
	}
	void Country::setName(const char* name) {
		delete[] m_name;
		if (name != nullptr && strlen(name) !=0) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else {
			delete[] m_city;
			setEmpty();
		}

	}
	Country& Country::addCity(const City& c) {
		if (!c.isEmpty()) {
			City* temp = new City[m_noOfCity + 1];
			for (int i = 0; i < m_noOfCity; i++)
				temp[i] = m_city[i];

			delete[] m_city;
			temp[m_noOfCity] = c;
			m_noOfCity++;
			m_city = temp;
		}
		return *this;
	}
	void Country::setEmpty() {
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}
	Country& Country::migrate(int people) {
		for (int i = 0; i < m_noOfCity; i++) {
			if (m_city[i].getPeople() < POPULATION) {
				m_city[i].addPopulation(people);
			}
		}
		return *this;
	}
	bool Country::isEmpty()const {
		if (m_name == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	Country::~Country() {
		delete[] m_name;
		delete[] m_city;
	}
	void Country::display()const {
		if (!isEmpty()) {
			cout << "Country Name: " << m_name << endl;
			cout << "No of city: " << m_noOfCity << endl;
			cout <<setw(32) << fixed << left << setfill(' ') << "City name";
			cout<< "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++)
				m_city[i].display();
		}
		else
			cout << "Invalid country object" << endl;
	}
}
