//
// Created by António Ramadas on 08/04/2017.
//

#include "ShiftOffRequest.h"

ShiftOffRequest::ShiftOffRequest(const string &nurse, const string &shiftType, const string &day) : nurse(nurse),
                                                                                                    shiftType(
                                                                                                            shiftType),
                                                                                                    day(day) {}

const string &ShiftOffRequest::getNurse() const {
    return nurse;
}

const string &ShiftOffRequest::getShiftType() const {
    return shiftType;
}

const string &ShiftOffRequest::getDay() const {
    return day;
}
