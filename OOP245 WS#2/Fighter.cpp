// patel ved rajendrakumar
// oop244 NAA
// vrpatel33@myseneca.ca
// workshop 2 part 1

#define _CRT_SECURE_NO_WARNINGS
#include "Fighter.h"
#include <iostream>
#include <string.h>

using namespace std;
namespace sdds {

    // fighter name
    void fighter(char* name) {
        cout << "Enter Fighter Name: ";
        cin >> name;
    }

    //fighter power
    void fighter(int& power) {
        cout << "Enter Fighter Power: ";
        cin >> power;
    }

    //display fighter info
    void display(const Fighter& myFighter) {
        cout << "Name: " << myFighter.name;//name
        cout << ", Power: " << myFighter.power << endl;//power
    }

    //display no. of fighters 
    void display(const Competition& mycompetition) {
        for (int i = 0; i < mycompetition.numfighters; i++) {
            display(mycompetition.fighters[i]); //using previous function
        }
    }
   
    // will add new fighter
    void addFighter(Competition& myCompetition) {

        Fighter* NEWFIGHTER = new Fighter[myCompetition.numfighters + 1];
        for (int i = 0; i < myCompetition.numfighters ; i++) {
        	NEWFIGHTER[i] = myCompetition.fighters[i];
        }
        cout << "Information of the new fighter:"<< endl;
        cout << "Enter Fighter Name: ";//name
        cin >> NEWFIGHTER[myCompetition.numfighters].name;
        cout << "Enter Fighter Power: ";//power
        cin >> NEWFIGHTER[myCompetition.numfighters].power;
        // also can use previous power and name function
        delete[] myCompetition.fighters;
        myCompetition.fighters = NEWFIGHTER;
        myCompetition.numfighters = myCompetition.numfighters +1;
       }
    
    //will remove defeated fighter
    void removeFighter(Competition& mycompetition, const Fighter& loserFighter) {
        
        int index = 0;
        int z = 0;
        index= findFighter(mycompetition, loserFighter);
        if (index != -1) {
               Fighter* RMFIGHTER = new Fighter[mycompetition.numfighters - 1];
            for (int i = 0; i < mycompetition.numfighters; i++) {
                if (i != index) {
                    RMFIGHTER[z++] = mycompetition.fighters[i];
                }
            }
                mycompetition.numfighters=mycompetition.numfighters-1;// also can use -- option
                delete[] mycompetition.fighters;
                mycompetition.fighters = RMFIGHTER;
            }
        
       }
    //will find matching fighter
    int findFighter(const Competition& mycompetition, const Fighter& theFighter) {
       int index = -1;
        for (int i = 0; i < mycompetition.numfighters; i++) {
        	if (strcmp(mycompetition.fighters[i].name, theFighter.name) == 0) {
                index = i;
           	}
        }
        return index;
       }
   
    // will return true or false
    bool fight(const Fighter& f1, const Fighter& f2) {//m
        if (f1.power > f2.power) {
            return 1;
        }
        else return 0;
    }

   // will display result of fight 
    void fight(Competition& mycompetition, Fighter& f1, Fighter& f2) {//m
        cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
        cout << "    The winner => ";
        if (fight(f1, f2) == 1) {
            display(f1);
            removeFighter(mycompetition, f2);
        }
        else {
            display(f2);
            removeFighter(mycompetition, f1);
        }
    }


}