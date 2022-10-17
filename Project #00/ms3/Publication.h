/* Citation and Sources...
Final Project Milestone 3
Module: Publication
Filename: Publication.h
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include"Date.h"
#include"Lib.h"
#include"Streamable.h"

namespace sdds {
	class Publication : Streamable {
		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int m_membership = 0;
		int m_libRef = -1;
		Date m_date;

		void extractChar(std::istream& istr, char ch)const;
		void set(const char* title, const char* shelfId, int membership, int libRef, Date date);
	public:

		Publication();

		// Modifiers
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the *libRef* attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 

		// Override
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;

		// RULE OF THREE : Copy Constructor, User Defined Copy Assignment Operator, Destructor
		Publication(const Publication& cnt);
		Publication& operator=(const Publication& cnt);
		~Publication();
	};

	std::ostream& operator<<(std::ostream& os, const Publication& obj);
	std::istream& operator>>(std::istream& is, Publication& obj);
}

#endif