// Name: Patel Ved Rajendrakumar
// Email: vrpatel33@myseneca.ca
// section: OOP345 NDD
// Date: 19th may, 2022
// FodOrder.h

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FOOD_ORDER_H
#define SDDS_FOOD_ORDER_H 

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder {
		char Name[10];
		char* food_Desc;
		double Price;
		bool Is_Special;

	public:
		FoodOrder();
		~FoodOrder();
		void read(std::istream& istr);
		void display();
	};
}

#endif