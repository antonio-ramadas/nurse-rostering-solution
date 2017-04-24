//
// Created by F0lha on 20/04/2017.
//

#ifndef NRS_DAY_H
#define NRS_DAY_H


#include "Shift.h"
#include "ShiftType.h"

class Day {
private:
    vector<Shift*> shifts;
public:
    Day(vector<ShiftType*> shiftTypes);
};


#endif //NRS_DAY_H
