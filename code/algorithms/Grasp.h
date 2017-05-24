//
// Created by F0lha on 19/05/2017.
//

#ifndef NRS_GRASP_H
#define NRS_GRASP_H


#include "../WeekData.h"
#include "../solution/Solution.h"

class Grasp {

    int initialSolutions = 10;
    Solution *bestSolution = nullptr;
public:
    Solution *getBestSolution() const;

public:
    Grasp();

    Grasp( int initialSolutions);

    Solution* run(bool random);

};


#endif //NRS_GRASP_H
