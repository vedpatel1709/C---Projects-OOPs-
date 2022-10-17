/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/07/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>
#include <utility>
#include <cstring>
#include <iomanip>
#include <iostream>

#include <string>

using namespace std;
namespace sdds {
   class Toy {
      unsigned int m_IdOfTheToy;
      string m_NameOfToy;
      int m_NoOfItems;
      double m_PriceOfTheToy;
      double m_SalesTax = 0.13;
   public:
      Toy() {};
      void update(int numItems);
      Toy(const std::string& toy);
      friend ostream& operator << (ostream& ostr,
         const Toy& Toy);
   };
}
#endif // !SDDS_TOY_H