//
// Created by António Ramadas on 08/04/2017.
//

#ifndef NRS_REQUIREMENT_H
#define NRS_REQUIREMENT_H

#include "DayRequirement.h"
#include "json.hpp"

#include <string>

using json = nlohmann::json;

using namespace std;

class Requirement {
private:
    string shiftType, skill;
    vector<DayRequirement> days;
public:
    const string &getShiftType() const;

    void setShiftType(const string &shiftType);

    const string &getSkill() const;

    void setSkill(const string &skill);

    const vector<DayRequirement, allocator<DayRequirement>> &getDays() const;

    void setDays(const vector<DayRequirement, allocator<DayRequirement>> &days);

public:
    Requirement(string shiftType, string skill, const json &daysRequirements);
};


#endif //NRS_REQUIREMENT_H
