/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NDD
Workshop 4 part 2
Date: 10th october,2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CHAPTER_H
#define SDDS_CHAPTER_H
namespace sdds {
    const int PAGES = 200;
    class Chapter {
    private:
        char m_ChapterName[50];
        int m_pages;
    public:
        Chapter();
        Chapter(const char* name, int page);
        void setEmpty();
        void display() const;
        bool isEmpty() const;
        int& getPage();
        char* getName();
    };
}
#endif