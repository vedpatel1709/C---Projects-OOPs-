/*
Name = Patel Ved Rajendrakumar
Student_ID = 149409203
Section = OOP244 NDD
Workshop 6 part 1
Date: 10th october, 2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
    bool Book::validPhone(const  char* Book_Title, const char* Author_Name, int Bookcase_Number, int Shelf_Number)const {
        if (Author_Name != nullptr && Author_Name[0] != '\0' && Book_Title != nullptr && Book_Title[0] != '\0' && strlen(Author_Name) <= MaxAuthorLen && strlen(Book_Title) <= MaxTitleLen && Bookcase_Number >= 1 && Bookcase_Number <= NoOfBookCases && Shelf_Number <= NoOfShelves && Shelf_Number >= 1) {
            return true;
        }
        else {
            return false;
        }
    }

    Book::Book() {
        setEmpty();
    }

    Book::Book(const char* Book_Title, const char* Author_Name, int Bookcase_Number, int Shelf_Number) {
        set(Book_Title, Author_Name, Bookcase_Number, Shelf_Number);
    }

    Book::Book(const Book& cnt) {
        if (cnt) {
            set(cnt.m_BookTitle, cnt.m_AuthorName, cnt.m_BookcaseNumber, cnt.m_ShelfNumber);
        }
    }

    void Book::setEmpty() {
        m_BookTitle = nullptr;
        m_AuthorName = nullptr;
        m_BookcaseNumber = 0;
        m_ShelfNumber = 0;
    }

    void Book::allocationAndCopy(const char* Book_Title, const char* Author_Name) {
        delete[] m_BookTitle;
        m_BookTitle = new char[strlen(Book_Title) + 1];
        strcpy(m_BookTitle, Book_Title);
        delete[] m_AuthorName;
        m_AuthorName = new char[strlen(Author_Name) + 1];
        strcpy(m_AuthorName, Author_Name);
    }

    Book& Book::operator=(const Book& cnt) {
        if (this != &cnt) {
            set(cnt.m_BookTitle, cnt.m_AuthorName, cnt.m_BookcaseNumber, cnt.m_ShelfNumber);
        }
        return *this;
    }
    /*Book::~Book() {
        delete[] m_BookTitle;
        delete[] m_AuthorName;
    }*/

    Book::operator bool() const {
        if (m_BookTitle != nullptr && m_AuthorName != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void Book::set(const char* Book_Title, const char* Author_Name, int Bookcase_Number, int Shelf_Number) {
        if (validPhone(Book_Title, Author_Name, Bookcase_Number, Shelf_Number)) {
            allocationAndCopy(Book_Title, Author_Name);
            m_BookcaseNumber = Bookcase_Number;
            m_ShelfNumber = Shelf_Number;
        }
        else {
            delete[] m_BookTitle;
            delete[] m_AuthorName;
            setEmpty();
        }
    }

    std::ostream& Book::write(std::ostream& ostr, bool onScreen) const {
        if (onScreen) {
            if (*this) {
                ostr.setf(ios::left);
                ostr.width(MaxTitleLen);
                ostr << m_BookTitle;
                ostr << "| ";
                ostr.width(MaxAuthorLen);
                ostr << m_AuthorName;
                ostr.unsetf(ios::left);
                ostr << "| ";
                ostr << m_ShelfNumber << "/";
                ostr.setf(ios::right);
                ostr.width(3);
                ostr.fill('0');
                ostr << m_BookcaseNumber;
                ostr.fill(' ');
                ostr.unsetf(ios::right);
            }
            else {
                ostr << "Invalid Book Record ................... | ........................ | .....";
            }
        }

        else {
            if (*this) {
                ostr << m_BookTitle << "," << m_AuthorName << "," << m_ShelfNumber << "/" << m_BookcaseNumber;
            }
        }
        return ostr;
    }

    std::istream& Book::read(std::istream& istr) {
        char BookTitle[100];
        char AuthorName[100];
        int BN = -1, SN = -1;
        istr.get(BookTitle, 100, ',');
        extractChar(istr, ',');
        istr.get(AuthorName, 100, ',');
        extractChar(istr, ',');
        istr >> SN;
        extractChar(istr, '/');
        istr >> BN;
        if (BookTitle[0] == '\n') {
            char BookTitle2[100];
            int j = 0;
            for (unsigned int i = 0; i < strlen(BookTitle); i++) {
                if (BookTitle[i] == '\n') continue;
                else BookTitle2[j++] = BookTitle[i];
            }
            BookTitle2[j] = '\0';
            strcpy(BookTitle, BookTitle2);
        }
        if (!istr.fail()) {
            set(BookTitle, AuthorName, BN, SN);
        }
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Book& cnt) {
        cnt.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Book& cnt) {
        return cnt.read(istr);
    }

    void Book::extractChar(std::istream& istr, char ch)const {
        if (istr.peek() != ch) {
            istr.setstate(ios::failbit);
        }
        else {
            istr.get();
        }
    }
    Book::~Book() {
        delete[] m_BookTitle;
        delete[] m_AuthorName;
    }
}