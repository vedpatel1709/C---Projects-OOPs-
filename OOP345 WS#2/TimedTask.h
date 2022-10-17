/*
 Name: Patel Ved Rajendrakumar
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 23rd May,2022
 Id: 149409203
 */

 /*I have done all the coding by myself and only copied the code that my
  * professor provided to complete my workshops and assignments.*/
#ifndef SDDS_TIMED_TASK_H_
#define SDDS_TIMED_TASK_H_

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
   const int m_MaxObjects = 10;
   class TimedTask {
      int Num_Record{};
      chrono::steady_clock::time_point Clock_Starts;
      chrono::steady_clock::time_point Clock_ends;
      struct Task {
         string Task_Name{};
         string Unit_Time{};
         chrono::steady_clock::duration Dura_Task;
      } Tasks[m_MaxObjects];

   public:
      TimedTask();
      void startClock();
      void stopClock();
      void addTask(const char* name);
      friend ostream& operator<<(ostream& ostr, TimedTask& T);
      ~TimedTask();
   };
}  // namespace sdds

#endif  // !SDDS_TIMED_TASK_H_
