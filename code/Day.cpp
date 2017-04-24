//
// Created by F0lha on 20/04/2017.
//

#include "Day.h"

Day::Day(vector<ShiftType*> shiftTypes) {

    for(int i = 0; i < shiftTypes.size(); i++)
        this->shifts.push_back((new Shift()));
}
