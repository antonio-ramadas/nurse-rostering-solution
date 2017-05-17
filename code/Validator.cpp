//
// Created by F0lha on 16/05/2017.
//

#include "Validator.h"

bool Validator::constraintH1(const Solution &solution) {
    vector<NurseSolution *> nurses = solution.getNurses();
    for(NurseSolution * nurse : nurses)
    {
        vector<Turn *> turns = nurse->getTurns();

        int lastDay = -1;

        for(Turn * turn : turns){
            int current = turn->getDay();
            if(lastDay != current)
                lastDay = current;
            else return false;
        }
    }
    return true;
}

/*bool Validator::constraintH2(const Solution &solution) {

    unordered_map<string, int> assignments;

    for (ShiftType shiftType : Scenario::getInstance()->getShifts())
        assignments.insert(make_pair(shiftType.getId(), 0));

    for (const vector<Turn*> &days: solution.getTurns())
        for (const Turn *turn : days) {

            string shiftId = turn->getShiftType()->getId();


        }

    return true;
}*/
bool Validator::constraintH3(const Solution &solution) {
    vector<NurseSolution *> nurses = solution.getNurses();
    for(NurseSolution * nurse : nurses)
    {
        vector<Turn *> turns = nurse->getTurns();

        string lastShiftString = nurse->getNurse()->getHistory().getLastAssignedShiftType();



        for(Turn * turn : turns){
            int current = turn->getDay();
            if(lastDay != current)
                lastDay = current;
            else return false;
        }
    }
    return true;
}
