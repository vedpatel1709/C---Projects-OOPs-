/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/20/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
   GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
      GeneratingList<EmployeeWage> activeEmp;
      // TODO: Add your code here to build a list of employees
      //         using raw pointers

      for (size_t i = 0; i < emp.size(); i++) {
         for (size_t j = 0; j < sal.size(); j++) {
            if (emp[i].id == sal[j].id) {
               EmployeeWage* eWage = new EmployeeWage(emp[i].name, sal[j].salary);
               try {
                  eWage->rangeValidator();
               }
               catch (...) {
                  delete eWage;
                  throw;
               }
               if (!activeEmp.sinValidity(emp[i].id)) throw std::string(" ");
               activeEmp += std::move(eWage);
               delete eWage;
            }
         }
      }
      return activeEmp;
   }

   GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
      GeneratingList<EmployeeWage> activeEmp;
      // TODO: Add your code here to build a list of employees
      //         using smart pointers

      for (size_t i = 0; i < emp.size(); i++) {
         for (size_t j = 0; j < sal.size(); j++) {
            if (emp[i].id == sal[j].id) {
               std::unique_ptr<EmployeeWage> eWage(new EmployeeWage(emp[i].name, sal[j].salary));
               eWage->rangeValidator();
               if (!activeEmp.sinValidity(emp[i].id)) {
                  throw std::string(" ");
               }
               activeEmp += std::move(eWage);
            }
         }
      }
      return activeEmp;
   }
}