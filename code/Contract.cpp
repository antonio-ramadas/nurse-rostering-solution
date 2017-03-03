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
    this->completeWeekends = completeWeekends;
}