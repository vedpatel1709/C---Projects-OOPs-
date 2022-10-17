// Patel Ved Rajendrakumar
// section   : oop244 NAA
// student ID: 149409203
// vrpatel33@myseneca.ca
// workshop 2 part 2


#ifndef SDDS_GUEST_H
#define SDDS_GUEST_H
namespace sdds {

    struct PhoneNumber {
        int m_number;
        int m_areacode;
    };

    struct Guest {
        char m_name[21];
        PhoneNumber m_phno;
    };

    struct GuestList {
        Guest* m_gst;
        int m_noOfGuests;
    };

    void read(char* str, int len);
    void read(PhoneNumber& thePhoneNumber);
    bool read(Guest& theGuest);
    void print(const PhoneNumber& thePhoneNumber);
    void print(const Guest& theGuest);
    void print(const GuestList& theGuestList);
    void addGuest(GuestList& theGuestList, const Guest& aGuest);

}
#endif // !_SDDS_GUEST_H_

