/*
 Name: Patel Ved Rajendrakumar
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 30th may, 2022
 Id: 149409203
 */
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include "Pair.h"
#include <string>

namespace sdds {

    template<class T, unsigned int CAPACITY>
    class Collection {

    public:

        T array[CAPACITY];
        unsigned int Stored_Elements = 0;
        T dummy{};

        Collection() {}

        unsigned int size()
        {
            return Stored_Elements;
        }

        void display(std::ostream& ostr = std::cout)const {
            ostr << "----------------------" << std::endl;
            ostr << "|" << " Collection Content " << "|" << std::endl;
            ostr << "----------------------" << std::endl;
            for (size_t i = 0; i < Stored_Elements; i++) {
                ostr << array[i] << std::endl;
            }
            ostr << "----------------------" << std::endl;
        }

        virtual bool add(const T& Temp) {

            if (Stored_Elements < CAPACITY) {
                array[Stored_Elements] = Temp;
                Stored_Elements++;
                return true;
            }
            else {
                return false;
            }
        }

        T& operator[](int index) {
            T& Temp= index >= 0 && (unsigned)index < Stored_Elements ?array[index] : dummy;
            return Temp;
        }

        virtual ~Collection() {}

    };


    template<> Collection<Pair, 100>::Collection() {
        Pair a("No Key", "No Value");
        dummy = a;

    };

}
#endif 