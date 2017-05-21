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

    vector<NurseSolution*> nurseVector;

    /*
     * 0->Iterate turns, check optimal stuff, add nurse if it cans
     * 1->
     */
    int phase, iterator1, iterator2, iteratorTurn1 , iteratorTurn2;

    bool ended = false;

public:
    SolutionNeighbourhood(Solution* solution);

    Solution *getNext();

    void undoLastMove();

    bool hasEnded();

    int getPhase() const;
};


#endif //NRS_SOLUTIONNEIGHBOURHOOD_H
