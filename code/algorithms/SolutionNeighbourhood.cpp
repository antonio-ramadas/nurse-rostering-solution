//
// Created by F0lha on 19/05/2017.
//

#include "SolutionNeighbourhood.h"

SolutionNeighbourhood::SolutionNeighbourhood(Solution* solution) : solution(solution){}

Solution *SolutionNeighbourhood::getNext(){
    undoLastMove();
    return nullptr;
}

void SolutionNeighbourhood::undoLastMove(){
    vector<Turn*> day1 , day2;
    switch (lastMove->getMoveType())
    {
        case 0:
            //insert so we have to remove
            day1 = solution->getTurns()[lastMove->getLastPosition().getDay()];
            for(Turn* turn : day1)
            {
                if(turn->getShiftType()->getId() == lastMove->getLastPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getLastPosition().getSkill())
                    lastMove->getMovedNurse()->removeTurn(turn);
            }
            break;
        case 1:
            //remove so we have to insert
            day1 = solution->getTurns()[lastMove->getInitialPosition().getDay()];
            for(Turn* turn : day1)
            {
                if(turn->getShiftType()->getId() == lastMove->getInitialPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getInitialPosition().getSkill())
                    lastMove->getMovedNurse()->addTurn(turn);
            }
            break;
        case 2:
            //trade so we have to do the inverse, so 2 to 1, and 1 to 2
            day1 = solution->getTurns()[lastMove->getInitialPosition().getDay()];
            day2 = solution->getTurns()[lastMove->getLastPosition().getDay()];

            Turn* initialTurn, *lastTurn;

            for(Turn* turn : day1)
            {
                if(turn->getShiftType()->getId() == lastMove->getLastPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getLastPosition().getSkill())
                    initialTurn = turn;
            }
            for(Turn* turn : day2)
            {
                if(turn->getShiftType()->getId() == lastMove->getLastPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getLastPosition().getSkill())
                    lastTurn = turn;
            }

            //atomicSwitchNurseTurns
            solution->atomicSwitchNurseTurns(lastMove->getMovedNurse(),initialTurn,lastMove->getTradedNurse(),lastTurn);
            break;
    }

    delete lastMove;
}