//
// Created by F0lha on 16/05/2017.
//

#include <chrono>
#include "Solution.h"

Solution::Solution(WeekData &weekData) {

    //create list of nurses with solution
    for (const Nurse &sce_nurses : Scenario::getInstance()->getNurses())
        nurses.push_back(new NurseSolution(&sce_nurses));

    using req_map = unordered_map<string, unordered_map<ShiftType*, vector<DayRequirement*>>>;

    //hardcoded size of week
    for(int j = 0; j < 7; j++) {
        vector<Turn *> shifts;

        for (req_map::const_iterator iter = begin(weekData.getRequirements()); iter != end(weekData.getRequirements()); advance(iter, 1))
            for (const pair<string,ShiftType> &st : Scenario::getInstance()->getShifts())
                shifts.push_back(new Turn(iter->first, &st.second));
      
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
            type->addNurse(nurses[random()]);
}
