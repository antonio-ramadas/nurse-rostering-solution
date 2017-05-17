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

bool Validator::constraintH3(const Solution &solution) {
    vector<NurseSolution *> nurses = solution.getNurses();
    for(NurseSolution * nurse : nurses)
    {
        vector<Turn *> turns = nurse->getTurns();

        string lastShiftString = nurse->getNurse()->getHistory().getLastAssignedShiftType();

        ShiftType lastShift = Scenario::getInstance()->getShifts().at(lastShiftString);

        for(Turn * turn : turns){
            if(find(lastShift.getForbiddenSucceedingShiftTypes().begin(), lastShift.getForbiddenSucceedingShiftTypes().end(), turn->getShiftType()->getId()) != lastShift.getForbiddenSucceedingShiftTypes().end())
                lastShift = Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId());
            else return false;
        }
    }
    return true;
}
