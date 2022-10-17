/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/13/2022
module: Book.cpp
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds {

	Book::Book() {

	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_yearOfThePublication;
	}
	double& Book::price() {
		return m_priceOfTheBook;
	}

	Book::Book(const std::string& strBook) {
		std::string tmp = strBook;
		//trim ws beginning and end
		auto trimWS = [=](std::string str) {
			str = str.substr(str.find_first_not_of(" \t\f\n\v\r"));
			str = str.substr(0, str.find_last_not_of(" \t\f\n\v\r") + 1);
			return str;
		};
		size_t i = tmp.find(',');
		m_author = trimWS(tmp.substr(0, i));
		tmp.erase(0, ++i);

		i = tmp.find(',');
		m_title = trimWS(tmp.substr(0, i));
		tmp.erase(0, ++i);

		i = tmp.find(',');
		m_country = trimWS(tmp.substr(0, i));
		tmp.erase(0, ++i);

		i = tmp.find(',');
		m_priceOfTheBook = stod(tmp.substr(0, i));
		tmp.erase(0, ++i);

		i = tmp.find(',');
		m_yearOfThePublication = stoi(tmp.substr(0, i));
		tmp.erase(0, ++i);

		m_desc = trimWS(tmp.substr(0));
	}

	std::ostream& operator<<(std::ostream& os, const Book& b) {
		os << std::setw(20) << std::right << b.m_author << " | "
			<< std::setw(22) << std::right << b.m_title << " | "
			<< std::setw(5) << std::right << b.m_country << " | "
			<< std::setw(4) << std::right << b.m_yearOfThePublication << " | "
			<< std::setw(6) << std::right << std::setiosflags(std::ios::fixed) 
			<< std::setprecision(2) << b.m_priceOfTheBook << " | "
			<< std::left << b.m_desc << std::endl;

		return os;
	}
}