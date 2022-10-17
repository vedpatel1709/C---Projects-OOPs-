/*
 Name: Patel Ved Rajendrakumar
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 23rd May,2022
 Id: 149409203
 */

 /*I have done all the coding by myself and only copied the code that my
  * professor provided to complete my workshops and assignments.*/

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#include "TimedTask.h"

using namespace std;

namespace sdds {

   TimedTask::TimedTask() {}

   void TimedTask::startClock() { Clock_Starts = chrono::steady_clock::now(); }

   void TimedTask::stopClock() { Clock_ends = chrono::steady_clock::now(); }

   void TimedTask::addTask(const char* name) {
      auto Dura_Task = chrono::duration_cast<chrono::nanoseconds>(Clock_ends - Clock_Starts);
      Tasks[Num_Record].Task_Name = name;
      Tasks[Num_Record].Unit_Time = "nanoseconds";
      Tasks[Num_Record].Dura_Task = Dura_Task;
      Num_Record++;
   }

   ostream& operator<<(ostream& ostr, TimedTask& T) {
      ostr << "--------------------------\n";
      ostr << "Execution Times:\n";
      ostr << "--------------------------\n";
      for (int n = 0; n < T.Num_Record; n++) {
         ostr << setw(21) << left << T.Tasks[n].Task_Name << ' ' << setw(13) << right
            << T.Tasks[n].Dura_Task.count() << ' ' << T.Tasks[n].Unit_Time << '\n';
      }
      ostr << "--------------------------\n";
      return ostr;
   }

   TimedTask::~TimedTask() {}

}  // namespace sdds