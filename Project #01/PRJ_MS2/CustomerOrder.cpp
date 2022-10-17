// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/21/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds {

   size_t CustomerOrder::m_widthField = 0;

   CustomerOrder::CustomerOrder() {
      m_name = { "" };
      m_product = { "" };
      m_cntItem = { 0 };
      m_lstItem = { nullptr };
      m_widthField = { 0 };
   }

   CustomerOrder::CustomerOrder(const std::string& str) {
      Utilities util;
      size_t next_pos = 0;
      bool index = true;

      m_cntItem = 0;
      m_name = util.extractToken(str, next_pos, index);
      m_product = util.extractToken(str, next_pos, index);

      size_t another_pos = next_pos;

      while (index) {
         util.extractToken(str, next_pos, index);
         m_cntItem++;
      }

      m_lstItem = new Item * [m_cntItem];
      index = true;

      for (size_t i = 0; i < m_cntItem; i++) {
         m_lstItem[i] = new Item(util.extractToken(str, another_pos, index));
      }

      if (util.getFieldWidth() > m_widthField) {
         m_widthField = util.getFieldWidth();
      }
   }
   CustomerOrder::~CustomerOrder() {
      if (m_lstItem) {
         for (unsigned int i = 0; i < m_cntItem; i++) delete m_lstItem[i];
      }

      delete[] m_lstItem;
      m_lstItem = nullptr;
   }
   CustomerOrder::CustomerOrder(CustomerOrder&) { throw "!ERROR"; }

   CustomerOrder::CustomerOrder(CustomerOrder&& cop) noexcept {
      *this = std::move(cop);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cop) noexcept {
      if (this != &cop) {
         for (unsigned int z = 0; z < m_cntItem; ++z) delete m_lstItem[z];
         delete[] m_lstItem;
         m_name = cop.m_name;
         m_product = cop.m_product;
         m_cntItem = cop.m_cntItem;
         m_lstItem = cop.m_lstItem;
         cop.m_cntItem = 0;
         cop.m_lstItem = nullptr;
      }
      return *this;
   }

   bool CustomerOrder::isOrderFilled() const {
      bool index = true;
      for (unsigned int z = 0; z < m_cntItem; z++) {
         if (!m_lstItem[z]->m_isFilled) index = false;
      }
      return index;
   }

   bool CustomerOrder::isItemFilled(const std::string& Itname) const {
      for (unsigned int i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == Itname) {
            return false;
         }
      }
      return true;
   }

   void CustomerOrder::fillItem(Station& st, std::ostream& os) {
      for (unsigned int i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == st.getItemName()) {
            if (st.getQuantity() > 0) {
               m_lstItem[i]->m_serialNumber = st.getNextSerialNumber();
               m_lstItem[i]->m_isFilled = true;
               st.updateQuantity();
               os << "    Filled " << m_name << ", " << m_product << " [";
               os << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
            else {
               os << "    Unable to fill " << m_name << ", " << m_product << " [";
               os << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << std::endl;
      for (unsigned int i = 0; i < m_cntItem; i++) {
         os << "[" << setw(6) << setfill('0') << right;
         os << m_lstItem[i]->m_serialNumber << "] " << setfill(' ');
         os << setw(m_widthField) << left << m_lstItem[i]->m_itemName << " - ";
         os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
      }
   }
}  // namespace sdds