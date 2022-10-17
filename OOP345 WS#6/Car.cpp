/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 07/08/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>

#include "Autoshop.h"
#include "Car.h"

using namespace std;

namespace sdds {
   Car::Car(std::istream& is) {

      std::string tag;
      std::string speed;
      std::string condition;

      bool digital = true;
      getline(is, tag, ',');
      getline(is, maker, ',');
      getline(is, condition, ',');
      getline(is, speed, ',');

      maker.erase(0, maker.find_first_not_of(' '));
      maker.erase(maker.find_last_not_of(' ') + 1);
      condition.erase(0, condition.find_first_not_of(' '));
      condition.erase(condition.find_last_not_of(' ') + 1);
      speed.erase(0, speed.find_first_not_of(' '));
      speed.erase(speed.find_last_not_of(' ') + 1);

      if (condition.empty() || condition[0] == ' ') {
         cnd = 'n';
      }
      else if (condition[0] == 'n' || condition[0] == 'u' || condition[0] == 'b') {
         cnd = condition[0];
      }
      else {
         std::string err = "Invalid record!";
         throw err;
      }
      for (int tmp : speed) {
         if (tmp < 48 || tmp > 57) {
            digital = false;
            break;
         }
      }
      if (digital) {
         TopSpeed = std::stod(speed);
      }
      else {
         std::string err = "Invalid record!";
         throw err;
      }
   }

   std::string Car::condition() const {

      std::string condition;
      switch (cnd) {
      case 'n':
         condition.assign("new");
         break;
      case 'u':
         condition.assign("used");
         break;
      case 'b':
         condition.assign("broken");
         break;
      }
      return condition;
   }

   double Car::topSpeed() const {
      return TopSpeed;
   }

   void Car::display(std::ostream& out) const {
      out << "| " << std::right << std::setw(10) << maker;
      out << " | " << std::left << std::setw(6) << condition();
      out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed();
      out << " |";
   }
}