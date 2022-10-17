/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/12/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COVID_COLLECTION_H
#define SDDS_COVID_COLLECTION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

namespace sdds {
	struct Covid {
		std::string country{};
		std::string city{};
		std::string variant{};
		std::string year{};
		size_t noOfCases{};
		size_t m_deaths{};
	};
	class CovidCollection {
		std::vector<Covid> covid;
		std::string& strTrim(std::string& token);
	public:
		CovidCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(std::string str);
		void cleanList();
		bool inCollection(std::string str) const;
		std::list<Covid>getListForCountry(std::string str) const;
		std::list<Covid>getListForVariant(std::string str) const;
		~CovidCollection();
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVID_COLLECTION_H

