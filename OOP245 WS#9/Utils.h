/***********************************************************************
// OOP244 Workshop 9:
// File	Utils.h
// Version 1.0
// Date	2021/11/19
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
* Name: Patel Ved Rajendrakumar
* Date: 25th november, 2021
* SEction: NAA
* ID: 149409203
* Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
#include <fstream>
namespace sdds {
	int strLen(const char* str);
	void strCpy(char* des, const char* src);
	void strCat(char* des, const char* src);
	void delAlloCopy(char*& des, const char* src);
	char* dynRead(std::istream& istr, char delimeter = '\n');
}
#endif // !