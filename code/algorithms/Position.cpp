//
// Created by F0lha on 20/05/2017.
//

#include "Position.h"

Position::Position(int day, const ShiftType* shiftType, const string &skill) : day(day), shiftType(shiftType),
                                                                               skill(skill) {}

bool Position::positionValid(){
    return day >= 0;
}

int Position::getDay() const {
    return day;
}

const ShiftType *Position::getShiftType() const {
    return shiftType;
}

const string &Position::getSkill() const {
    return skill;
}
