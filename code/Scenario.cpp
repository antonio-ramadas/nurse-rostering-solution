//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"

Scenario* Scenario::scenario = nullptr;

void Scenario::parseScenario(const string &path) {
    // read a JSON file
    json j;

    try {
        j = Reader::ReadJSONFile(path);
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
        contracts.insert(pair<string,Contract> (contract["id"].get<string>(), Contract(contract["id"],
                                     contract["minimumNumberOfAssignments"],
                                     contract["maximumNumberOfAssignments"],
                                     contract["minimumNumberOfConsecutiveWorkingDays"],
                                     contract["maximumNumberOfConsecutiveWorkingDays"],
                                     contract["minimumNumberOfConsecutiveDaysOff"],
                                     contract["maximumNumberOfConsecutiveDaysOff"],
                                     contract["maximumNumberOfWorkingWeekends"],
                                     contract["completeWeekends"])));
}

void Scenario::parseForbiddenShiftTypeSuccessions(const json &j) {
    for (json forbidden : j["forbiddenShiftTypeSuccessions"]) {
        map<string,ShiftType>::iterator it = find_if(shifts.begin(), shifts.end(),
                                                 [&forbidden](const std::pair<string, ShiftType> & shift) -> bool {
                                                     return forbidden["precedingShiftType"] == shift.second.getId();
                                                 });

        it->second.setForbidden(forbidden["succeedingShiftTypes"]);
    }
}

void Scenario::parseShiftTypes(const json &j) {
    for (json shift : j["shiftTypes"]) {
        shifts.insert(pair<string, ShiftType>(shift["id"].get<string>(), ShiftType(shift["id"].get<string>(),
                                                                     shift["minimumNumberOfConsecutiveAssignments"],
                                                                     shift["maximumNumberOfConsecutiveAssignments"])));
    }
}

void Scenario::parseHistory(const string &path) {
     // read a JSON file
    json j;

    try {
        j = Reader::ReadJSONFile(path);
    } catch (Exception exception) {
        exception.printErr();
        return;
    }

    //Useless information, I think...
    //int week = j["week"];
    //int scenario = j["scenario"];

    json history = j["nurseHistory"];

    for (json nHistory : history) {
        try {
            History hist(nHistory["numberOfAssignments"],
                         nHistory["numberOfWorkingWeekends"],
                         nHistory["numberOfConsecutiveAssignments"],
                         nHistory["numberOfConsecutiveWorkingDays"],
                         nHistory["numberOfConsecutiveDaysOff"],
                         nHistory["lastAssignedShiftType"]
            );

            findNurse(nHistory["nurse"]).setHistory(hist);
        } catch (Exception e) {
            e.printErr();
            return;
        }
    }
}

Nurse & Scenario::findNurse(const string &name) {
    for (int i = 0; i < nurses.size(); i++)
        if (nurses.at(i).getId() == name)
            return nurses.at(i);

    throw Exception(ExceptionsEnum::NurseNotFound, "Nurse " + name + " not found");
}

const map<string,ShiftType> &Scenario::getShifts() const {
    return shifts;
}

const vector<string> &Scenario::getSkills() const {
    return skills;
}

const vector<Nurse> &Scenario::getNurses() const {
    return nurses;
}

int Scenario::getNumberOfWeeks() const {
    return numberOfWeeks;
}

Scenario::Scenario() {

}

Scenario* Scenario::getInstance() {
    if (scenario == nullptr)
        scenario = new Scenario();

    return scenario;
}
