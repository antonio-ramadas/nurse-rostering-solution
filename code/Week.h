//
// Created by F0lha on 20/04/2017.
//

#ifndef NRS_WEEK_H
#define NRS_WEEK_H


#include "Day.h"
#include "ShiftType.h"

class Week {
private:
    vector<Day*> days;
public:
    Week(vector<ShiftType*> shiftTypes);
};


#endif //NRS_WEEK_H
