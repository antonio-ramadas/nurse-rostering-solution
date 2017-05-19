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

    bool randomIteration();

    void createNursesAndTurns();

    void deleteNursesAndTurns();
  
    const void removeAndAssignNurseTurns(NurseSolution *nurseSolution, Turn *turnToRemove, Turn *turnToAssign);

    const bool canSwitch(NurseSolution *nurseSolution, Turn *turnToRemove, Turn *turnToAssign);
  

public:
    Solution();

    virtual ~Solution();

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

    void resetSolution();
  
    const bool assignNurseToTurn(NurseSolution *nurseSolution, Turn *turn);

    const bool removeNurseFromTurn(NurseSolution *nurseSolution, Turn *turn);

    const bool atomicSwitchNurseTurns(NurseSolution *ns1, Turn *t1, NurseSolution *ns2, Turn *t2);
  
};


#endif //NRS_SOLUTION_H
