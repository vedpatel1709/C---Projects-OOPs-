/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NDD
Workshop 6 part 1
Date: 10th october,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
namespace sdds
{
    const int MaxNameLength = 55;
    class Contact
    {
        char* m_name{};
        int m_area;
        int m_exchangeCode;
        int m_number;
        bool validPhone(int areaCode, int exchangeCode, int number)const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(std::istream& istr, char ch)const;
        std::ostream& printPhoneNumber(std::ostream& istr)const;
        void set(const char* name, int areaCode, int exchangeCode, int number);
    public:
        Contact(const char* name = nullptr, int areaCode = 0, int excahngeCode = 0, int number = 0);
        Contact(const Contact& cnt);
        Contact& operator=(const Contact& cnt);
        ~Contact();
        operator bool() const;
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;
        std::istream& read(std::istream& istr);

    };
    std::ostream& operator<<(std::ostream& ostr, const Contact& cnt);
    std::istream& operator>>(std::istream& istr, Contact& cnt);
}
#endif 


