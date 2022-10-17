/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>
namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() {};
    };
    std::istream& operator>>(std::istream& istr, Streamable& Stream);
    std::ostream& operator<<(std::ostream& ostr, const Streamable& Stream);
}
#endif 