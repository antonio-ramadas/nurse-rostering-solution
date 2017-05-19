//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"
#include "WeekData.h"
#include "Validator.h"
#include "solution/Solution.h"
#include "Writter.h"
#include "algorithms/Grasp.h"

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

    Grasp* grasp = new Grasp(10);

    Solution* sol = grasp->run(true);

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

    cout << "Solution evaluated : " << Validator::evaluateSolution(*sol) << endl;

    //Dump result
    Writter::WriteSolutionToJSONFile(sol);

    return EXIT_SUCCESS;
}