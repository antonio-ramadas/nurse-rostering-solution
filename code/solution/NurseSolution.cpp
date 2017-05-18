//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include <iostream>
#include "NurseSolution.h"
#include "../Scenario.h"

NurseSolution::NurseSolution(const Nurse* nurse): nurse(nurse){}

bool NurseSolution::addTurn(Turn* turn){
    if(!turnExists(turn))
    {
        turns.push_back(turn);
        return true;
    }
    return false;
}

bool NurseSolution::turnExists(Turn * turn) {
    return find(turns.begin(), turns.end(),turn)!=turns.end();
}

const vector<Turn *> &NurseSolution::getTurns() const {
    return turns;
}

const Nurse *NurseSolution::getNurse() const {
    return nurse;
}

const bool NurseSolution::canWork(const Turn *turn) {
    return isSingleAssignment(turn) && isLegalSuccession(turn) && hasSkillToWork(turn);
}

const bool NurseSolution::isSingleAssignment(const Turn *turn) const {
    return none_of(begin(turns), end(turns), [=](Turn* turnElem) {
        return turnElem->getDay() == turn->getDay();
    });
}

const bool NurseSolution::isLegalSuccession(const Turn *turn) const {
    return !hasHistoryConflict(turn) && !hasTurnConflict(turn);
}

const bool NurseSolution::hasSkillToWork(const Turn *turn) const {
    return nurse->hasSkill(turn->getSkill());
}

const bool NurseSolution::hasHistoryConflict(const Turn *pTurn) const {
    if (pTurn->getDay() != 0)
        return false;

    if (nurse->getHistory().getLastAssignedShiftType() == "None")
        return false;

    return Scenario::getInstance()->getShifts()
            .at(nurse->getHistory().getLastAssignedShiftType())
            .isForbiddenShift(pTurn->getShiftType()->getId());
}

bool NurseSolution::hasTurnConflict(const Turn *turn) const {
    bool ret = any_of(begin(turns), end(turns), [&](Turn* turnElem) -> bool {

        cout << turn->getDay() << "|" << turn->getShiftType()->getId() << " - ";
        cout << turnElem->getDay() << "|" << turnElem->getShiftType()->getId() << " -> ";

        bool result = false;
        bool enter = false;

        if (turnElem->getDay() == turn->getDay() - 1) {
            enter = true;
            result = turnElem->getShiftType()->isForbiddenShift(turn->getShiftType()->getId());
        } else if (turnElem->getDay() == turn->getDay() + 1) {
            enter = true;
            result = turn->getShiftType()->isForbiddenShift(turnElem->getShiftType()->getId());
        }

        if (enter) {
            cout << result << endl;
            return result;
        }

        cout << endl;

        return false;
    });

    cout << "result: " << ret << endl;

    return ret;
}


