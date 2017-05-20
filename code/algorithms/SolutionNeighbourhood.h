//
// Created by F0lha on 19/05/2017.
//

#ifndef NRS_SOLUTIONNEIGHBOURHOOD_H
#define NRS_SOLUTIONNEIGHBOURHOOD_H


#include "../solution/Solution.h"
#include "Move.h"

class SolutionNeighbourhood {

    Solution* solution;

    Move* lastMove = nullptr;

public:
    SolutionNeighbourhood(Solution* solution);

    Solution *getNext();

    void undoLastMove();
};


#endif //NRS_SOLUTIONNEIGHBOURHOOD_H
