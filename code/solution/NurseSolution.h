//
// Created by F0lha on 16/05/2017.
//

#ifndef NRS_NURSESOLUTION_H
#define NRS_NURSESOLUTION_H


#include "../Nurse.h"
#include "Turn.h"

using namespace std;

class Turn;

class NurseSolution {
    const Nurse* nurse;
    vector<Turn *> turns;

public:
    NurseSolution(const Nurse* nurse);

    bool addTurn(Turn* turn);

    bool turnExists(Turn * turn);

    const vector<Turn *> &getTurns() const;

    const Nurse *getNurse() const;
};


#endif //NRS_NURSESOLUTION_H
