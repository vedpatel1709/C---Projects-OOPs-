/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/12/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <iomanip>

#include "CovidCollection.h"

namespace sdds {

	CovidCollection::CovidCollection(std::string file_name) {

		std::ifstream file(file_name);
		if (!file)
		{
			throw "Invalid file_name!";
		}

		while (file) {

			Covid Cvd;
			std::string str;
			std::getline(file, str);

			if (file) {
				strTrim(Cvd.country = str.substr(0, 25));
				strTrim(Cvd.city = str.substr(25, 25));
				strTrim(Cvd.variant = str.substr(50, 25));
				try {
					Cvd.year = std::stoi(str.substr(75, 5)) < 0 ? " " : str.substr(75, 5);
				}catch (...) {
					Cvd.year = '0';
				}

				Cvd.noOfCases = std::stoi(str.substr(80, 5));
				Cvd.m_deaths = std::stoi(str.substr(85));
				this->covid.push_back(Cvd);
			}
		}
		file.close();
	};


	void CovidCollection::display(std::ostream& out) const {

		std::for_each(covid.begin(), covid.end(), [&out](const Covid& covid) {
			out << covid << std::endl;
			});

		auto totalCases = std::accumulate(covid.begin(), covid.end(), 0u, [](const size_t& length, const Covid& theCovid) {
			return length + theCovid.noOfCases;
			});

		auto totalDeaths = std::accumulate(covid.begin(), covid.end(), 0u, [](const size_t& length, const Covid& theCovid) {
			return length + theCovid.m_deaths;
			});

		for (int i = 0; i < 88; i++)
			out << "-";
		out << std::endl;

		out << "|" << std::right << std::fixed << std::setw(79) << "Total Cases Around the World: " << std::right << std::setw(6) << totalCases << " |" << std::endl;;
		out << "|" << std::right << std::fixed << std::setw(79) << "Total Deaths Around the World: " << std::right << std::setw(6) << totalDeaths << " |" << std::endl;;
	}

	void CovidCollection::sort(std::string str) {
		if (str == "country") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.country < c2.country;
				});
		}
		else if (str == "variant") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.variant < c2.variant;
				});
		}
		else if (str == "cases") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.noOfCases < c2.noOfCases;
				});
		}
		else if (str == "deaths") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.m_deaths < c2.m_deaths;
				});
		}
	}

	void CovidCollection::cleanList() {

		std::transform(covid.begin(), covid.end(), covid.begin(), [](Covid TheCovid) {
			if (TheCovid.variant == "[None]") {
				TheCovid.variant = "";
			}
			return TheCovid;
			});
	}

	std::string& CovidCollection::strTrim(std::string& str) {
		while (str.length() > 0 && str[0] == ' ') {
			str.erase(0, 1);
		}
		while (str.length() > 0 && str[str.length() - 1] == ' ') {
			str.erase(str.length() - 1, 1);
		}
		return str;
	}

	bool CovidCollection::inCollection(std::string str) const {
		auto valid = std::find_if(covid.begin(), covid.end(), [&str](const Covid& TheCovid) {
			return TheCovid.variant == str;
			});
		return valid != covid.end();
	}

	std::list<Covid> CovidCollection::getListForCountry(std::string str) const {
		auto count = std::count_if(covid.begin(), covid.end(), [&str](const Covid& TheCovid) {
			return TheCovid.country == str;
			});

		std::list<Covid>listed(count);
		std::copy_if(covid.begin(), covid.end(), listed.begin(), [&str](const Covid& TheCovid) {
			return TheCovid.country == str;
			});

		return listed;

	}

	std::list<Covid> CovidCollection::getListForVariant(std::string str) const {
		auto count = count_if(covid.begin(), covid.end(), [&str](const Covid& TheCovid) {
			return TheCovid.variant == str;
			});

		std::list<Covid>listed(count);
		std::copy_if(covid.begin(), covid.end(), listed.begin(), [&str](const Covid& TheCovid) {
			return TheCovid.variant == str;
			});

		return listed;
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| " << std::left << std::setw(21) << theCovid.country;
		out << " | " << std::left << std::setw(15) << theCovid.city;
		out << " | " << std::left << std::setw(20) << theCovid.variant;
		out << " | " << std::right << std::setw(7) << theCovid.year;
		out << "| " << std::right << std::setw(4) << theCovid.noOfCases;
		out << " | " << std::right << std::setw(3) << theCovid.m_deaths << " |";

		return out;
	}
	CovidCollection::~CovidCollection() {
	}
}
