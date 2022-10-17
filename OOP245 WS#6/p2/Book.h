/*
Name = Patel Ved Rajendrakumar
Student_ID = 149409203
Section = OOP244 NDD
Workshop 6 part 1
Date: 10th october, 2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds {
    const int NoOfBookCases = 132;
    const int NoOfShelves = 7;
    const int MaxTitleLen = 40;
    const int MaxAuthorLen = 25;
    class Book {
        char* m_BookTitle{};
        char* m_AuthorName{};
        int m_BookcaseNumber;
        int m_ShelfNumber;
        bool validPhone(const  char* BookTitle, const char* AuthorName, int BookcaseNumbe, int ShelfNumber)const;
        void set(const char* BookTitle = nullptr, const char* AuthorName = nullptr, int BookcaseNumbe = 0, int ShelfNumber = 0);
        void setEmpty();
        void allocationAndCopy(const char* BookTitle, const char* AuthorName);
        void extractChar(std::istream& istr, char ch)const;
    public:
        Book();
        Book(const char* BookTitle, const char* AuthorName, int BookcaseNumbe, int ShelfNumber);
        Book(const Book& cnt);
        Book& operator=(const Book& cnt);
       ~Book();
        operator bool() const;
        std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Book& cnt);
    std::istream& operator>>(std::istream& istr, Book& cnt);
}
#endif