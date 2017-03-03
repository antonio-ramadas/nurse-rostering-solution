//
// Created by António Ramadas on 02/03/2017.
//

#include "ShiftType.h"

ShiftType::ShiftType(const string &id, const int &min, const int &max) {
    this->id = id;
    minimumNumberOfConsecutiveAssignments = min;
    maximumNumberOfConsecutiveAssignments = max;
}

void ShiftType::setForbidden(const vector<string> &forbiddens) {
    forbiddenSucceedingShiftTypes = forbiddens;
}

const string &ShiftType::getId() const {
    return id;
}

const vector<string> &ShiftType::getForbiddenSucceedingShiftTypes() const {
    return forbiddenSucceedingShiftTypes;
}
