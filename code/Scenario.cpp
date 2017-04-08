//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"

Scenario::Scenario(const string &path) {
    // read a JSON file
    json j;

    try {
        j = Parser::ReadJSONFile(path);
    } catch (Exception exception) {
        exception.printErr();
        return;
    }

    id = j["id"];
    numberOfWeeks = j["numberOfWeeks"];
    skills = j["skills"].get<vector<string> >();

    parseShiftTypes(j);

    parseForbiddenShiftTypeSuccessions(j);

    parseContracts(j);

    parseNurses(j);
}

void Scenario::parseNurses(const json &j) {
    for (json nurse : j["nurses"])
        nurses.push_back(Nurse(nurse["id"],
                               nurse["contract"],
                               nurse["skills"]));
}

void Scenario::parseContracts(const json &j) {
    for (json contract : j["contracts"])
        contracts.push_back(Contract(contract["id"],
                                     contract["minimumNumberOfAssignments"],
                                     contract["maximumNumberOfAssignments"],
                                     contract["minimumNumberOfConsecutiveWorkingDays"],
                                     contract["maximumNumberOfConsecutiveWorkingDays"],
                                     contract["minimumNumberOfConsecutiveDaysOff"],
                                     contract["maximumNumberOfConsecutiveDaysOff"],
                                     contract["maximumNumberOfWorkingWeekends"],
                                     contract["completeWeekends"]));
}

void Scenario::parseForbiddenShiftTypeSuccessions(const json &j) {
    for (json forbidden : j["forbiddenShiftTypeSuccessions"]) {
        vector<ShiftType>::iterator it = find_if(shifts.begin(), shifts.end(),
                                                 [&forbidden](ShiftType shift) -> bool {
                                                     return forbidden["precedingShiftType"] == shift.getId();
                                                 });

        it->setForbidden(forbidden["succeedingShiftTypes"]);
    }
}

void Scenario::parseShiftTypes(const json &j) {
    for (json shift : j["shiftTypes"])
        shifts.push_back(ShiftType(shift["id"],
                                     shift["minimumNumberOfConsecutiveAssignments"],
                                     shift["maximumNumberOfConsecutiveAssignments"]));
}