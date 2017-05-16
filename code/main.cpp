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
    Scenario scenario("./../datasets/test/n005w4/Sc-n005w4.json");
    WeekData weekData("./../datasets/test/n005w4/WD-n005w4-0.json", scenario.getShifts().size(), scenario.getSkills().size() );
    scenario.parseHistory("./../datasets/test/n005w4/H0-n005w4-0.json");

    //Compute

    Solution sol(scenario,weekData);

    cout << "Number of Nurses : " + to_string(sol.getNurses().size());

    cout << "Number of Turns : " + to_string(sol.getTurns().size());

    //Dump result

    system("pause");

    return EXIT_SUCCESS;
}