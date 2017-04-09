//
// Created by António Ramadas on 02/03/2017.
//

#include "History.h"

History::History(int numberOfAssignments, int numberOfWorkingWeekends, int numberOfConsecutiveAssignments,
                 int numberOfConsecutiveWorkingDays, int numberOfConsecutiveDaysOff,
                 const string &lastAssignedShiftType) : numberOfAssignments(numberOfAssignments),
                                                        numberOfWorkingWeekends(numberOfWorkingWeekends),
                                                        numberOfConsecutiveAssignments(numberOfConsecutiveAssignments),
                                                        numberOfConsecutiveWorkingDays(numberOfConsecutiveWorkingDays),
                                                        numberOfConsecutiveDaysOff(numberOfConsecutiveDaysOff),
                                                        lastAssignedShiftType(lastAssignedShiftType) {}


History::History() : History(0,0,0,0,0,"") {}

int History::getNumberOfAssignments() const {
    return numberOfAssignments;
}

void History::setNumberOfAssignments(int numberOfAssignments) {
    History::numberOfAssignments = numberOfAssignments;
}

int History::getNumberOfWorkingWeekends() const {
    return numberOfWorkingWeekends;
}

void History::setNumberOfWorkingWeekends(int numberOfWorkingWeekends) {
    History::numberOfWorkingWeekends = numberOfWorkingWeekends;
}

int History::getNumberOfConsecutiveAssignments() const {
    return numberOfConsecutiveAssignments;
}

void History::setNumberOfConsecutiveAssignments(int numberOfConsecutiveAssignments) {
    History::numberOfConsecutiveAssignments = numberOfConsecutiveAssignments;
}

int History::getNumberOfConsecutiveWorkingDays() const {
    return numberOfConsecutiveWorkingDays;
}

void History::setNumberOfConsecutiveWorkingDays(int numberOfConsecutiveWorkingDays) {
    History::numberOfConsecutiveWorkingDays = numberOfConsecutiveWorkingDays;
}

int History::getNumberOfConsecutiveDaysOff() const {
    return numberOfConsecutiveDaysOff;
}

void History::setNumberOfConsecutiveDaysOff(int numberOfConsecutiveDaysOff) {
    History::numberOfConsecutiveDaysOff = numberOfConsecutiveDaysOff;
}

const string &History::getLastAssignedShiftType() const {
    return lastAssignedShiftType;
}

void History::setLastAssignedShiftType(const string &lastAssignedShiftType) {
    History::lastAssignedShiftType = lastAssignedShiftType;
}
