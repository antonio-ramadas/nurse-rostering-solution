//
// Created by António Ramadas on 02/03/2017.
//

#include "WeekData.h"

WeekData::WeekData(const string &path) {
    json j;

    try {
        j = Reader::ReadJSONFile(path);
    } catch (Exception exception) {
        exception.printErr();
        return;
    }

    scenario = j["scenario"];

    parseRequirements(j);

    parseShiftOffRequests(j);
}

void WeekData::parseRequirements(json j_arg) {
    json requirements_json = j_arg["requirements"];

    for (json j : requirements_json) {
        requirements.push_back(Requirement(j["shiftType"], j["skill"], j));
    }
}

void WeekData::parseShiftOffRequests(json j_arg) {
    json shiftOffRequests_json = j_arg["shiftOffRequests"];

    for (json j : shiftOffRequests_json) {
        shiftOffRequests.push_back(ShiftOffRequest(j["nurse"], j["shiftType"], j["day"]));
    }
}
