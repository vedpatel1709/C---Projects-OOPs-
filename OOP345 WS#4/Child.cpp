/*
Name: Ved Rajendrakumar Patel
Student Id: 149409203
email: vrpatel33@myseneca.ca
Section: NDD
Date: 06/07/2022
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Child.h"

using namespace std;
namespace sdds {
    Child::Child() {
        SetEmpty();
    }
    void Child::SetEmpty() {
        delete[] toy;
        toy = nullptr;
        m_Count = 0;
        m_ChildName = "";
        m_ChildAge = 0;
    }
    Child::Child(Child&& Child) {
        *this = move(Child);
    }
    Child& Child::operator = (Child&& Child) {
        if (this != &Child) {
            m_Count = Child.m_Count;
            m_ChildName = Child.m_ChildName;
            m_ChildAge = Child.m_ChildAge;
            delete[] toy;
            toy = Child.toy;
            Child.toy = nullptr;
            Child.m_Count = 0;
            Child.m_ChildName = "";
            Child.m_ChildAge = 0;
        }
        return *this;
    }
    Child& Child::operator = (const Child& child) {
        if (this != &child) {
            m_Count = child.m_Count;
            m_ChildName = child.m_ChildName;
            m_ChildAge = child.m_ChildAge;
            delete[] toy;
            toy = new Toy[m_Count];
            for (size_t i = 0; i < m_Count; i++) {
                toy[i] = child.toy[i];
            }
        }
        return *this;
    }
    Child::Child(std::string name, int childAge,
        const Toy* toys[], size_t count) {
        toy = new Toy[count];
        m_ChildName = name;
        m_ChildAge = childAge;
        m_Count = count;
        for (size_t i = 0; i < count; i++) {
            toy[i] = *toys[i];
        }
    }
    Child::Child(const Child& Child) {
        *this = Child;
    }
    size_t Child::size() const {
        return m_Count;
    }

    ostream& operator << (ostream& ostr,
        const Child& child) {
        static size_t CALL_CNT;
        ++CALL_CNT;
        ostr << "--------------------------\n" <<
            "Child " << CALL_CNT << ": " << child.m_ChildName << " " << child.m_ChildAge << " years old:" << endl;
        ostr << "--------------------------\n";
        if (child.m_Count == 0) {
            ostr << "This child has no toys!" << endl;
        }
        else {
            for (size_t i = 0; i < child.m_Count; i++) {
                ostr << child.toy[i];
            }
        }
        ostr << "--------------------------\n";
        return ostr;
    }

    Child::~Child() {
        delete[] toy;
        toy = nullptr;
    }
}