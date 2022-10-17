// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORK_STATION_H
#define SDDS_WORK_STATION_H

#include <deque>
#include <iostream>

#include "CustomerOrder.h"
#include "Station.h"

using namespace std;

extern deque<sdds::CustomerOrder> g_pending;
extern deque<sdds::CustomerOrder> g_completed;
extern deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {

   class Workstation : public Station {
      deque<CustomerOrder> m_orders;
      Workstation* m_pNextStation{nullptr};

   public:
      Workstation(const string& str);
      void fill(ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station = nullptr);
      Workstation* getNextStation() const;
      void display(ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
      bool empty() const;
   };
};  // namespace sdds

#endif