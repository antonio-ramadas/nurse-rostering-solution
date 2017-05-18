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
    Scenario::getInstance()->setWeekData(weekData);

    //Compute

    Solution* sol = new Solution(weekData);

    cout << "Number of Nurses : " << sol->getNurses().size() << endl;

    cout << "Number of Turns : " << sol->getTurns().size() << endl;

    cout << endl;

    sol->randomizeSolution();

    while(Validator::constraintH1(*sol) == false || /*Validator::constraintH2(*sol) == false || */ Validator::constraintH3(*sol) == false) {
        delete sol;
        sol = new Solution(weekData);
        sol->randomizeSolution();
        cout << *sol << endl;
    }

    cout << *sol << endl;



    if(Validator::constraintH1(*sol) )
        cout << "H1 constraint : " << "true";
    else
        cout << "H1 constraint : " << "false";
    cout << endl;

    if(Validator::constraintH2(*sol) )
        cout << "H2 constraint : " << "true";
    else
        cout << "H2 constraint : " << "false";
    cout << endl;

    if(Validator::constraintH3(*sol) )
        cout << "H3 constraint : " << "true";
    else
        cout << "H3 constraint : " << "false";
    cout << endl;

    cout << "S4 constraint : " << Validator::constraintS4(*sol);

    //Dump result

    return EXIT_SUCCESS;
}