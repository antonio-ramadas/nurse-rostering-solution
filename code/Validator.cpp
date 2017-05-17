//
// Created by F0lha on 16/05/2017.
//

#include "Validator.h"

bool Validator::constraintH1(const Solution &solution) {
    vector<NurseSolution *> nurses = solution.getNurses();
    for(NurseSolution * nurse : nurses)
    {
        vector<Turn *> turns = nurse->getTurns();

        int lastDay = -1;

        for(Turn * turn : turns){
            int current = turn->getDay();
            if(lastDay != current)
                lastDay = current;
            else return false;
        }
    }
    return true;
}

bool Validator::constraintH2(const Solution &solution) {

    for (const vector<Turn*> &days: solution.getTurns())
        for (const Turn *turn : days) {

            string shiftId = turn->getShiftType()->getId();

            /*int numberAllocatedNurses = count_if(begin(turn->getNurses()),
                     end(turn->getNurses()),
                     [] (NurseSolution *nurseSolution) -> bool {
                         return nurseSolution->
                     });
*/
        }

    return true;
}