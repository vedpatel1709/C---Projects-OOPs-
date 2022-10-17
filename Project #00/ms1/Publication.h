#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
namespace sdds
{
    class Publication : public Streamable
    {
        char *m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();

       
        virtual void set(int member_id);
      
        void setRef(int value);
       
        void resetDate();
        

       
        virtual char type() const;
       
        bool onLoan() const;
       
        Date checkoutDate() const;
       
        bool operator==(const char *title) const;
       
       
        operator const char *() const;
       
        int getRef() const;
       

       
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        bool conIO(std::ios &io) const;
        operator bool() const;

       
        Publication(const Publication &src);
        Publication &operator=(const Publication &src);
        ~Publication();
    };
}
#endif