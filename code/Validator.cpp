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

        for(int current = 0; current < turns.size(); current++) {
            if(lastDay != current)
                lastDay = current;
            else return false;
        }
    }
    return true;
}

bool Validator::constraintH2(const Solution &solution) {

    using req_map = unordered_map<string, unordered_map<ShiftType*, vector<DayRequirement*>>>;

    const req_map &requirements = Scenario::getInstance()->getWeekData().getRequirements();

    for (unsigned int day = 0; day < solution.getTurns().size(); day++)
        for (Turn *turn : solution.getTurns().at(day))
            if (requirements.at(turn->getSkill()).at(const_cast<ShiftType*>(turn->getShiftType())).at(day)->getMinimumCoverage() < turn->getNurses().size())
                return false;

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
