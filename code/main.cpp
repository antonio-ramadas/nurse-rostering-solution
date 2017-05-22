//
// Created by António Ramadas on 02/03/2017.
//

#include "Scenario.h"
#include "Validator.h"
#include "Writter.h"
#include "algorithms/Grasp.h"
#include "InputParser.h"

using namespace std;

int main(int argc, char *argv[]) {

    InputParser input(argc, argv);

    //Parse
    Scenario::getInstance()->parseScenario(input.getCmdOption("--sce"));

    WeekData weekData(input.getCmdOption("--week"),
                     (int) Scenario::getInstance()->getShifts().size(),
                     (int) Scenario::getInstance()->getSkills().size());

    Scenario::getInstance()->parseHistory(input.getCmdOption("--his"));
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
    Writter::WriteSolutionToJSONFile(sol, input.getCmdOption("--sol"));

    return EXIT_SUCCESS;
}