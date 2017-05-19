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

bool NurseSolution::turnExists(const Turn *turn) {
    return find(turns.begin(), turns.end(),turn)!=turns.end();
}

const vector<Turn *> &NurseSolution::getTurns() const {
    return turns;
}

const Nurse *NurseSolution::getNurse() const {
    return nurse;
}

const bool NurseSolution::canWork(const Turn *turnToAssign, const Turn *turnToIgnore) {
    return isSingleAssignment(turnToAssign, turnToIgnore) && isLegalSuccession(turnToAssign, turnToIgnore) && hasSkillToWork(turnToAssign);
}

const bool NurseSolution::isSingleAssignment(const Turn *turnToCheck, const Turn *turnToIgnore) const {
    return none_of(begin(turns), end(turns), [&](Turn* turnElem) {
        if (turnToIgnore != nullptr && turnElem->getId() == turnToIgnore->getId())
            return false;
        return turnElem->getDay() == turnToCheck->getDay();
    });
}

const bool NurseSolution::isLegalSuccession(const Turn *turnToCheck, const Turn *turnToIgnore) const {
    return !hasHistoryConflict(turnToCheck) && !hasTurnConflict(turnToCheck);
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
    return any_of(begin(turns), end(turns), [&](Turn* turnElem) -> bool {

        if (turnElem->getDay() == turn->getDay() - 1) {
            return turnElem->getShiftType()->isForbiddenShift(turn->getShiftType()->getId());
        } else if (turnElem->getDay() == turn->getDay() + 1) {
            return turn->getShiftType()->isForbiddenShift(turnElem->getShiftType()->getId());
        }

        return false;
    });
}

const bool NurseSolution::removeTurn(const Turn *turn) {
    if (!turnExists(turn))
        return false;

    turns.erase(find(begin(turns), end(turns), turn));

    return true;
}
