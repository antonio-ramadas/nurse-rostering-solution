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

bool Validator::constraintH2(const Solution &solution) {

    for (const vector<vector<DayRequirement*>> &skills : Scenario::getInstance()->getWeekData().getRequirements())
        for (const vector<DayRequirement*> &shifts : skills)
            for (unsigned int day = 0; day < shifts.size(); day++) {

                vector<Turn*> turns = solution.getTurns().at(day);
                int sum = 0;

                //BUG I can't get the requirement of a specific skill and shift type in week data
                /*for (Turn* turn : turns) {
                    if (turn->getShiftType()->getId() == shifts.at(day)) {

                    }
                }*/
            }

    return true;
}

bool Validator::constraintH3(const Solution &solution) {
    vector<NurseSolution *> nurses = solution.getNurses();
    for(NurseSolution * nurse : nurses)
    {
        vector<Turn *> turns = nurse->getTurns();

        string lastShiftString = nurse->getNurse()->getHistory().getLastAssignedShiftType();

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
