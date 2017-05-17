//
// Created by F0lha on 16/05/2017.
//

#include <chrono>
#include "Solution.h"

Solution::Solution(WeekData &weekData) {

    //create list of nurses with solution
    for (const Nurse &sce_nurses : Scenario::getInstance()->getNurses())
        nurses.push_back(new NurseSolution(&sce_nurses));

    //hardcoded size of week
    for(int j = 0; j < 7; j++) {
        vector<Turn *> shifts;

        for (pair<string,ShiftType> const &shift :  Scenario::getInstance()->getShifts()) {
            Turn *turn = new Turn(j, &shift.second);
            shifts.push_back(turn);
        }
      
        turns.push_back(shifts);
    }
}

const vector<NurseSolution *> &Solution::getNurses() const {
    return nurses;
}

const vector<vector<Turn *>> &Solution::getTurns() const {
    return turns;
}

void Solution::randomizeSolution(){
    default_random_engine generator((unsigned int) chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, (int) nurses.size()-1);

    auto random = bind(distribution, generator);

    for (vector<Turn *> day : turns)
        for (Turn *type : day)
            if(random() < 3)
            type->addNurse(nurses[random()]);
}
