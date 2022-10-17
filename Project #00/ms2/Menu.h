/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

/*
Name: Patel Ved Rajendrakumar
Date: 20th november, 2021
ID: 149409203
Email: vrpatel33@myseneca.ca
*/

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds
{
	class Menu; // create temp class so that we can use friend menu class 
	const int MAX_MENU_ITEMS = 20;

	class MenuItem
	{
		char* m_content;
		MenuItem();
		MenuItem(const char* content);
		void display() const;
		MenuItem(const MenuItem& M) = delete;
		MenuItem& operator=(const MenuItem& M) = delete;
		operator bool()const;
		operator const char* ()const;
		~MenuItem();
		friend class Menu;
	};


	class Menu
	{
		MenuItem m_title{};
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		int m_numOfItems{};
	public:
		Menu();
		Menu(const char* title);
		Menu(const Menu& M) = delete;
		Menu& operator=(const Menu& M) = delete;
		void display() const;
		void display_title(std::ostream& os) const;
		std::ostream& read(std::ostream& cout) const;
		int run() const;
		Menu& operator<<(const char* menuitemConent);

		int operator~() const;
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](int index) const;
		void setEmpty();
		bool isEmpty() const;
		~Menu();
	};
	std::ostream& operator<<(std::ostream& cout, const Menu& M);

}
#endif 