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
    int day;
public:
    Turn(int day, const ShiftType *shiftType);

    bool addNurse(NurseSolution * nurse);

    bool exitsNurse(NurseSolution * nurse);
};


#endif //NRS_TURN_H
