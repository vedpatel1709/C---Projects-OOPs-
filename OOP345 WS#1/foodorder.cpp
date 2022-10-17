// Name: Patel Ved Rajendrakumar
// Email: vrpatel33@myseneca.ca
// section: OOP345 NDD
// Date: 19th may, 2022
// FoodOrder.cpp

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "foodorder.h"

using namespace std;

double g_taxrate;
double g_dailydiscount;

namespace sdds {
   static int Counter_no = 0;

   // default constructor
   FoodOrder::FoodOrder() {
      food_Desc = nullptr;
      Name[0] = '\0';
      Price = -1;
      Is_Special = false;
   };

   void FoodOrder::display() {
      // display order
      if (Name[0] == '\0') {
         cout << left << setw(2) << ++Counter_no << ". " << "No Order" << endl;
      }
      else
      {
         // taxed price
         double taxed_Price = Price + (Price * g_taxrate);
         // discounted price
         double discounted_Price = taxed_Price - g_dailydiscount;

         cout << left << setw(2) << ++Counter_no << ". " << left << setw(10) << Name << "|" << left << setw(25) << food_Desc
            << "|" << left << setw(12) << fixed << setprecision(2) << taxed_Price << "|";

         // check for special condition
         if (Is_Special) {
            cout << right << setw(13) << discounted_Price;
         }
         cout << endl;
      }
   }

   void FoodOrder::read(istream& istr) {
      //assigning valyes to null so that new values can be saved
      food_Desc = nullptr;
      Name[0] = '\0';
      Price = -1;
      Is_Special = false;

      char name[10];
      istr.get(name, 10, ',');

      // will ignore , comma
      istr.ignore();

      string foodDesc;
      // will take value upto , and will ignore ,
      getline(istr, foodDesc, ',');

      double food_Price = -1;
      istr >> food_Price;
      // will ignore ; comma
      istr.ignore();

      // will accept "Y" and "N"
      char Special;
      istr >> Special;

      if (!istr.fail()) {

         strcpy(Name, name);

         food_Desc = new char[strlen(foodDesc.c_str()) + 1];
         strcpy(food_Desc, foodDesc.c_str());

         Price = food_Price;
         if (Special == 'Y') {
            Is_Special = true;
         }
         else {
            Is_Special = false;
         }
      }
   }

   // making sure there is no memory leak
   FoodOrder::~FoodOrder() {

      delete[] food_Desc;
      food_Desc = nullptr;

   };

}