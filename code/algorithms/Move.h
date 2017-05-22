//
// Created by F0lha on 20/05/2017.
//

#ifndef NRS_MOVE_H
#define NRS_MOVE_H


#include "../ShiftType.h"
#include "../solution/NurseSolution.h"
#include "Position.h"

class Move {

    Position initialPosition;
    Position lastPosition = Position(-1,nullptr,"");

    NurseSolution* movedNurse;
    NurseSolution* tradedNurse = nullptr;

public:
    Move(Position initialPosition, NurseSolution* movedNurse);


    Move(Position initialPosition,Position lastPosition, NurseSolution* movedNurse);


    Move(Position initialPosition,Position lastPosition, NurseSolution* movedNurse, NurseSolution* tradedNurse);

    const Position &getInitialPosition() const;

    const Position &getLastPosition() const;

    NurseSolution *getMovedNurse() const;

    NurseSolution *getTradedNurse() const;

    int getMoveType();

};


#endif //NRS_MOVE_H
