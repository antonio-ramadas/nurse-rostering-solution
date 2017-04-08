//
// Created by António Ramadas on 08/04/2017.
//

#ifndef NRS_DAYREQUIREMENT_H
#define NRS_DAYREQUIREMENT_H

#include <string>

using namespace std;

class DayRequirement {
private:
    int minimumCoverage, optimalCoverage;
public:
    int getMinimumCoverage() const;

    void setMinimumCoverage(int minimumCoverage);

    int getOptimalCoverage() const;

    void setOptimalCoverage(int optimalCoverage);

public:
    DayRequirement(int minimumCoverage, int optimalCoverage);
};


#endif //NRS_DAYREQUIREMENT_H
