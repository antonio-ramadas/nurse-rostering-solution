//
// Created by F0lha on 20/04/2017.
//

#ifndef NRS_WEEKASSIGNEMENT_H
#define NRS_WEEKASSIGNEMENT_H

#include <exception>
#include <string>
#include "ShiftType.h"
#include "Nurse.h"
#include "WeekData.h"
#include "Week.h"

using namespace std;

class WeekAssignment {
private:
     vector<ShiftType*> shiftTypes;
     int numberOfWeeks;
     //Vector of Nurses by Shift by Day by Week
     vector<Week*> weeks;
public:
    WeekAssignment(vector<ShiftType*> shiftTypes, int numberOfWeeks , WeekData weekData);

    int getNumberOfWeeks() const {
        return numberOfWeeks;
    }

};

#endif //NRS_WEEKASSIGNEMENT_H
