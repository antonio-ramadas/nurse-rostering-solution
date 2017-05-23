//
// Created by António Ramadas on 23/05/2017.
//

#ifndef NRS_CONSTRUCTIONHEURISTICS_H
#define NRS_CONSTRUCTIONHEURISTICS_H


#include "../solution/Solution.h"

class ConstructionHeuristics {
private:
    static map<unsigned int, string> countNurseSkills();
    static Solution *FirstFit(Solution *solution, const string &skillId = "");
    static void assignGivenDay(Solution *solution, unsigned int dayIndex, const string &skillId = "");

public:
    static Solution* MoreSkilled(Solution *solution);

    static Solution* RequestsFirst(Solution *solution);

    static  Solution* randomIteration( Solution* solution);
};


#endif //NRS_CONSTRUCTIONHEURISTICS_H
