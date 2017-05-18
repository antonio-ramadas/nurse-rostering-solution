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

        for(Turn * turn : turns) {
            if(lastDay != turn->getDay())
                lastDay = turn->getDay();
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
            else if(find(lastShift.getForbiddenSucceedingShiftTypes().begin(), lastShift.getForbiddenSucceedingShiftTypes().end(), turn->getShiftType()->getId()) == lastShift.getForbiddenSucceedingShiftTypes().end()
               || lastDay != (turn->getDay() - 1)){
                lastShift = Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId());
                lastDay = turn->getDay();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
