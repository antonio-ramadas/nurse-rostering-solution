//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_CONTRACT_H
#define NRS_CONTRACT_H

#include <string>

using namespace std;

class Contract {
private:
    string id;
    int minimumNumberOfAssignments,
            maximumNumberOfAssignments,
            minimumNumberOfConsecutiveWorkingDays,
            maximumNumberOfConsecutiveWorkingDays,
            minimumNumberOfConsecutiveDaysOff,
            maximumNumberOfConsecutiveDaysOff,
            maximumNumberOfWorkingWeekends;
    bool completeWeekends;
public:
    Contract (const string &id, const int &minAssignments, const int &maxAssignments, const int &minWorkingDays, const int &maxWorkingDays, const int &minDaysOff, const int &maxDaysOff, const int &WorkingWeekends, const int &completeWeekends);

    int getMinimumNumberOfAssignments() const;

    int getMaximumNumberOfAssignments() const;

    int getMinimumNumberOfConsecutiveWorkingDays() const;

    int getMaximumNumberOfConsecutiveWorkingDays() const;

    int getMinimumNumberOfConsecutiveDaysOff() const;

    int getMaximumNumberOfConsecutiveDaysOff() const;

    int getMaximumNumberOfWorkingWeekends() const;

    bool getCompleteWeekends() const;
};


#endif //NRS_CONTRACT_H
