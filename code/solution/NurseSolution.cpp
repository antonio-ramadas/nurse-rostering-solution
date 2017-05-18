//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include <iostream>
#include "NurseSolution.h"

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
    return all_of(begin(turns), end(turns), [&](Turn* turnElem) -> bool {

        if (turnElem->getDay() - 1 == turn->getDay()) {
            return turnElem->getShiftType()->isForbidden(turn->getShiftType()->getId());
        } else if (turnElem->getDay() + 1 == turn->getDay()) {
            return turn->getShiftType()->isForbidden(turnElem->getShiftType()->getId());
        }

        return true;
    });
}

const bool NurseSolution::hasSkillToWork(const Turn *turn) const {
    return any_of(begin(nurse->getSkills()), end(nurse->getSkills()), [&](string skill) {
        return nurse->hasSkill(skill);
    });
}


