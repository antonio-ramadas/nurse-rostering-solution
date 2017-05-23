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
    return nullptr;
}

Solution *ConstructionHeuristics::WeekendFirst(Solution *solution) {
    return nullptr;
}
