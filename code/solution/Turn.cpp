//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include "Turn.h"

Turn::Turn(const string &skill, const ShiftType *shiftType) : shiftType(shiftType), skill(skill) {}

bool Turn::addNurse(NurseSolution * nurse){
    if(!exitsNurse(nurse)) {
        nurses.push_back(nurse);
        nurse->addTurn(this);
        return true;
    }
    return false;
}

bool Turn::exitsNurse(NurseSolution * nurse) {
    return find(nurses.begin(), nurses.end(),nurse)!=nurses.end();
}

const vector<NurseSolution *, allocator<NurseSolution *>> &Turn::getNurses() const {
    return nurses;
}

const ShiftType *Turn::getShiftType() const {
    return shiftType;
}
