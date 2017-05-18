//
// Created by F0lha on 16/05/2017.
//

#include <chrono>
#include "Solution.h"

Solution::Solution(WeekData &weekData) {

    //create list of nurses with solution
    for (const Nurse &sce_nurses : Scenario::getInstance()->getNurses())
        nurses.insert(make_pair(sce_nurses.getId(),new NurseSolution(&sce_nurses)));

    using req_map = unordered_map<string, unordered_map<ShiftType*, vector<DayRequirement*>>>;

    //hardcoded size of week
    for(int j = 0; j < 7; j++) {
        vector<Turn *> shifts;

        for (pair<string,ShiftType> const &shift :  Scenario::getInstance()->getShifts()) {
            ShiftType* shiftType = new ShiftType(shift.second.getId(),shift.second.getMinimumNumberOfConsecutiveAssignments(),shift.second.getMaximumNumberOfConsecutiveAssignments());
            shiftType->setForbidden(shift.second.getForbiddenSucceedingShiftTypes());
            for(string skill : Scenario::getInstance()->getSkills()) {
                Turn *turn = new Turn(j, skill, shiftType);
                shifts.push_back(turn);
            }
        }
        turns.push_back(shifts);
    }
}

const map<string, NurseSolution *> &Solution::getNurses() const {
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
            if(random() < 3) {
                auto iter = nurses.begin();
                std::advance( iter, random() );
                assignNurse(iter->second, type);
                //type->addNurse(iter->second);
            }
}

Solution::~Solution() {
    for(vector<Turn*> day : turns)
        for(Turn* turn : day)
            delete turn;
}

bool Solution::assignNurse(NurseSolution *nurseSolution, Turn *turn) {

    if (!nurseSolution->canWork(turn))
        return false;

    turn->addNurse(nurseSolution);

    return true;
}
