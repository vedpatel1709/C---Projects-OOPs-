// Patel Ved Rajendrakumar
// section   : oop244 NAA
// student ID: 149409203
// vrpatel33@myseneca.ca
// workshop 2 part 2

#include <iostream>
#include <cstring>
#include "Guests.h"
using namespace std;

namespace sdds {
    void read(char* str, int len) {
        if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
        cin.getline(str, len);
    }
    void read(PhoneNumber& thePhoneNumber) {
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode >> thePhoneNumber.m_number;
    }
    bool read(Guest& theGuest) {
        bool input;
        input = false;
        cout << "Guest name: ";
        cin.ignore();
        cin.getline(theGuest.m_name, 20);
        if (strlen(theGuest.m_name) !=0) {
            read(theGuest.m_phno);
            input =true;
        }
        return input;
    }
    void print(const PhoneNumber& thePhoneNumber) {
        cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;
    }
    void print(const Guest& theGuest) {
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);
       // cout << endl;
    }
    void print(const GuestList& theGuestList) {
        for (int i = 0; i < theGuestList.m_noOfGuests; i++) {
            cout << i + 1 << "- ";
            print(theGuestList.m_gst[i]);
        }
    }
    void addGuest(GuestList& theGuestList, const Guest& aGuest) {
        Guest* NEWGUESTLIST = theGuestList.m_gst;
            theGuestList.m_gst = new Guest[theGuestList.m_noOfGuests + 1];
         for (int i = 0; i < theGuestList.m_noOfGuests; i++) {
             theGuestList.m_gst[i] = NEWGUESTLIST[i] ;
        }
        theGuestList.m_gst[theGuestList.m_noOfGuests++] = aGuest;
        delete[] NEWGUESTLIST;
    }
   
}