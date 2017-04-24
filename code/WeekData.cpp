//
// Created by António Ramadas on 02/03/2017.
//

#include "WeekData.h"

WeekData::WeekData(const string &path, int numberOfShifts, int numberOfSkills) {
    json j;

    this->numberOfShifts = numberOfShifts;
    this->numberOfSkills = numberOfSkills;

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

void WeekData::parseRequirements(const json &j_arg) {
    json requirements_json = j_arg["requirements"];

    //matrix[NSkills][NShifts][NDays]
    string requirementTxt = "requirementOn";

    const vector<string> DaysOfTheWeekVector {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    json::iterator it = requirements_json.begin();
    for(int i = 0; i < this->numberOfSkills; i++)
        for(int j = 0; j < this->numberOfShifts; j++)
            for(int k = 0; k < NUMBER_DAYS_OF_THE_WEEK; k++){
                json j = (*it)[requirementTxt + DaysOfTheWeekVector.at(k)];
                requirements[i][j][k] = new DayRequirement(DayRequirement(
                        j["minimum"].get<int>(),
                        j["optimal"].get<int>()));
            }
}

void WeekData::parseShiftOffRequests(const json &j_arg) {
    json shiftOffRequests_json = j_arg["shiftOffRequests"];

    for (json j : shiftOffRequests_json) {
        shiftOffRequests.push_back(ShiftOffRequest(j["nurse"], j["shiftType"], j["day"]));
    }
}
