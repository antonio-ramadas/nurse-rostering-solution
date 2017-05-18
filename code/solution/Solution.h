//
// Created by F0lha on 16/05/2017.
//

#ifndef NRS_SOLUTION_H
#define NRS_SOLUTION_H

#include <random>
#include "../Scenario.h"
#include "../WeekData.h"
#include "NurseSolution.h"


using namespace std;

class Solution {
    map<string, NurseSolution *> nurses;
    //matrix Weeks/Days/Types
    vector< vector< Turn *>> turns;

public:
    Solution(WeekData &weekData);

    const map<string, NurseSolution *> &getNurses() const;

    const vector< vector< Turn *>> &getTurns() const;

    friend ostream& operator<< (ostream& stream, const Solution& solution){
        for(auto const &nurse : solution.getNurses())
        {
            cout << nurse.second->getNurse()->getId() << " has: ";
            for(Turn* turn : nurse.second->getTurns())
            {
                cout << turn->getShiftType()->getId() << "/" << turn->getSkill() << "/" << turn->getDay() << ",";
            }
            cout << endl;
        }

        return stream;
    };

    void randomizeSolution();
};


#endif //NRS_SOLUTION_H
