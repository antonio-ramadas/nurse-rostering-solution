//
// Created by António Ramadas on 08/04/2017.
//

#ifndef NRS_SHIFTOFFREQUEST_H
#define NRS_SHIFTOFFREQUEST_H

#include <string>

using namespace std;

class ShiftOffRequest {
public:
    ShiftOffRequest(const string &nurse, const string &shiftType, const string &day);

private:
    //be careful, shiftType may be "Any"
    string nurse, shiftType, day;
public:
    const string &getNurse() const;

    const string &getShiftType() const;

    const string &getDay() const;

    bool operator== (const ShiftOffRequest& shiftOffRequest) {
        return nurse ==shiftOffRequest.getNurse() ||  day == shiftOffRequest.getDay() || shiftType ==shiftOffRequest.getShiftType();
    };
};


#endif //NRS_SHIFTOFFREQUEST_H
