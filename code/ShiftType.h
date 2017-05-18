//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_SHIFTTYPE_H
#define NRS_SHIFTTYPE_H

#include <string>
#include <vector>

using namespace std;

class ShiftType {
private:
    string id;
    int minimumNumberOfConsecutiveAssignments, maximumNumberOfConsecutiveAssignments;
    vector<string> forbiddenSucceedingShiftTypes;

public:
    ShiftType() {}
    ShiftType(const string &id, const int &min, const int &max);
    void setForbidden(const vector<string> &forbiddens);

    const string &getId() const;
    const vector<string> &getForbiddenSucceedingShiftTypes() const;

    int getMinimumNumberOfConsecutiveAssignments() const;

    int getMaximumNumberOfConsecutiveAssignments() const;

    const bool isForbiddenShift(const string &shiftId) const;
};


#endif //NRS_SHIFTTYPE_H
