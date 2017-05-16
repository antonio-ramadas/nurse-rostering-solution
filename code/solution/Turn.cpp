//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include "Turn.h"

Turn::Turn(int day, const ShiftType *shiftType) : shiftType(shiftType), day(day) {}

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

int Turn::getDay() const {
    return day;
}
