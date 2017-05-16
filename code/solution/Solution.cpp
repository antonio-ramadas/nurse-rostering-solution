//
// Created by F0lha on 16/05/2017.
//

#include "Solution.h"

Solution::Solution(Scenario * scenario, vector<WeekData> * weekData) {

    //create list of nurses with solution
    for(int i = 0; i < scenario->getNurses().size(); i++){
        nurses.push_back(new NurseSolution(& scenario->getNurses()[i]));
    }

    for(int i = 0; i < scenario->getNumberOfWeeks(); i++)
    {
        vector<vector<Turn *>> day;
        //hardcoded size of week
        for(int j = 0; j < 7; j++)
        {
            vector<Turn *> shifts;
            for(int k = 0; k < scenario->getShifts().size(); k++)
            {
                shifts.push_back(new Turn(i,j,& scenario->getShifts()[k]));
            }
            day.push_back(shifts);
        }
        turns.push_back(day);
    }
}

const vector<NurseSolution *> &Solution::getNurses() const {
    return nurses;
}

const vector<vector<vector<Turn *>>> &Solution::getTurns() const {
    return turns;
}
