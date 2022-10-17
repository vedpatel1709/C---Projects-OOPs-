/* Name: Patel Ved Rajendrakumar
   Section: OOP244 NAA
   ID:149409203
   Email: vrpatel33@myseneca.ca
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
using namespace  std;
namespace sdds {
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;
    class EggCarton {
        int m_size;
        int m_noOfEggs;
        bool m_jumbosize;
        void setBroken();
    public:
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
        ostream& display(std::ostream& ostr) const;
        istream& read(std::istream& istr);

        operator bool() const;
        operator int() const;
        operator double() const;

        EggCarton& operator--();
        EggCarton operator--(int);
        EggCarton& operator++();
        EggCarton operator++(int);

        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;
    };
    int operator+(int left, const EggCarton& right);
    ostream& operator<<(ostream& ostr, const EggCarton& right);
    istream& operator>>(istream& istr, EggCarton& right);

}
#endif