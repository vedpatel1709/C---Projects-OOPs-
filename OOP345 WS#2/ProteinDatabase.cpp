/*
Name: Patel Ved Rajendrakumar
Email: vrpatel33@myseneca.ca
section: OOP345 NDD
Date: 23rd May,2022
Id: 149409203
*/

/*I have done all the coding by myself and only copied the code that my
 * professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>

#include "ProteinDatabase.h"

using namespace std;
namespace sdds {
   ProteinDatabase::ProteinDatabase() {}

   ProteinDatabase::~ProteinDatabase() { delete[] m_record; }

   ProteinDatabase::ProteinDatabase(char* f_name) {
      ifstream name(f_name);
      if (!name) {
         return;
      }
      string lines, nameRecord;
      while (getline(name, lines).good()) {
         if (lines[0] == '>') {
            m_length++;
         }
      }
      name.clear();
      name.seekg(ios::beg);
      m_record = new string[m_length];
      lines.clear();
      int i = -1;
      while (getline(name, lines).good()) {
         if (lines[0] == '>') {
            ++i;
            nameRecord = lines.substr(1);
         }
         else if (!nameRecord.empty()) {
            m_record[i] += lines;
         }
      }
   }

   ProteinDatabase::ProteinDatabase(ProteinDatabase&& mv) { *this = move(mv); }
   ProteinDatabase::ProteinDatabase(const ProteinDatabase& cp) { *this = cp; }

   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& PD) {
      if (this != &PD) {
         delete[] m_record;
         m_record = nullptr;
         m_record = PD.m_record;
         PD.m_record = nullptr;
         m_length = PD.m_length;
         PD.m_length = 0;
      }
      return *this;
   }

   ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& PD) {
      if (this != &PD) {
         if (PD.m_record != nullptr) {
            delete[] m_record;
            m_length = PD.m_length;
            m_record = new string[m_length]{};
            for (long unsigned int i = 0; i < m_length; i++) {
               m_record[i] = PD.m_record[i];
            }
         }
      }
      return *this;
   }

   size_t ProteinDatabase::size() const { return m_length; }
   string ProteinDatabase::operator[](size_t index) {
      if (index < m_length) {
         return m_record[index];
      }
      return "";
   }
}  // namespace sdds