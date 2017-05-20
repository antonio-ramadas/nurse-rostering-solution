//
// Created by F0lha on 20/05/2017.
//

#ifndef NRS_POSITION_H
#define NRS_POSITION_H


#include "../ShiftType.h"

class Position {

    int day;
    const ShiftType* shiftType;
    string skill;

public:

    Position(int day, const ShiftType* shiftType, const string &skill);

    bool positionValid();

    int getDay() const;

    const ShiftType *getShiftType() const;

    const string &getSkill() const;
};


#endif //NRS_POSITION_H
