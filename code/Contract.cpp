//
// Created by António Ramadas on 02/03/2017.
//

#include "Contract.h"

Contract::Contract(const string &id, const int &minAssignments, const int &maxAssignments, const int &minWorkingDays,
                   const int &maxWorkingDays, const int &minDaysOff, const int &maxDaysOff, const int &WorkingWeekends,
                   const int &completeWeekends) {
    this->id = id;
    minimumNumberOfAssignments = minAssignments;
    maximumNumberOfAssignments = maxAssignments;
    minimumNumberOfConsecutiveWorkingDays = minWorkingDays;
    maximumNumberOfConsecutiveWorkingDays = maxWorkingDays;
    minimumNumberOfConsecutiveDaysOff = minDaysOff;
    maximumNumberOfConsecutiveDaysOff = maxDaysOff;
    maximumNumberOfWorkingWeekends = WorkingWeekends;
    this->completeWeekends = completeWeekends == 1 ? true : false;
}

int Contract::getMinimumNumberOfAssignments() const {
    return minimumNumberOfAssignments;
}

int Contract::getMaximumNumberOfAssignments() const {
    return maximumNumberOfAssignments;
}

int Contract::getMinimumNumberOfConsecutiveWorkingDays() const {
    return minimumNumberOfConsecutiveWorkingDays;
}

int Contract::getMaximumNumberOfConsecutiveWorkingDays() const {
    return maximumNumberOfConsecutiveWorkingDays;
}

int Contract::getMinimumNumberOfConsecutiveDaysOff() const {
    return minimumNumberOfConsecutiveDaysOff;
}

int Contract::getMaximumNumberOfConsecutiveDaysOff() const {
    return maximumNumberOfConsecutiveDaysOff;
}

int Contract::getMaximumNumberOfWorkingWeekends() const {
    return maximumNumberOfWorkingWeekends;
}

bool Contract::getCompleteWeekends() const {
    return completeWeekends;
}
