/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/20/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
   template<typename T>
   class GeneratingList {

      std::vector<T> list;
   public:

      GeneratingList() {}
      GeneratingList(const char* f) {
         std::ifstream file(f);
         if (!file)
            throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

         while (file) {
            T t;
            if (t.load(file))
               list.push_back(T(t));
         }
      }

      size_t size() const { return list.size(); }
      const T& operator[](size_t i) const { return list[i]; }


      //TODO: Implement the Luhn Algorithm to check the
      //      valadity of SIN No's
      bool sinValidity(const std::string& sin) {
         int SinLength = sin.length();
         int SinSum = std::stoi(sin.substr(SinLength - 1, 1));
         int count = (SinLength - 2) % 2;

         for (int i = 0; i <= SinLength - 2; i++) {
            int Index = std::stoi(sin.substr(i, 1));
            if ((i % 2) == count)
               Index = Index * 2;
            if (Index > 9)
               Index -= 9;
            SinSum += Index;
         }

         return (SinSum % 10) == 0;
      }

      //TODO: Overload the += operator with a smart pointer
      // as a second operand.
      void operator+=(std::unique_ptr<T> rec) {
         list.push_back(*rec);
      }

      //TODO: Overload the += operator with a raw pointer
      // as a second operand.
      void operator+=(T* rec) {
         list.push_back(*rec);
      }

      void print(std::ostream& os) const {
         os << std::fixed << std::setprecision(2);
         for (auto& e : list)
            e.print(os);
      }
   };

   template<typename T>
   std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
      rd.print(os);
      return os;
   }
}
#endif  // !SDDS_GENERATINGLIST_H

