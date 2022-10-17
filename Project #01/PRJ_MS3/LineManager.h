// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include "Workstation.h"

namespace sdds {
   class LineManager {
      vector<Workstation*> m_activeLine;
      size_t m_cntCustomerOrder;
      Workstation* m_firstStation;

   public:
      LineManager();
      LineManager(const std::string& file, const vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };
};  // namespace sdds

#endif