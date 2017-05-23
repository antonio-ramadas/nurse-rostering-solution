//
// Created by António Ramadas on 23/05/2017.
//

#include "ConstructionHeuristics.h"

Solution *ConstructionHeuristics::FirstFit(Solution *solution) {
    int minimum;
    for (unsigned int dayIndex = 0; dayIndex < solution->getTurns().size(); dayIndex++)
        for (Turn *turn : solution->getTurns().at(dayIndex)) {
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

    return solution;
}

Solution *ConstructionHeuristics::MoreSkilled(Solution *solution) {
    unordered_map<string, unsigned int> counter = countNurseSkills();
    return solution;
}

Solution *ConstructionHeuristics::WeekendFirst(Solution *solution) {
    return nullptr;
}

unordered_map<string, unsigned int> ConstructionHeuristics::countNurseSkills() {
    unordered_map<string, unsigned int> counter;

    for (const string &skill : Scenario::getInstance()->getSkills())
        counter.insert(make_pair(skill, 0));

    for (const Nurse &nurse : Scenario::getInstance()->getNurses())
        for (const string &skill : nurse.getSkills())
            counter.at(skill)++;

    return counter;
}
