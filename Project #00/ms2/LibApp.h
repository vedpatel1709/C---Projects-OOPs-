/* Citation and Sources...
Final Project Milestone 1
Module: LibApp
Filename: LibApp.h
Version 1.0
Author	Ved Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/10/15  Preliminary release

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

/*
Name: Patel Ved Rajendrakumar
Date: 20th november, 2021
ID: 149409203
Email: vrpatel33@myseneca.ca
*/

#ifndef SDDS_LIB_APP_H
#define SDDS_LIB_APP_H

#include "Menu.h"

namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        bool confirm(const char* message);
        void load();
        void save();
        void search();

        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        void run();
    };

};
#endif