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

void ShiftOffRequest::setNurse(const string &nurse) {
    ShiftOffRequest::nurse = nurse;
}

const string &ShiftOffRequest::getShiftType() const {
    return shiftType;
}

void ShiftOffRequest::setShiftType(const string &shiftType) {
    ShiftOffRequest::shiftType = shiftType;
}

const string &ShiftOffRequest::getDay() const {
    return day;
}

void ShiftOffRequest::setDay(const string &day) {
    ShiftOffRequest::day = day;
}
