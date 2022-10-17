/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/07/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <iostream>
#include <string>
#include "Toy.h"
using namespace std;
namespace sdds {
	class Child
	{
	private:
		Toy* toy{};
		size_t m_Count;
		string m_ChildName;
		int m_ChildAge;
	public:
		Child();
		void SetEmpty();
		Child& operator=(const Child& Child);
		Child(Child&& Child);
		Child& operator=(Child&& Child);
		Child(const Child& Child);
		size_t size() const;
		Child(string name, int childAge, const Toy* toys[], size_t count);
		~Child();
		friend ostream& operator<<(ostream& ostr, const Child& Child);
	};
}
#endif // !SDDS_CHILD_H
