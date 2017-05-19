//
// Created by F0lha on 19/05/2017.
//

#ifndef NRS_SOLUTIONNEIGHBOURHOOD_H
#define NRS_SOLUTIONNEIGHBOURHOOD_H


#include "../solution/Solution.h"

class SolutionNeighbourhood {

    Solution* solution;


public:
    SolutionNeighbourhood(Solution* solution);

    Solution *getNext();
};


#endif //NRS_SOLUTIONNEIGHBOURHOOD_H
