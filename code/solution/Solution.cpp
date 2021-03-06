//
// Created by F0lha on 16/05/2017.
//

#include <chrono>
#include "Solution.h"

Solution::Solution() {
    this->createNursesAndTurns();
}

void Solution::createNursesAndTurns() {
    //create list of nurses with solution
    for (const Nurse &sce_nurses : Scenario::getInstance()->getNurses())
        nurses.insert(make_pair(sce_nurses.getId(),new NurseSolution(&sce_nurses)));

    using req_map = unordered_map<string, unordered_map<ShiftType*, vector<DayRequirement*>>>;

    //hardcoded size of week
    for(int j = 0; j < 7; j++) {
        vector<Turn *> shifts;

        for (pair<string,ShiftType> const &shift :  Scenario::getInstance()->getShifts()) {
            ShiftType* shiftType = new ShiftType(shift.second.getId(),shift.second.getMinimumNumberOfConsecutiveAssignments(),shift.second.getMaximumNumberOfConsecutiveAssignments());
            shiftType->setForbidden(shift.second.getForbiddenSucceedingShiftTypes());
            for(string skill : Scenario::getInstance()->getSkills()) {
                Turn *turn = new Turn(j, skill, shiftType);
                shifts.push_back(turn);
            }
        }
        turns.push_back(shifts);
    }
}



const map<string, NurseSolution *> &Solution::getNurses() const {
    return nurses;
}

const vector<vector<Turn *>> &Solution::getTurns() const {
    return turns;
}

void Solution::populateSolution(Solution *(*algorithm)(Solution *)){
    while(algorithm(this) == nullptr)
    {
        this->resetSolution();
    }
}

Solution::~Solution() {
    this->deleteNursesAndTurns();
}

void Solution::deleteNursesAndTurns() {
    for(vector<Turn*> day : turns)
        for(Turn* turn : day)
            delete turn;
    for(auto const &nurse: nurses)
        delete nurse.second;

    nurses.clear();
    turns.clear();
}

const bool Solution::assignNurseToTurn(NurseSolution *nurseSolution, Turn *turn) {

    if (!nurseSolution->canWork(turn))
        return false;

    turn->addNurse(nurseSolution);

    return true;
}

void Solution::resetSolution() {
    this->deleteNursesAndTurns();
    this->createNursesAndTurns();
}

const bool Solution::removeNurseFromTurn(NurseSolution *nurseSolution, Turn *turn) {
    return turn->removeTurn(nurseSolution);
}

const bool Solution::removeAndAssignNurseTurns(NurseSolution *nurseSolution, Turn *turnToRemove, Turn *turnToAssign) {
    return removeNurseFromTurn(nurseSolution, turnToRemove) && assignNurseToTurn(nurseSolution, turnToAssign);
}

const bool Solution::atomicSwitchNurseTurns(NurseSolution *ns1, Turn *t1, NurseSolution *ns2, Turn *t2) {
    if (canSwitch(ns1, t1, t2) && canSwitch(ns2, t2, t1)) {
        if( removeAndAssignNurseTurns(ns1, t1, t2) && removeAndAssignNurseTurns(ns2, t2, t1)) {
            ns1->sortTurns();
            ns2->sortTurns();

            return true;
        }
    }

    return false;
}

const bool Solution::canSwitch(NurseSolution *nurseSolution, Turn *turnToRemove, Turn *turnToAssign) {
    return nurseSolution->hasTurn(turnToRemove) && nurseSolution->canWork(turnToAssign, turnToRemove);
}
