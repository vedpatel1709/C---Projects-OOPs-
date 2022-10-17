// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/15/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {
   class Station {
      int IdOfTheStation{};
      std::string NameOfTheItem{};
      std::string DescOfTheStation{};
      size_t NextSerielNo{};
      size_t ItemInStock{};

      static size_t m_widthField;
      static size_t id_generator;

   public:
      Station(const std::string& str);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}  // namespace sdds
#endif  // !SDDS_STATION_H