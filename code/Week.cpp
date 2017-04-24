//
// Created by F0lha on 20/04/2017.
//

#include "Week.h"

#define NUMBEROFDAYS 5

Week::Week(vector<ShiftType*> shiftTypes){
    for(int i = 0; i < NUMBEROFDAYS; i++)
        this->days.push_back((new Day(shiftTypes)));
}
