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

class WeekData {
private:
    string scenario;
    vector<Requirement> requirements;
    vector<ShiftOffRequest> shiftOffRequests;

public:
    WeekData(const string &path);

    void parseRequirements(const json &requirements);

    void parseShiftOffRequests(const json &j_arg);
};


#endif //NRS_WEEKDATA_H
