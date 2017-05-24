//
// Created by António Ramadas on 23/05/2017.
//

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
