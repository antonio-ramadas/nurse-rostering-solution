//
// Created by António Ramadas on 23/05/2017.
//

#include <chrono>
#include "ConstructionHeuristics.h"

Solution *ConstructionHeuristics::FirstFit(Solution *solution, const string &skillId) {
    auto rbegin = solution->getTurns().rbegin();
    auto rend = solution->getTurns().rend();

    for (auto dayIndex = rbegin; dayIndex != rend; dayIndex++)
        assignGivenDay(solution, (unsigned int) distance(dayIndex, rend)-1, skillId);

    return solution;
}

void ConstructionHeuristics::assignGivenDay(Solution *solution, unsigned int dayIndex, const string &skillId) {
    int minimum;
    for (Turn *turn : solution->getTurns().at(dayIndex)) {
        if (!skillId.empty() && turn->getSkill() != skillId)
            continue;

        minimum = Scenario::getInstance()->getWeekData().getMinimumCoverageRequirement(turn->getSkill(),
                                                                                       turn->getShiftType()->getId(),
                                                                                       dayIndex);
        if (minimum == 0)
            continue;

        for (auto const &it : solution->getNurses())
            if (solution->assignNurseToTurn(it.second, turn))
                if (--minimum <= 0)
                    break;
    }
}

Solution *ConstructionHeuristics::MoreSkilled(Solution *solution) {
    map<unsigned int, string> counter = countNurseSkills();

    for (auto &it : counter)
        solution = FirstFit(solution, it.second);

    return solution;
}

map<unsigned int, string> ConstructionHeuristics::countNurseSkills() {
    unordered_map<string, unsigned int> counter;

    for (const string &skill : Scenario::getInstance()->getSkills())
        counter.insert(make_pair(skill, 0));

    for (const Nurse &nurse : Scenario::getInstance()->getNurses())
        for (const string &skill : nurse.getSkills())
            counter.at(skill)++;

    //sort the map, key = counter and value = skill
    map<unsigned int, string> sortedCounter;
    for (auto &it : counter)
        sortedCounter.insert(make_pair(it.second, it.first));

    return sortedCounter;
}

Solution* ConstructionHeuristics::RequestsFirst(Solution* solution){
    default_random_engine generator((unsigned int) chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, (int) solution->getNurses().size()-1);

    auto random = bind(distribution, generator);

    vector<ShiftOffRequest> shiftOffRequests = Scenario::getInstance()->getWeekData().getShiftOffRequests();


    for (vector<Turn *> day : solution->getTurns())
        for (Turn *turn : day) {
            int requiredNurses = Scenario::getInstance()->getWeekData().getRequirements().at(turn->getSkill()).at(turn->getShiftType()->getId()).at((unsigned int)turn->getDay())->getMinimumCoverage();
            int loop = 0;
            outerLoop: for(int i = 0; i < requiredNurses;i++)
            {
                loop++;
                auto iter = solution->getNurses().begin();
                std::advance( iter, random() );
                //check if nurse requested day off
                bool cont = false;

                for(ShiftOffRequest shiftOffRequest: shiftOffRequests) {
                    if(shiftOffRequest.getNurse() == iter->second->getNurse()->getId())
                        continue;
                    int dayInt = Scenario::getInstance()->getDayOfWeek(shiftOffRequest.getDay());
                    if(turn->getDay() == dayInt && (shiftOffRequest.getShiftType() == "Any" || shiftOffRequest.getShiftType() == turn->getShiftType()->getId())) {
                        cont = true;
                        shiftOffRequests.erase(std::remove(shiftOffRequests.begin(), shiftOffRequests.end(), shiftOffRequest), shiftOffRequests.end());
                        break;
                    }
                }
                if(cont)
                    continue;
                if(!solution->assignNurseToTurn(iter->second, turn))
                    i--;
                if(loop > solution->getNurses().size()*2)
                    return nullptr;
            }
        }
    return solution;
}

Solution* ConstructionHeuristics::randomIteration(Solution * solution) {
    default_random_engine generator((unsigned int) chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, (int) solution->getNurses().size()-1);

    auto random = bind(distribution, generator);

    for (vector<Turn *> day : solution->getTurns())
        for (Turn *turn : day) {
            int requiredNurses = Scenario::getInstance()->getWeekData().getRequirements().at(turn->getSkill()).at(turn->getShiftType()->getId()).at((unsigned int)turn->getDay())->getMinimumCoverage();
            int loop = 0;
            for(int i = 0; i < requiredNurses;i++)
            {
                loop++;
                auto iter = solution->getNurses().begin();
                std::advance( iter, random() );
                if(!solution->assignNurseToTurn(iter->second, turn))
                    i--;
                if(loop > solution->getNurses().size()*2)
                    return nullptr;
            }
        }
    return solution;
}