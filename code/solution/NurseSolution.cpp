//
// Created by F0lha on 16/05/2017.
//

#include <algorithm>
#include <iostream>
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
    return find(turns.begin(), turns.end(),turn)!=turns.end();
}

const vector<Turn *> &NurseSolution::getTurns() const {
    return turns;
}

const Nurse *NurseSolution::getNurse() const {
    return nurse;
}

const bool NurseSolution::canWork(const Turn *turn) {
    return any_of(begin(turns), end(turns), [=](Turn* turnElem) {
         return turnElem->getDay() == turn->getDay();
    });
}


