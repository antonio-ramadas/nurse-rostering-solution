//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"
#include "WeekData.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Parse
    Scenario scenario("./../datasets/test/n005w4/Sc-n005w4.json");
    WeekData weekData("./../datasets/test/n005w4/WD-n005w4-0.json", scenario.getShifts().size(), scenario.getSkills().size() );
    //scenario.parseHistory("./../datasets/test/n005w4/H0-n005w4-0.json");

    //Compute

    //Dump result

    return EXIT_SUCCESS;
}