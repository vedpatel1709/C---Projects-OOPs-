//Name: Patel Ved Rajendrakumar
//ID: 149409203
//Email: vrpatel33@myseneca.ca
// Date: 2nd december, 2021
//Section: NAA
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {

    /*
    Requirement for the template:
    23: not needed
    25: nothing
    */
    template<typename T1, typename T2>
    bool check(T1* array, int index, T2 key)
    {
        return array[index] == key;
    }

    /*
    Requirement for the template:
   35: collection constructor
   40: check function
   42: add function inside collection class
    */
    template<typename T1, typename T2>
    bool search(T1* array, int number, T2 key, Collection<T1>& c)
    {
        bool index = false;
        for (int i = 0; i < number; i++)
        {
            if (check(array, i, key))
            {
                c.add(array[i]);
                index = true;
            }
        }
        return index;
    }
    /*
    not needed anything special
    */
    template <typename T>
        void listArrayElements(const char* title, T* array, int number)
    {
        cout << title << endl;
        for (int i = 0; i < number; i++)
        {
            cout << i + 1 << ": " << array[i] << endl;
        }
    }

     /*
    Requirement for the template:
   ">" operator for comparision
    */
    template <typename T1>
    bool sizeCheck(Collection<T1>& c1, Collection<T1>& c2)
    {
        return c1.size() > c2.size();
    }
}
#endif // !SDDS_SEARCH_H_

