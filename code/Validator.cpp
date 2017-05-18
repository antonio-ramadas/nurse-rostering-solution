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

unsigned int Validator::constraintS1(const Solution &solution) {

    unsigned int sum = 0;

    for(vector<Turn *> day : solution.getTurns())
        for(Turn * turn : day){
            int nNurses = turn->getNurses().size();
            int optimal = Scenario::getInstance()->getWeekData().getRequirements().at(turn->getSkill()).at(turn->getShiftType()->getId()).at(turn->getDay())->getOptimalCoverage();
            if(nNurses < optimal)
                sum += 30 * (optimal - nNurses);
        }
    return sum;
}

unsigned int Validator::constraintS2(const Solution &solution){

    int sum = 0;

    for(auto const &nurse : solution.getNurses())
        {
            Contract contract = Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract());

            int numberOfConsecutiveAssignments = nurse.second->getNurse()->getHistory().getNumberOfConsecutiveAssignments();

            int numberOfConsecutiveWorkingDays = nurse.second->getNurse()->getHistory().getNumberOfConsecutiveWorkingDays();

            string lastShift = nurse.second->getNurse()->getHistory().getLastAssignedShiftType();

            int day = -1;

            //iterate turns

            for(Turn * turn : nurse.second->getTurns())
            {
                if(lastShift == "None")
                    numberOfConsecutiveWorkingDays = 1;
                //if it stops being consecutive working days
                else if(turn->getDay() != day + 1) {
                    if (numberOfConsecutiveWorkingDays < contract.getMinimumNumberOfConsecutiveWorkingDays())
                        sum += 30 * (contract.getMinimumNumberOfConsecutiveWorkingDays() - numberOfConsecutiveWorkingDays);
                    else if (numberOfConsecutiveWorkingDays > contract.getMaximumNumberOfConsecutiveWorkingDays())
                        sum += 30 * (numberOfConsecutiveWorkingDays - contract.getMinimumNumberOfConsecutiveWorkingDays());
                    numberOfConsecutiveWorkingDays = 1;
                }
                else
                    numberOfConsecutiveWorkingDays++;

                if(lastShift == "None")
                    numberOfConsecutiveAssignments = 1;
                else if(lastShift != turn->getShiftType()->getId()) {

                    if (numberOfConsecutiveAssignments < Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId()).getMinimumNumberOfConsecutiveAssignments())
                        sum += 15 * (Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId()).getMinimumNumberOfConsecutiveAssignments() - numberOfConsecutiveAssignments);
                    else if (numberOfConsecutiveWorkingDays > Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId()).getMaximumNumberOfConsecutiveAssignments())
                        sum += 15 * (numberOfConsecutiveAssignments - Scenario::getInstance()->getShifts().at(turn->getShiftType()->getId()).getMaximumNumberOfConsecutiveAssignments());

                    numberOfConsecutiveAssignments = 1;
                }
                else numberOfConsecutiveAssignments++;

                lastShift = turn->getShiftType()->getId();
                day = turn->getDay();
            }
        }
    return sum;
}
unsigned int Validator::constraintS3(const Solution &solution) {

    unsigned int sum = 0;

    for(auto const &nurse : solution.getNurses())
    {
        int numberOfConsecutiveDaysOff = nurse.second->getNurse()->getHistory().getNumberOfConsecutiveDaysOff();

        int lastDay = - (numberOfConsecutiveDaysOff + 1);

        for(Turn * turn : nurse.second->getTurns())
        {
            int currentDay = turn->getDay();

            int CDays = currentDay - (lastDay + 1);

            if(CDays < Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getMinimumNumberOfConsecutiveDaysOff())
                sum += 30 * (Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getMinimumNumberOfConsecutiveDaysOff() - CDays);
            else if (CDays > Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getMaximumNumberOfConsecutiveDaysOff())
                sum += 30 * (CDays - Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getMaximumNumberOfConsecutiveDaysOff());

            lastDay = turn->getDay();
        }
    }

    return sum;
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

unsigned int Validator::constraintS5(const Solution &solution) {

    unsigned int sum = 0;

    for(auto const &nurse : solution.getNurses())
        if(Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getCompleteWeekends())
            {
                if(nurseWorkingWeekEnd(nurse.second))
                    sum += 30;
            }
    return sum;
}

unsigned int Validator::constraintS6(const Solution &solution){

    unsigned int sum = 0;

    for(auto const &nurse : solution.getNurses())
    {
        int totalAssignments = nurse.second->getNurse()->getHistory().getNumberOfAssignments();
        totalAssignments += nurse.second->getTurns().size();
        Contract contract = Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract());
        if(totalAssignments > contract.getMaximumNumberOfAssignments())
            sum += 20 * totalAssignments-contract.getMaximumNumberOfAssignments();
        else if (totalAssignments < contract.getMinimumNumberOfAssignments())
            sum += 20 * contract.getMinimumNumberOfAssignments() - totalAssignments;
    }
    return  sum;
}

bool Validator::nurseWorkingWeekEnd(NurseSolution *nurse){

    vector<Turn *> turns = nurse->getTurns();
    if(turns.size() > 1)
    {
        if(turns[turns.size() - 1]->getDay() == 6)
            if(turns[turns.size() - 2]->getDay() != 5)
                return false;
        if(turns[turns.size() - 1]->getDay() == 5)
            return false;
    }
    else if(turns.size() == 1) {
        if (turns[0]->getDay() == 6 || turns[0]->getDay() == 5)
            return false;
    }

    return true;
}


unsigned int Validator::constraintS7(const Solution &solution){

    unsigned int sum = 0;

    for(auto const &nurse : solution.getNurses())
    {
        int numberOfWorkingWeekends = nurse.second->getNurse()->getHistory().getNumberOfWorkingWeekends();


        if(nurse.second->getTurns().size() > 0)
            if(nurse.second->getTurns()[nurse.second->getTurns().size() - 1]->getDay() == 6 || nurse.second->getTurns()[nurse.second->getTurns().size() - 1]->getDay() == 5)
                numberOfWorkingWeekends++;

        if(numberOfWorkingWeekends > Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getMaximumNumberOfWorkingWeekends())
            sum += 30 * (numberOfWorkingWeekends - Scenario::getInstance()->getContract(nurse.second->getNurse()->getContract()).getMaximumNumberOfWorkingWeekends());

    }
    return sum;
}

unsigned int Validator::evaluateSolution(const Solution &solution){

    unsigned int sum = 0;

    //sum += constraintS1(solution);
    sum += constraintS2(solution);
    sum += constraintS3(solution);
    sum += constraintS4(solution);
    sum += constraintS5(solution);
    sum += constraintS6(solution);
    sum += constraintS7(solution);

    return sum;

}