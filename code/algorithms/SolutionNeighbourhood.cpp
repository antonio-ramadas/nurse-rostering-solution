//
// Created by F0lha on 19/05/2017.
//

#include "SolutionNeighbourhood.h"
#include "../Validator.h"

SolutionNeighbourhood::SolutionNeighbourhood(Solution* solution) : solution(solution){
    this->phase = 0;
    this->iterator1 = 0;
    this->iterator2 = 0;
    this->iteratorTurn1 = 0;
    this->iteratorTurn2 = 0;

    for(auto it = solution->getNurses().begin(); it != solution->getNurses().end(); ++it ) {
        this->nurseVector.push_back( it->second );
    }
}

Solution *SolutionNeighbourhood::getNext(){
    undoLastMove();
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
                                iterator1 = 0;
                                iterator2 = 0;
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
                    iterator1 = 0;
                    iterator2 = 0;
                    return this->getNext();
                }
            }
        }
    }
    //iterate each nurse then iterate the otherNurses and check if they can trade Turns
    else if(phase == 1){
        for(;iterator1 < this->nurseVector.size();){
            for(;iterator2 < this->nurseVector.size();)
            {
                if(iterator1 != iterator2)
                    for(;iteratorTurn1 < nurseVector[iterator1]->getTurns().size();)
                    {
                        for(;iteratorTurn2 < nurseVector[iterator2]->getTurns().size();){
                            if(nurseVector[iterator1]->getTurns()[iteratorTurn1] != nurseVector[iterator2]->getTurns()[iteratorTurn2]) {
                                lastMove = new Move(
                                        //initial Position
                                        Position(nurseVector[iterator1]->getTurns()[iteratorTurn1]->getDay(),
                                                 nurseVector[iterator1]->getTurns()[iteratorTurn1]->getShiftType(),
                                                 nurseVector[iterator1]->getTurns()[iteratorTurn1]->getSkill()),
                                        //lastPosition Position
                                        Position(nurseVector[iterator2]->getTurns()[iteratorTurn2]->getDay(),
                                                 nurseVector[iterator2]->getTurns()[iteratorTurn2]->getShiftType(),
                                                 nurseVector[iterator2]->getTurns()[iteratorTurn2]->getSkill()),
                                        //Ns1 / Ns2
                                        nurseVector[iterator1], nurseVector[iterator2]);
                                if(solution->atomicSwitchNurseTurns(nurseVector[iterator1],nurseVector[iterator2]->getTurns()[iteratorTurn2],nurseVector[iterator2],nurseVector[iterator2]->getTurns()[iteratorTurn2]))
                                {
                                    iteratorTurn2++;
                                    return solution;
                                    }
                                else {
                                    delete lastMove;
                                    lastMove = nullptr;
                                    iteratorTurn2++;
                                }
                            }
                            else iteratorTurn2++;
                        }
                        iteratorTurn1++;
                        iteratorTurn2 = 0;
                    }
                iterator2++;
                iteratorTurn1 = 0;
            }
            iterator2 = 0;
            iterator1++;
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

            Turn* initialTurn;
            Turn* lastTurn;

            for(Turn* turn : day1)
            {
                if(turn->getShiftType()->getId() == lastMove->getInitialPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getInitialPosition().getSkill())
                    initialTurn = turn;
            }
            for(Turn* turn : day2)
            {
                if(turn->getShiftType()->getId() == lastMove->getLastPosition().getShiftType()->getId() && turn->getSkill() == lastMove->getLastPosition().getSkill())
                    lastTurn = turn;
            }

            //atomicSwitchNurseTurns, invert what lastMove did
            //NS1 / LastPosition / NS2 / InitialPosition
            solution->atomicSwitchNurseTurns(lastMove->getMovedNurse(),lastTurn,lastMove->getTradedNurse(),initialTurn);
            //if(!solution->atomicSwitchNurseTurns(lastMove->getMovedNurse(),lastTurn,lastMove->getTradedNurse(),initialTurn))
                //cout << "ERRO" << endl;
            delete lastMove;
            lastMove = nullptr;
            break;
    }

    delete lastMove;
    lastMove = nullptr;
}

bool SolutionNeighbourhood::hasEnded(){
    return ended;
}

int SolutionNeighbourhood::getPhase() const {
    return phase;
}
