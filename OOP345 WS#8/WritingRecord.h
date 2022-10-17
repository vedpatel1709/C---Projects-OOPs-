/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/20/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include "GeneratingList.h"
#include "EmpProfile.h"

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}


#endif // SDDS_WRITINGRECORD_H
