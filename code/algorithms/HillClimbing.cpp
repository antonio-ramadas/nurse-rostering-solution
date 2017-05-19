//
// Created by F0lha on 19/05/2017.
//

#include "HillClimbing.h"
#include "../Validator.h"
#include "SolutionNeighbourhood.h"

Solution* HillClimbing::runHillClimbing(Solution* solution){

    SolutionNeighbourhood* neighbourhood = new SolutionNeighbourhood(solution);

    Solution* bestSolution = solution;
    int bestScore = Validator::evaluateSolution(*solution);

    Solution* neiSolution;

    while((neiSolution = neighbourhood->getNext()) != nullptr)
    {
        int currentScore = Validator::evaluateSolution(*neiSolution);
        if(bestScore > currentScore)
        {
            delete solution;
            delete neighbourhood;
            neighbourhood = new SolutionNeighbourhood(neiSolution);
            bestScore = currentScore;
            bestSolution = neiSolution;
        }
        else{
            delete neiSolution;
        }
    }
    delete neighbourhood;
    return bestSolution;
}