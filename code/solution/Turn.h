//
// Created by F0lha on 16/05/2017.
//

#ifndef NRS_TURN_H
#define NRS_TURN_H


#include "../ShiftType.h"
#include "NurseSolution.h"


using namespace std;

class NurseSolution;

class Turn {

    vector<NurseSolution *> nurses;
    const ShiftType* shiftType;
    const string skill;
public:
    Turn(const string &skill, const ShiftType *shiftType);

    bool addNurse(NurseSolution * nurse);

    bool exitsNurse(NurseSolution * nurse);

    const vector<NurseSolution *, allocator<NurseSolution *>> &getNurses() const;

    const ShiftType *getShiftType() const;
};


#endif //NRS_TURN_H
