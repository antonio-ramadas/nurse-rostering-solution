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
    static unsigned int CURRENT_ID;
    unsigned int id;

    vector<NurseSolution *> nurses;
    const ShiftType* shiftType;
    const string skill;
    const int day;

public:
    Turn(const int day, const string &skill, const ShiftType *shiftType);

    bool addNurse(NurseSolution * nurse);

    bool hasNurse(const NurseSolution *nurse);

    const vector<NurseSolution *, allocator<NurseSolution *>> &getNurses() const;

    const ShiftType* getShiftType() const;

    const int getDay() const;

    unsigned int getId() const;

    const string &getSkill() const;

    const bool removeTurn(NurseSolution *nurseSolution);
};


#endif //NRS_TURN_H
