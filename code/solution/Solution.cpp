//
// Created by F0lha on 16/05/2017.
//

#include <chrono>
#include "Solution.h"

Solution::Solution() {

    this->createNursesAndTurns();
}

void Solution::createNursesAndTurns() {
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
    while(!this->randomIteration())
    {
        this->resetSolution();
    }
}

bool Solution::randomIteration() {
    default_random_engine generator((unsigned int) chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, (int) nurses.size()-1);

    auto random = bind(distribution, generator);

    for (vector<Turn *> day : turns)
        for (Turn *turn : day) {
            int requiredNurses = Scenario::getInstance()->getWeekData().getRequirements().at(turn->getSkill()).at(turn->getShiftType()->getId()).at(turn->getDay())->getMinimumCoverage();
            int loop = 0;
            for(int i = 0; i < requiredNurses;i++)
            {
                loop++;
                auto iter = nurses.begin();
                std::advance( iter, random() );
                if(!assignNurse(iter->second, turn))
                    i--;
                if(loop > nurses.size()*2)
                    return false;
            }
        }
    return true;
}

Solution::~Solution() {
    this->deleteNursesAndTurns();
}

void Solution::deleteNursesAndTurns() {
    for(vector<Turn*> day : turns)
        for(Turn* turn : day)
            delete turn;
    for(auto const &nurse: nurses)
        delete nurse.second;

    nurses.clear();
    turns.clear();
}

bool Solution::assignNurse(NurseSolution *nurseSolution, Turn *turn) {

    if (!nurseSolution->canWork(turn))
        return false;

    turn->addNurse(nurseSolution);

    return true;
}

void Solution::resetSolution(){
    this->deleteNursesAndTurns();
    this->createNursesAndTurns();
}
