//
// Created by F0lha on 16/05/2017.
//

#include "Validator.h"

bool Validator::constraintH1(const Solution &solution) {
    map<string, NurseSolution *> nurses = solution.getNurses();
    for(auto const &nurse : nurses)
    {
        vector<Turn *> turns = nurse.second->getTurns();

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

    using req_map = unordered_map<string, unordered_map<string, vector<DayRequirement*>>>;

    const req_map &requirements = Scenario::getInstance()->getWeekData().getRequirements();

    for (unsigned int day = 0; day < solution.getTurns().size(); day++)
        for (Turn *turn : solution.getTurns().at(day))
            if (requirements.at(turn->getSkill()).at(turn->getShiftType()->getId()).at(day)->getMinimumCoverage() > turn->getNurses().size()) {
                //cerr << "Not enough at " << turn->getShiftType()->getId() << "/" <<  day << " needed : " << requirements.at(turn->getSkill()).at(turn->getShiftType()->getId()).at(day)->getMinimumCoverage()
                  //   << " and has : " << turn->getNurses().size() << endl;
                return false;
            }

    return true;
}

bool Validator::constraintH3(const Solution &solution) {
    map<string, NurseSolution *> nurses = solution.getNurses();
    for(auto const &nurse : nurses)
    {
        vector<Turn *> turns = nurse.second->getTurns();

        string lastShiftString = nurse.second->getNurse()->getHistory().getLastAssignedShiftType();

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

unsigned int Validator::constraintS4(const Solution &solution) {

    unsigned int sum = 0;

    for(ShiftOffRequest shiftOffRequest : Scenario::getInstance()->getWeekData().getShiftOffRequests()) {

        NurseSolution *nurseSolution = solution.getNurses().at(shiftOffRequest.getNurse());
        string shiftType = shiftOffRequest.getShiftType();

        int day = Scenario::getInstance()->getDayOfWeek(shiftOffRequest.getDay());

        vector<Turn*> nurseTurns = nurseSolution->getTurns();

        for_each(begin(nurseTurns), end(nurseTurns), [&](Turn *turn) {
            if(turn->getDay() == day && (shiftType == "Any" || shiftType == turn->getShiftType()->getId()))
                sum += 10;
        });
    }

    return sum;
}

unsigned int Validator::constraintS6(const Solution &solution){
    for(NurseSolution *nurse : solution.getNurses())
    {
        int totalAssignments = nurse->getNurse()->getHistory().getNumberOfAssignments();
        totalAssignments += nurse->getTurns().size();
        Contract contract = Scenario::getInstance()->getContract(nurse->getNurse()->getContract());
        contract
    }
    return  1;
}