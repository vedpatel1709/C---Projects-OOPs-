// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/21/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H

#include <iostream>
#include <string>
#include <utility>

#include "Station.h"

namespace sdds {
   struct Item {
      std::string m_itemName;
      size_t m_serialNumber{ 0 };
      bool m_isFilled{ false };
      Item(const std::string& src) : m_itemName(src) {};
   };

   class CustomerOrder {
      std::string m_name;
      std::string m_product;
      unsigned int m_cntItem{ 0 };
      Item** m_lstItem{ nullptr };

      static size_t m_widthField;

   public:
      CustomerOrder();
      CustomerOrder(const std::string&);
      ~CustomerOrder();
      CustomerOrder(CustomerOrder&);
      CustomerOrder& operator=(CustomerOrder&) = delete;
      CustomerOrder(CustomerOrder&&) noexcept;
      CustomerOrder& operator=(CustomerOrder&&) noexcept;
      bool isOrderFilled() const;
      bool isItemFilled(const std::string& itemName) const;
      void fillItem(Station& station, std::ostream& os);
      void display(std::ostream& os) const;
   };
}  // namespace sdds
#endif  // !SDDS_CUSTOMER_ORDER_H