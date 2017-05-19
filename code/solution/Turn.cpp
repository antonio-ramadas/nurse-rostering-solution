//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include <iostream>
#include "Turn.h"

Turn::Turn(const int day, const string &skill, const ShiftType *shiftType) : day(day), shiftType(shiftType), skill(skill) {}

bool Turn::addNurse(NurseSolution * nurse){
    if(!exitsNurse(nurse)) {
        nurses.push_back(nurse);
        nurse->addTurn(this);
        return true;
    }
    return false;
}

bool Turn::exitsNurse(const NurseSolution *nurse) {
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
    if (!exitsNurse(nurseSolution) || !nurseSolution->turnExists(this))
        return false;

    nurses.erase(find(begin(nurses), end(nurses), nurseSolution));
    nurseSolution->removeTurn(this);

    return true;
}
