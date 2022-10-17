/*
 Name: Ved Rajendrakumar Patel
 Email: vrpatel33@myseneca.ca
 section: OOP345 NDD
 Date: 30th may,2022
 Id: 149409203
 */

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>
#include <string>

namespace sdds {
    class Pair {

        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() const {
            return m_key;
        }
        const std::string& getValue() const {
            return m_value;
        }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

        // Added Stuff
        
        static bool Same(const Pair& left, const Pair& right);
        Pair();
        bool operator==(const Pair& RO)const;
        virtual std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Pair& P);
}
#endif // !SDDS_PAIR_H