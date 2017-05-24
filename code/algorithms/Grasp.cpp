//
// Created by F0lha on 19/05/2017.
//

#include "Grasp.h"
#include "../Validator.h"
#include "HillClimbing.h"
#include "ConstructionHeuristics.h"

Grasp::Grasp() {}

Grasp::Grasp(int initialSolutions) : initialSolutions(initialSolutions){}

Solution* Grasp::run(bool random){

    int bestScore = -1;

    if(random)
    {
        for(int i = 0; i < initialSolutions; i++)
        {
            Solution* newSol = new Solution();

            newSol->populateSolution(ConstructionHeuristics::randomIteration);

            //Solution* currentSol = newSol;
            Solution* currentSol = HillClimbing::runHillClimbing(newSol);

            if(bestSolution == nullptr) {
                bestSolution = currentSol;
                bestScore = Validator::evaluateSolution(*currentSol);
            }
            else
            {
                int currentScore = Validator::evaluateSolution(*currentSol);
                if(currentScore < bestScore)
                {
                    delete bestSolution;
                    bestSolution = currentSol;
                    bestScore = currentScore;
                }
                else
                {
                    delete currentSol;
                }
            }
        }
    } else{
        return bestSolution;
    }

    return bestSolution;
}

Solution *Grasp::getBestSolution() const {
    return bestSolution;
}
