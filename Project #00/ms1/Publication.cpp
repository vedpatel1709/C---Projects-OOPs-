#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include "Publication.h"
using namespace std;
namespace sdds
{
    Publication::Publication(const Publication& source)
    {
        m_title = nullptr;
        *this = source;
    }

    Publication& Publication::operator=(const Publication& src)
    {
        m_shelfId[0] = '\0';
        strcpy(m_shelfId, src.m_shelfId);
        delete[] m_title;
        m_membership = src.m_membership;
        m_libRef = src.m_libRef;
        m_date = src.m_date;
        if (src.m_title != nullptr)
        {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
        else
        {
            m_title = nullptr;
        }
        return *this;
    }

    Publication::~Publication()
    {
        delete[] m_title;
    }
    Publication::Publication()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
       //resetDate();
    }
    void Publication::set(int member_id)
    {
        m_membership = member_id;
    }
    void Publication::setRef(int value)
    {
        m_libRef = value;
    }
    void Publication::resetDate()
    {
        Date D;
        m_date = D;
    }
    char Publication::type() const
    {
        return 'P';
    }
    bool Publication::onLoan() const
    {
        return (m_membership != 0);
    }
    Date Publication::checkoutDate() const
    {
        return m_date;
    }
    bool Publication::operator==(const char* title) const
    {
        return (strstr(m_title, title));
    }
    Publication::operator const char* () const
    {
        return m_title;
    }
    int Publication::getRef() const
    {
        return m_libRef;
    }
    bool Publication::conIO(ios& io) const
    {
        return (&io == &cin || &io == &cout);
    }
    ostream& Publication::write(ostream& os) const
    {
        if (conIO(os))
        {
            os << "| " << m_shelfId << " | ";
            os << m_title;
            os.width(33 - strlen(m_title));
            os.fill('.');
            os << " | ";
            if (m_membership == 0)
            {
                os << " N/A ";
            }
            else
            {
                os << m_membership;
            }
            os << " | " << m_date << " |";
        }
        else
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }
    std::istream& Publication::read(std::istream& istr)
    {
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;

        char shelfId[5];
        char title[256];
        if (conIO(istr))
        {
            std::cout << "Shelf No: ";
            istr.getline(shelfId, 5);

            std::cout << "Title: ";
            istr.getline(title, 256);

            if (strlen(title) <= 0)
            {
                istr.setstate(ios::failbit);
            }

            std::cout << "Date: ";
            istr >> m_date;
            if (m_date.errCode())
            {
                istr.setstate(ios::failbit);
            }
        }
        else
        {
            char libRef[6];
            istr.getline(libRef, 6, '\t');
            m_libRef = atoi(libRef);
            istr.getline(shelfId, 5, '\t');
            istr.getline(title, SDDS_TITLE_WIDTH  +1 , '\t');
            istr >> m_membership;
            istr >> m_date;
        }
        if (istr)
        {
            strcpy(m_shelfId, shelfId);
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
        return istr;
    }
    Publication::operator bool() const
    {

        return (m_shelfId[0] != '\0' && m_title != nullptr);
    }
}