//
// Created by F0lha on 20/05/2017.
//

#include "Move.h"

Move::Move(Position initialPosition,Position lastPosition, NurseSolution* movedNurse, NurseSolution* tradedNurse) : initialPosition(initialPosition), lastPosition(lastPosition), movedNurse(movedNurse) , tradedNurse(tradedNurse){}

Move::Move(Position initialPosition,Position lastPosition, NurseSolution* movedNurse) : initialPosition(initialPosition), lastPosition(lastPosition), movedNurse(movedNurse){}

Move::Move(Position initialPosition, NurseSolution* movedNurse) : initialPosition(initialPosition), movedNurse(movedNurse){}


const Position &Move::getInitialPosition() const {
    return initialPosition;
}

const Position &Move::getLastPosition() const {
    return lastPosition;
}

NurseSolution *Move::getMovedNurse() const {
    return movedNurse;
}

NurseSolution *Move::getTradedNurse() const {
    return tradedNurse;
}

int Move::getMoveType(){
    //If not nullptr, so it was a trade
    if(tradedNurse != nullptr)
        return 2;
        //if last position is not valid, then nurse was removed
    else if(!lastPosition.positionValid())
        return 1;
        //if not, nurse was added
    else return 0;
}

