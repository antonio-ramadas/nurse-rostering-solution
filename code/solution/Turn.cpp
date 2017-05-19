//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include <iostream>
#include "Turn.h"

unsigned int Turn::CURRENT_ID = 0;

Turn::Turn(const int day, const string &skill, const ShiftType *shiftType) : day(day), shiftType(shiftType), skill(skill) {
    id = CURRENT_ID++;
}

bool Turn::addNurse(NurseSolution * nurse){
    if(!hasNurse(nurse)) {
        nurses.push_back(nurse);
        nurse->addTurn(this);
        return true;
    }
    return false;
}

bool Turn::hasNurse(const NurseSolution *nurse) {
    return find(nurses.begin(), nurses.end(),nurse)!=nurses.end();
}

const vector<NurseSolution *, allocator<NurseSolution *>> &Turn::getNurses() const {
    return nurses;
}

const ShiftType* Turn::getShiftType() const {
    return shiftType;
}

const string &Turn::getSkill() const {
    return skill;
}

const int Turn::getDay() const {
    return day;
}

const bool Turn::removeTurn(NurseSolution *nurseSolution) {
    if (!hasNurse(nurseSolution) || !nurseSolution->hasTurn(this))
        return false;

    nurses.erase(find(begin(nurses), end(nurses), nurseSolution));
    nurseSolution->removeTurn(this);

    return true;
}

unsigned int Turn::getId() const {
    return id;
}
