/***********************************************************************
// OOP244 Workshop 9:
// File	Person.h
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

#ifndef SDDS_PERSON_H
#define SDDS_PERSON_H

#include <iostream>
namespace sdds {
    class Person {
        char* m_name{};
        char* m_middleName{};
        char* m_lastName{};
    public:
        Person();
        Person(const Person& copyFrom);
        Person& operator=(const Person& RightOperand);
        virtual ~Person();
        virtual std::istream& read(std::istream& istr);
        virtual std::ostream& write(std::ostream& ostr)const;
        // returns true if the name is valid; 
        // a valid name has a first and a last name
        // and they are not empty
        virtual operator bool()const;
        // deallocates the dynamic memory
        virtual void operator~();
    };
    std::istream& operator>>(std::istream& leftOperand, Person& rightOperand);
    std::ostream& operator<<(std::ostream& leftOperand, const Person& rightOperand);
}

#endif
