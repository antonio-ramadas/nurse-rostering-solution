//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"
#include "WeekData.h"
#include "Validator.h"
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

    Solution* sol = new Solution(weekData);

    cerr << "Number of Nurses : " << sol->getNurses().size() << endl;

    cerr << "Number of Turns : " << sol->getTurns().size() << endl;



    sol->randomizeSolution();

    while(Validator::constraintH1(*sol) == 0) {
        delete sol;
        sol = new Solution(weekData);
        sol->randomizeSolution();
    }

    cerr << *sol;

    if(Validator::constraintH3(*sol) )
        cerr << "H3 constraint : " << "true";
    else
        cerr << "H3 constraint : " << "false";
    cerr << endl;

    if(Validator::constraintH1(*sol) )
        cerr << "H1 constraint : " << "true";
    else
        cerr << "H1 constraint : " << "false";
    cerr << endl;

    //Dump result

    return EXIT_SUCCESS;
}