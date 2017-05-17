//
// Created by António Ramadas on 02/03/2017.
//

#include "WeekData.h"
#include "Scenario.h"

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

    string requirementTxt = "requirementOn";

    const vector<string> DaysOfTheWeekVector {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (json requirement_json : requirements_json) {

        const string skill = requirement_json["skill"];
        const string shiftType_str = requirement_json["shiftType"];

        if (requirements.find(skill) == end(requirements))
            requirements.insert(
                make_pair(
                        skill,
                        unordered_map<ShiftType*, vector<DayRequirement*>>()
                ));

        unordered_map<ShiftType*, vector<DayRequirement*>> &shifts = requirements.find(skill)->second;
        ShiftType &currentShiftType = Scenario::getInstance()->getShifts().find(shiftType_str)->second;

        if (shifts.find(&currentShiftType) == end(shifts))
            shifts.insert(
                    make_pair(
                            &currentShiftType,
                            vector<DayRequirement*>()
                    ));

        vector<DayRequirement*> &days = shifts.find(&currentShiftType)->second;

        for (int i = 0; i < NUMBER_DAYS_OF_THE_WEEK; i++) {
            json js = requirement_json[requirementTxt + DaysOfTheWeekVector.at(i)];

            days.push_back(new DayRequirement(js["minimum"], js["optimal"]));
        }
    }
}

void WeekData::parseShiftOffRequests(const json &j_arg) {
    json shiftOffRequests_json = j_arg["shiftOffRequests"];

    for (json j : shiftOffRequests_json) {
        shiftOffRequests.push_back(ShiftOffRequest(j["nurse"], j["shiftType"], j["day"]));
    }
}

const unordered_map<string, unordered_map<ShiftType*, vector<DayRequirement*>>> &WeekData::getRequirements() const {
    return requirements;
}
