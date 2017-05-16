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
    //matrix Weeks/Days/Types
    vector< vector< Turn *>> turns;

    Scenario * scenario;
    vector<WeekData>* weekData;
public:
    Solution(Scenario * scenario, vector<WeekData> * weekData);

    const vector<NurseSolution *> &getNurses() const;

    const vector< vector< Turn *>> &getTurns() const;

     void randomizeSolution();
};


#endif //NRS_SOLUTION_H
