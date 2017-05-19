//
// Created by F0lha on 19/05/2017.
//

#ifndef NRS_GRASP_H
#define NRS_GRASP_H


#include "WeekData.h"
#include "solution/Solution.h"

class Grasp {

    WeekData* weekData;

    int initialSolutions = 10;

public:
    Grasp(WeekData* weekData);

    Grasp(WeekData* weekData, int initialSolutions);

    Solution* run(bool random);

};


#endif //NRS_GRASP_H
