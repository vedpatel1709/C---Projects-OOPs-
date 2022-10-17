// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/15/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>

#include "Utilities.h"

namespace sdds {
   char Utilities::m_delimiter;

   void Utilities::setFieldWidth(size_t width) {
      m_widthField = width;
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
      std::string str1;

      if (next_pos <= str.length()) {
         size_t pos = str.find_first_of(m_delimiter, next_pos);
         if (pos != std::string::npos) {
            str1 = str.substr(next_pos, pos - next_pos);
            next_pos = pos + 1;
         }
         else {
            str1 = str.substr(next_pos);
            next_pos = str.length() + 1;
         }
         if ((str1.empty()) && (next_pos != str.length() + 1))

         {
            more = false;
            throw str + "<-- ERROR: Token Failure";
         }
         if (m_widthField < str1.length())
            m_widthField = str1.length();
         more = next_pos <= str.length();
      }
      return str1;
   }

   void Utilities::setDelimiter(char Del) {
      m_delimiter = Del;
   }

   char Utilities::getDelimiter() {
      return m_delimiter;
   }
}  // namespace sdds