//
// Created by F0lha on 19/05/2017.
//

#include "Grasp.h"
#include "../Validator.h"
#include "HillClimbing.h"

Grasp::Grasp(WeekData* weekData) : weekData(weekData){}

Grasp::Grasp(WeekData* weekData, int initialSolutions) : weekData(weekData), initialSolutions(initialSolutions){}

Solution* Grasp::run(bool random){

    Solution* bestSolution = nullptr;
    int bestScore;

    if(random)
    {
        for(int i = 0; i < initialSolutions; i++)
        {
            Solution* newSol = new Solution(*weekData);

            newSol->randomizeSolution();

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