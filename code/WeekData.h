//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_WEEKDATA_H
#define NRS_WEEKDATA_H

#include "Requirement.h"
#include "Exception.h"
#include "Reader.h"
#include "ShiftOffRequest.h"

#include <string>
#include <vector>

using namespace std;

#define NUMBER_DAYS_OF_THE_WEEK 7

class WeekData {
private:
    string scenario;
    vector<ShiftOffRequest> shiftOffRequests;
    int numberOfShifts, numberOfSkills;

    //matrix[NSkills][NShifts][NDays]
    vector<vector<vector<DayRequirement *> > > requirements = {{{nullptr}}};

public:
    WeekData(){};

    WeekData(const string &path, int numberOfShifts, int numberOfSkills);

    void parseRequirements(const json &requirements);

    void parseShiftOffRequests(const json &j_arg);

    const vector<vector<vector<DayRequirement *> > >& getRequirements() const;
};


#endif //NRS_WEEKDATA_H
