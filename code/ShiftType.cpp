//
// Created by António Ramadas on 02/03/2017.
//

#include <iostream>
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

int ShiftType::getMinimumNumberOfConsecutiveAssignments() const {
    return minimumNumberOfConsecutiveAssignments;
}

int ShiftType::getMaximumNumberOfConsecutiveAssignments() const {
    return maximumNumberOfConsecutiveAssignments;
}

const bool ShiftType::isForbiddenShift(const string &shiftId) const {
    bool ret = any_of(begin(forbiddenSucceedingShiftTypes), end(forbiddenSucceedingShiftTypes), [&](string shift) {
        return shift == shiftId;
    });

    cout << " (" << ret << " = ";

    for (string forbid : forbiddenSucceedingShiftTypes)
        cout << forbid << ",";

    cout << ") ";

    return ret;
}
