//
// Created by F0lha on 16/05/2017.
//

#ifndef NRS_SOLUTION_H
#define NRS_SOLUTION_H


#include "../Scenario.h"
#include "../WeekData.h"
#include "NurseSolution.h"


using namespace std;

class Solution {
    vector<NurseSolution *> nurses;
    vector<Turn *> turns;
public:
    Solution(Scenario scenario, WeekData weekData);

    const vector<NurseSolution *> &getNurses() const;

    const vector<Turn *> &getTurns() const;
};


#endif //NRS_SOLUTION_H
