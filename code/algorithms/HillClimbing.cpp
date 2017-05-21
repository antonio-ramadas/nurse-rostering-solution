//
// Created by F0lha on 19/05/2017.
//

#include "HillClimbing.h"
#include "../Validator.h"
#include "SolutionNeighbourhood.h"

Solution* HillClimbing::runHillClimbing(Solution* solution){

    SolutionNeighbourhood* neighbourhood = new SolutionNeighbourhood(solution);

    int bestScore = Validator::evaluateSolution(*solution);

    //next will undo last move so it can reset the initial solution
    while((solution = neighbourhood->getNext()) && !neighbourhood->hasEnded())
    {
        int currentScore = Validator::evaluateSolution(*solution);
        if(bestScore > currentScore)
        {
            delete neighbourhood;
            neighbourhood = new SolutionNeighbourhood(solution);
            bestScore = currentScore;
        }
    }
    delete neighbourhood;
    return solution;
}