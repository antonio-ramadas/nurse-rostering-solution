//
// Created by F0lha on 20/04/2017.
//

#include "Assignement.h"

WeekAssignment::WeekAssignment(vector<ShiftType*> shiftTypes, int numberOfWeeks, WeekData weekData) {

    this->shiftTypes = shiftTypes;
    this->numberOfWeeks = numberOfWeeks;

    for(int i = 0; i < numberOfWeeks; i++){
        this->weeks.push_back((new Week(shiftTypes)));
    }

}