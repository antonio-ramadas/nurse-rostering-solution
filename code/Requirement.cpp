//
// Created by António Ramadas on 08/04/2017.
//

#include "Requirement.h"
#include "Scenario.h"

Requirement::Requirement(string shiftType, string skill, const json &daysRequirements) {
    this->shiftType = shiftType;
    this->skill = skill;

    const vector<string> DaysOfTheWeekVector = Scenario::getInstance()->getDaysOfTheWeekVector();

    string requirementTxt = "requirementOn";

    for (int i = 0; i < DaysOfTheWeekVector.size(); i++) {
        json j = daysRequirements[requirementTxt + DaysOfTheWeekVector.at(i)];
        days.push_back(DayRequirement(
                j["minimum"].get<int>(),
                j["optimal"].get<int>()));
    }
}

const string &Requirement::getShiftType() const {
    return shiftType;
}

void Requirement::setShiftType(const string &shiftType) {
    Requirement::shiftType = shiftType;
}

const string &Requirement::getSkill() const {
    return skill;
}

void Requirement::setSkill(const string &skill) {
    Requirement::skill = skill;
}

const vector<DayRequirement, allocator<DayRequirement>> &Requirement::getDays() const {
    return days;
}

void Requirement::setDays(const vector<DayRequirement, allocator<DayRequirement>> &days) {
    Requirement::days = days;
}
