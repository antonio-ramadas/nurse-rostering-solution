//
// Created by António Ramadas on 08/04/2017.
//

#include "DayRequirement.h"

DayRequirement::DayRequirement(int minimumCoverage, int optimalCoverage) : minimumCoverage(minimumCoverage),
                                                                           optimalCoverage(optimalCoverage) {}

int DayRequirement::getMinimumCoverage() const {
    return minimumCoverage;
}

void DayRequirement::setMinimumCoverage(int minimumCoverage) {
    DayRequirement::minimumCoverage = minimumCoverage;
}

int DayRequirement::getOptimalCoverage() const {
    return optimalCoverage;
}

void DayRequirement::setOptimalCoverage(int optimalCoverage) {
    DayRequirement::optimalCoverage = optimalCoverage;
}
