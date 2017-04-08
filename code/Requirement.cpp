//
// Created by António Ramadas on 08/04/2017.
//

#include "Requirement.h"

Requirement::Requirement(string shiftType, string skill, json daysRequirements) {
    this->shiftType = shiftType;
    this->skill = skill;

    const vector<string> DaysOfTheWeekVector {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    string requirementTxt = "requirementOn";

    for (int i = 0; i < NUMBER_DAYS_OF_THE_WEEK; i++) {
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
