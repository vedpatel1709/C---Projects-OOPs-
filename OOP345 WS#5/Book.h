/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/13/2022
module: Book.h
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>

namespace sdds {
	class Book {
		std::string m_author = "";
		std::string m_title = "";
		std::string m_country = "";
		size_t m_yearOfThePublication = 0u;
		double m_priceOfTheBook = 0.0f;
		std::string m_desc = "";

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& b);
		void trim(std::string& str) const;

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_desc);
		}
	};
}
#endif