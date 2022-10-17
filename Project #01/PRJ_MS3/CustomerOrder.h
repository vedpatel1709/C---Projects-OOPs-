// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H

#include "Station.h"

using namespace std;

namespace sdds {
   struct Item
   {
      string m_itemName;
      size_t m_serialNumber{ 0 };
      bool m_isFilled{ false };

      Item(const string& src) : m_itemName(src) {};
   };

   class CustomerOrder {
      string m_name;
      string m_product;
      unsigned int m_cntItem{ 0 };
      Item** m_lstItem{ nullptr };
      static size_t m_widthField;

   public:
      CustomerOrder();
      CustomerOrder(const string&);
      ~CustomerOrder();
      CustomerOrder(const CustomerOrder&);
      CustomerOrder& operator=(const CustomerOrder&) = delete;
      CustomerOrder(CustomerOrder&&) noexcept;
      CustomerOrder& operator=(CustomerOrder&&) noexcept;
      bool isOrderFilled() const;
      bool isItemFilled(const string& itemName) const;
      void fillItem(Station& station, ostream& os);
      void display(ostream& os) const;

   };
};    // namespace sdds
#endif  // !SDDS_CUSTOMER_ORDER_H