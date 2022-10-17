/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <cstring>
#include "labelShape.h"
using namespace std;

namespace sdds
{
	const char* labelShape::label() const
	{
		return m_label;
	}

	labelShape::labelShape(const char* label)
	{
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}

	labelShape::~labelShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void labelShape::readShape(std::istream& istr)
	{
		string label;
		getline(istr, label, ',');
		delete[] m_label;
		m_label = new char[strlen(label.c_str()) + 1];
		strcpy(m_label, label.c_str());
	}
}