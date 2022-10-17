/*
 Name: Patel Ved Rajendrakumar
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 23rd May,2022
 Id: 149409203
 */

 /*I have done all the coding by myself and only copied the code that my
  * professor provided to complete my workshops and assignments.*/

#ifndef SDDS_PROTEIN_DATABASE_H_
#define SDDS_PROTEIN_DATABASE_H_

#include <iostream>

using namespace std;
namespace sdds
{
   class ProteinDatabase {
   public:
      string* m_record{};
      long unsigned int m_length{};
      long unsigned int m_index{};

      ProteinDatabase();
      ~ProteinDatabase();
      ProteinDatabase(char* name);

      size_t size() const;
      string operator[](size_t);
      ProteinDatabase(const ProteinDatabase& cp);
      ProteinDatabase& operator=(const ProteinDatabase& PD);
      ProteinDatabase(ProteinDatabase&& mv);
      ProteinDatabase& operator=(ProteinDatabase&& PD);
   };
}  // namespace sdds
#endif  // !SDDS_PROTEIN_DATABASE_H_
