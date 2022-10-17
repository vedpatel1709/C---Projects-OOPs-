// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/21/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

#include "Station.h"
#include "Utilities.h"

namespace sdds {
   size_t Station::m_widthField = 0;
   size_t Station::id_generator = 0;

   Station::Station(const std::string& str) {
      Utilities util;
      IdOfTheStation = ++Station::id_generator;
      bool Index = true;
      size_t pos = 0u;
      const char* temp = " \t\n\r\f\v";
      try {
         NameOfTheItem = util.extractToken(str, pos, Index);
         NextSerielNo = stoi(util.extractToken(str, pos, Index));
         ItemInStock = stoi(util.extractToken(str, pos, Index));
         Station::m_widthField =
            std::max(util.getFieldWidth(), Station::m_widthField);
         DescOfTheStation = util.extractToken(str, pos, Index);
         DescOfTheStation.erase(0, DescOfTheStation.find_first_not_of(temp));
         DescOfTheStation.erase(DescOfTheStation.find_last_not_of(temp) + 1);
      }
      catch (std::string err) {
         std::cout << err;
      }
   }

   const std::string& Station::getItemName() const {
      return NameOfTheItem;
   }

   size_t Station::getNextSerialNumber() {
      return NextSerielNo++;
   }

   size_t Station::getQuantity() const {
      return ItemInStock;
   }

   void Station::updateQuantity() {
      if (ItemInStock > 0)
         ItemInStock--;
   }

   void Station::display(std::ostream& os, bool full) const {
      os << std::right << std::setw(3) << std::setfill('0') << IdOfTheStation;
      os << " | " << std::left << std::setw(Station::m_widthField);
      os << std::setfill(' ') << NameOfTheItem << " | " << std::right;
      os << std::setw(6) << std::setfill('0') << NextSerielNo << " | ";
      if (full) {
         os << std::setw(4) << std::setfill(' ') << std::right << ItemInStock << " | ";
         os << DescOfTheStation << std::endl;
      }
      else
         os << std::endl;
   }
}  // namespace sdds