/*
 Name: Ved Rajendrakumar Patel
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 30th may,2022
 Id: 149409203
 */

 /*I have done all the coding by myself and only copied the code that my
  * professor provided to complete my workshops and assignments.*/

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <cmath>
#include <iostream>
#include <string>

#include "Collection.h"
#include "Pair.h"

namespace sdds {

    template <class T>
    class Set : public Collection<T, 100> {
        const unsigned int CAPACITY = 100;

    public:
        Set() {}
        bool add(const T& elements) {
            for (int i = 0; (unsigned)i < this->Stored_Elements; i++) {
                if (elements == this->array[i]) {
                    return false;
                }
            }
            return Collection<T, 100>::add(elements);
        }
    };

    template <>
    bool Set<double>::add(const double& ele) {
        for (int i = 0; (unsigned)i < this->Stored_Elements; i++) {
            if (std::fabs(ele - this->array[i]) <= 0.01) {
                return false;
            }
        }
        return Collection<double, 100>::add(ele);
    };
}  // namespace sdds
#endif