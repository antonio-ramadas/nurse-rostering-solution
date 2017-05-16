//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include "NurseSolution.h"

NurseSolution::NurseSolution(const Nurse* nurse): nurse(nurse){}

bool NurseSolution::addTurn(Turn* turn){
    if(!turnExists(turn))
    {
        turns.push_back(turn);
        return true;
    }
    return false;
}

bool NurseSolution::turnExists(Turn * turn) {
    std::find(turns.begin(), turns.end(),turn)!=turns.end();
}
