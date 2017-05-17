//
// Created by F0lha on 16/05/2017.
//

#ifndef NRS_VALIDATOR_H
#define NRS_VALIDATOR_H


#include "solution/Solution.h"
#include <cstddef>

using namespace std;

class Validator {

public:
    //////////
    // Hard //
    //////////
    //Single assignment per day
    static bool constraintH1(const Solution &solution);

    //TODO Under-staffing
    static bool constraintH2(const Solution &solution);

    //TODO Shift type successions
    static bool constraintH3(const Solution &solution);

    //TODO Missing required skill
    static bool constraintH4(const Solution &solution);

    //////////
    // Soft //
    //////////
    //TODO Insufficient staffing for optimal coverage
    // Cost: 30
    static unsigned int constraintS1(const Solution &solution);

    //TODO Consecutive assignments
    // Cost: The weights for consecutive shift constraint and for consecutive working days are respectively 15 and 30.
    static unsigned int constraintS2(const Solution &solution);

    //TODO Consecutive Days Off
    // Cost: 30
    static unsigned int constraintS3(const Solution &solution);

    //TODO Preferences
    // Cost: 10
    static unsigned int constraintS4(const Solution &solution);

    //TODO Complete Weekend
    // Cost: 30
    static unsigned int constraintS5(const Solution &solution);

    //////////////////////////////////////////////////////////////////////////////////
    // Soft constraints that may only be checked at the end of the planning horizon //
    //////////////////////////////////////////////////////////////////////////////////

    //TODO Total Assignments
    // Cost: 20
    static unsigned int constraintS6(const Solution &solution);

    //TODO Total working weekends
    // Cost: 30
    static unsigned int constraintS7(const Solution &solution);

};


#endif //NRS_VALIDATOR_H
