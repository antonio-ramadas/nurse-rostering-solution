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

    const bool isSingleAssignment(const Turn* turnToCheck, const Turn *turnToIgnore = nullptr) const;

    const bool isLegalSuccession(const Turn *turnToCheck, const Turn *turnToIgnore = nullptr) const;

    const bool hasSkillToWork(const Turn* turn) const;

    const bool hasHistoryConflict(const Turn *turnToCheck) const;

    bool hasTurnConflict(const Turn *turnToCheck, const Turn *turnToIgnore = nullptr) const;

public:
    NurseSolution(const Nurse* nurse);

    bool addTurn(Turn* turn);

    bool hasTurn(const Turn *turn);

    const vector<Turn *> &getTurns() const;

    const Nurse *getNurse() const;

    const bool canWork(const Turn *turnToAssign, const Turn *turnToIgnore = nullptr);

    const bool removeTurn(Turn *turn);

    void sortTurns();

    static bool compareTurns(Turn* a, Turn* b);
};


#endif //NRS_NURSESOLUTION_H
