/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <algorithm>
#include <cstring>
#include <string>

#include "Autoshop.h"
#include "Car.h"
#include "Utilities.h"

namespace sdds {

   Autoshop& Autoshop::operator += (Vehicle* vhcl) {
      m_vehicles.push_back(vhcl);
      return *this;
   }

   void Autoshop::display(std::ostream& os) {
      os << "--------------------------------\n";
      os << "| Cars in the autoshop!        |\n";
      os << "--------------------------------\n";

      std::vector < Vehicle* > ::iterator v;
      for (v = m_vehicles.begin(); v != m_vehicles.end(); v++) {
         (*v)->display(os);
         os << std::endl;
      }
      os << "--------------------------------\n";
   }

   Autoshop::~Autoshop() {
      std::vector < Vehicle* > ::iterator i;
      for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
         delete* i;
      }
   }
}