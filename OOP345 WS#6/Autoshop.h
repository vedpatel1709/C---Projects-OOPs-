/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS_

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>

#include <cstring>
#include <vector>
#include <list>

#include "Vehicle.h"
using namespace std;

namespace sdds {
   class Autoshop {
      std::vector < Vehicle* > m_vehicles;
   public:
      Autoshop& operator += (Vehicle* vhcl);
      void display(std::ostream& out);
      ~Autoshop();

      template < typename T >
      void select(T test, std::list <const Vehicle* >& vhcl) {
         std::vector < Vehicle* > ::iterator i;
         for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            if (test(*i)) {
               vhcl.push_back(*i);
            }
         }
      }
   };
}

#endif