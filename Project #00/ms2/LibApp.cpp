/* Citation and Sources...
Final Project Milestone 1
Module: LibApp
Filename: LibApp.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "LibApp.h"

using namespace std;
namespace sdds
{
    bool LibApp::confirm(const char* message)
    {
        Menu m(message);
        m << "Yes";
        if (m.run())
        {
            return true;
        }
        else {
            return false;
        }
    }
    void LibApp::load()
    {
        cout << "Loading Data\n";
    }

    void LibApp::save()
    {
        cout << "Saving Data\n";
    }

    void LibApp::search()
    {
        cout << "Searching for publication\n";
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication\n";
        cout << "Publication returned\n";
        m_changed = true;
        cout << "\n";
    }

    void LibApp::newPublication()
    {
        cout << "Adding new publication to library\n";
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added\n";
        }
        cout << "\n";
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library\n";
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed\n";
        }
        cout << "\n";
    }

    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out\n";
        }
        cout << "\n";
    }

    LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_changed = false;
        m_mainMenu << "Add New Publication"  << "Remove Publication"<< "Checkout publication from library"<< "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }

    void LibApp::run()
    {
        int loop = 1;
        do
        {
            int selection = m_mainMenu.run();
            if (selection == 0)
            {
                if (m_changed)
                {
                   int index = m_exitMenu.run();
                    if (index == 1)
                    {
                       save();
                       loop = 0;
                    }
                    else if (index == 2)
                    {
                        loop = 1;
                        cout << endl;
                    }
                    else if (index == 0)
                    {

                        bool get = confirm("This will discard all the changes are you sure?");
                        if (get)
                        {
                            loop = 0;
                        }
                        else
                        {
                            loop = 0;
                        }
                    }
                }
                else
                {
                    loop = 0;
                }
            }
            else if (selection == 1)
            {
                newPublication();

            }
            else if (selection == 2)
            {
                removePublication();

            }
            else if (selection == 3)
            {
                checkOutPub();

            }
            else if (selection == 4)
            {
                returnPub();
            }
        } while (loop);
        cout << "\n-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application\n";
    }
   
}
