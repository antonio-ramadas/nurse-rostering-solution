//
// Created by F0lha on 19/05/2017.
//

#include "SolutionNeighbourhood.h"
#include "../Validator.h"

SolutionNeighbourhood::SolutionNeighbourhood(Solution* solution) : solution(solution){
    this->phase = 0;
    this->iterator1 = 0;
    this->iterator2 = 0;
}

Solution *SolutionNeighbourhood::getNext(){
    cout << "Before : " << Validator::evaluateSolution(*this->solution)<<endl;
    undoLastMove();
    cout << "After : " << Validator::evaluateSolution(*this->solution)<<endl;
    if(phase == 0) {
        while (1) {
            Turn *currentTurn = solution->getTurns()[iterator1][iterator2];

            if (currentTurn->getNurses().size() <
                Scenario::getInstance()->getWeekData().getRequirements().at(currentTurn->getSkill()).at(
                        currentTurn->getShiftType()->getId()).at(currentTurn->getDay())->getOptimalCoverage())
                for (auto const &nurse : solution->getNurses()) {
                    if (solution->assignNurseToTurn(nurse.second,currentTurn)) {
                        lastMove = new Move(Position(-1, nullptr, ""),
                                            Position(currentTurn->getDay(), currentTurn->getShiftType(),
                                                     currentTurn->getSkill()), nurse.second);
                        iterator2++;
                        if (iterator2 == solution->getTurns()[iterator1].size()) {
                            iterator2 = 0;
                            iterator1++;
                            if (iterator1 == solution->getTurns().size()) {
                                phase++;
                                return this->getNext();
                            }
                        }
                        return solution;
                    }
                }
            iterator2++;
            if (iterator2 == solution->getTurns()[iterator1].size()) {
                iterator2 = 0;
                iterator1++;
                if (iterator1 == solution->getTurns().size()) {
                    phase++;
                    return this->getNext();
                }
            }
        }
    }
    this->ended = true;
    return solution;
}

void SolutionNeighbourhood::undoLastMove(){
    if(lastMove == nullptr)
        return;
    vector<Turn*> day1 , day2;
    switch (lastMove->getMoveType())
    {
        case 0:
            //insert so we have to remove
            day1 = solution->getTurns()[lastMove->getLastPosition().getDay()];
            for(Turn* turn : day1)
            {
                if(turn->getShiftType()->getId() == lastMove->getLastPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getLastPosition().getSkill()) {
                    solution->removeNurseFromTurn(lastMove->getMovedNurse(),turn);
                    delete lastMove;
                    lastMove = nullptr;
                    return;
                }
            }
            break;
        case 1:
            //remove so we have to insert
            day1 = solution->getTurns()[lastMove->getInitialPosition().getDay()];
            for(Turn* turn : day1)
            {
                if(turn->getShiftType()->getId() == lastMove->getInitialPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getInitialPosition().getSkill()){
                    lastMove->getMovedNurse()->addTurn(turn);
                return;
                }
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
    lastMove = nullptr;
}

bool SolutionNeighbourhood::hasEnded(){
    return ended;
}