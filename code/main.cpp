//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"
#include "WeekData.h"
#include "solution/Solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Parse
    Scenario::getInstance()->parseScenario("./../datasets/test/n005w4/Sc-n005w4.json");

    WeekData weekData("./../datasets/test/n005w4/WD-n005w4-0.json",
                     (int) Scenario::getInstance()->getShifts().size(),
                     (int) Scenario::getInstance()->getSkills().size());

    Scenario::getInstance()->parseHistory("./../datasets/test/n005w4/H0-n005w4-0.json");

    //Compute

    Solution sol(weekData);

    cout << "Number of Nurses : " << sol.getNurses().size() << endl;

    cout << "Number of Turns : " << sol.getTurns().size() << endl;

    //Dump result

    return EXIT_SUCCESS;
}