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

        int lastDay;
        ShiftType lastShift;

        try {

            lastShift = Scenario::getInstance()->getShifts().at(lastShiftString);
            lastDay = -1;
        }
        catch(const std::exception& e)
        {
            lastDay = -2;
        }

        for(Turn * turn : turns){
            if(lastDay == -2) {
                lastShift = Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId());
                lastDay = turn->getDay();
            }
            else if(find(lastShift.getForbiddenSucceedingShiftTypes().begin(), lastShift.getForbiddenSucceedingShiftTypes().end(), turn->getShiftType()->getId()) != lastShift.getForbiddenSucceedingShiftTypes().end()
               || lastDay != turn->getDay() - 1){
                cerr << "test:" << turn->getShiftType()->getId();
                lastShift = Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId());
                lastDay = turn->getDay();
            }
            else return false;
        }
    }
    return true;
}
