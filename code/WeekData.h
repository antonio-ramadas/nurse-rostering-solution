//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_WEEKDATA_H
#define NRS_WEEKDATA_H

#include "Requirement.h"
#include "Exception.h"
#include "Reader.h"
#include "ShiftOffRequest.h"
#include "ShiftType.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define NUMBER_DAYS_OF_THE_WEEK 7

class WeekData {
private:
    string scenario;
    vector<ShiftOffRequest> shiftOffRequests;
    int numberOfShifts, numberOfSkills;

    //matrix[NSkills][NShifts][NDays]
    unordered_map<string, unordered_map<string, vector<DayRequirement*>>> requirements;
public:
    const unordered_map<string, unordered_map<string, vector<DayRequirement*>>> &getRequirements() const;

    WeekData(){};

    WeekData(const string &path, int numberOfShifts, int numberOfSkills);

    void parseRequirements(const json &requirements);

    void parseShiftOffRequests(const json &j_arg);

    const vector<ShiftOffRequest> &getShiftOffRequests() const;

    int getMinimumCoverageRequirement(const string &skill, const string &shift, const int &day);
};


#endif //NRS_WEEKDATA_H
