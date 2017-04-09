//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_HISTORY_H
#define NRS_HISTORY_H

#include <string>

using namespace std;

class History {
private:
    int numberOfAssignments,
            numberOfWorkingWeekends,
            numberOfConsecutiveAssignments,
            numberOfConsecutiveWorkingDays,
            numberOfConsecutiveDaysOff;
    string lastAssignedShiftType;
public:
    History();
    History(int numberOfAssignments, int numberOfWorkingWeekends, int numberOfConsecutiveAssignments,
            int numberOfConsecutiveWorkingDays, int numberOfConsecutiveDaysOff, const string &lastAssignedShiftType);


    int getNumberOfAssignments() const;

    void setNumberOfAssignments(int numberOfAssignments);

    int getNumberOfWorkingWeekends() const;

    void setNumberOfWorkingWeekends(int numberOfWorkingWeekends);

    int getNumberOfConsecutiveAssignments() const;

    void setNumberOfConsecutiveAssignments(int numberOfConsecutiveAssignments);

    int getNumberOfConsecutiveWorkingDays() const;

    void setNumberOfConsecutiveWorkingDays(int numberOfConsecutiveWorkingDays);

    int getNumberOfConsecutiveDaysOff() const;

    void setNumberOfConsecutiveDaysOff(int numberOfConsecutiveDaysOff);

    const string &getLastAssignedShiftType() const;

    void setLastAssignedShiftType(const string &lastAssignedShiftType);
};


#endif //NRS_HISTORY_H
