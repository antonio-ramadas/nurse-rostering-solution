//
// Created by António Ramadas on 23/05/2017.
//

#ifndef NRS_CONSTRUCTIONHEURISTICS_H
#define NRS_CONSTRUCTIONHEURISTICS_H


#include "../solution/Solution.h"

class ConstructionHeuristics {
public:
    static Solution* FirstFit(Solution *solution);
    static Solution* MoreSkilled(Solution *solution);
    static Solution* WeekendFirst(Solution *solution);
};


#endif //NRS_CONSTRUCTIONHEURISTICS_H
