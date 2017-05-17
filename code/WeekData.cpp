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

    vector<vector<vector<DayRequirement *>>> f(this->numberOfSkills, std::vector < vector <DayRequirement *>>(this->numberOfShifts, vector<DayRequirement *>(NUMBER_DAYS_OF_THE_WEEK)));

    this->requirements = f;

    scenario = j["scenario"];

    parseRequirements(j);

    parseShiftOffRequests(j);
}

void WeekData::parseRequirements(const json &j_arg) {
    json requirements_json = j_arg["requirements"];

    //matrix[NSkills][NShifts][NDays]
    string requirementTxt = "requirementOn";

    const vector<string> DaysOfTheWeekVector {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    json cenas = requirements_json.at(0);
    int c = 0;
    for(int i = 0; i < this->numberOfSkills; i++)
        for(int j = 0; j < this->numberOfShifts; j++) {
            for (int k = 0; k < DaysOfTheWeekVector.size(); k++) {

                json js = (cenas)[requirementTxt + DaysOfTheWeekVector.at(k)];

                requirements[i][j][k] = new DayRequirement(js["minimum"], js["optimal"]);
            }
            c++;
            if(c < requirements_json.size())
                cenas = requirements_json.at(c);
        }
}

void WeekData::parseShiftOffRequests(const json &j_arg) {
    json shiftOffRequests_json = j_arg["shiftOffRequests"];

    for (json j : shiftOffRequests_json) {
        shiftOffRequests.push_back(ShiftOffRequest(j["nurse"], j["shiftType"], j["day"]));
    }
}
