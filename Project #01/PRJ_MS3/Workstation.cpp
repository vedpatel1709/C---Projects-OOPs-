// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <deque>
#include <iostream>
#include <iomanip>
#include <utility>

#include "CustomerOrder.h"
#include "Station.h"
#include "Workstation.h"


using namespace std;
using namespace sdds;

deque<CustomerOrder> g_pending{};
deque<CustomerOrder> g_completed{};
deque<CustomerOrder> g_incomplete{};

   Workstation::Workstation(const string& str) : Station{ str } {}

   void Workstation::fill(ostream& os) {
      if (!m_orders.empty()) {
         m_orders.front().fillItem(*this, os);
      }
   }

   bool Workstation::attemptToMoveOrder() {
      bool index = true;

      if (!(m_orders.empty())) {
         if (m_orders.front().isItemFilled(getItemName()) ||
            this->getQuantity() == 0) {
            if (m_pNextStation == nullptr) {
               if (m_orders.front().isOrderFilled()) {
                  g_completed.emplace_back(move(m_orders.front()));
               }
               else {
                  g_incomplete.emplace_back(move(m_orders.front()));
               }
            }
            else {
               (*m_pNextStation) += move(m_orders.front());
            }
            m_orders.pop_front();
            index = true;
         }
         index = false;
      }
      return index;
   }

   void Workstation::setNextStation(Workstation* station) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const { 
      return m_pNextStation; 
   }

   void Workstation::display(std::ostream& os) const {
      os << getItemName() << " --> ";
      if (m_pNextStation != nullptr) {
         os << m_pNextStation->getItemName() << std::endl;
      }
      else {
         os << "End of Line" << std::endl;
      }
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }

   bool Workstation::empty() const { 
      return m_orders.empty(); 
   }
  // namespace sdds