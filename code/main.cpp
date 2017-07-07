//
// Created by António Ramadas on 02/03/2017.
//

#include <thread>
#include <mutex>
#include <cstdlib>
#include <condition_variable>
#include "Scenario.h"
#include "Validator.h"
#include "Writter.h"
#include "algorithms/Grasp.h"
#include "InputParser.h"

void execute(Grasp *grasp, chrono::seconds timeout);

using namespace std;

int main(int argc, char *argv[]) {

    InputParser input(argc, argv);
    Writter::solPath = input.getCmdOption("--sol");

    //Parse
    Scenario::getInstance()->parseScenario(input.getCmdOption("--sce"));

    WeekData weekData(input.getCmdOption("--week"),
                      (int) Scenario::getInstance()->getShifts().size(),
                      (int) Scenario::getInstance()->getSkills().size());

    Scenario::getInstance()->parseHistory(input.getCmdOption("--his"));
    Scenario::getInstance()->setWeekData(weekData);

    //Compute
    Grasp* grasp = new Grasp(1000000000);
    long nurses = Scenario::getInstance()->getNurses().size();
    switch(nurses) {
        case 30:
            execute(grasp, 62s);
            break;
        case 35:
            execute(grasp, 85s);
            break;
        case 40:
            execute(grasp, 109s);
            break;
        case 50:
            execute(grasp, 155s);
            break;
        case 60:
            execute(grasp, 202s);
            break;
        case 70:
            execute(grasp, 248s);
            break;
        case 80:
            execute(grasp, 295s);
            break;
        case 100:
            execute(grasp, 388s);
            break;
        case 110:
            execute(grasp, 434s);
            break;
        case 120:
            execute(grasp, 481s);
            break;
        default:
            execute(grasp, 30s);
    }

    Solution *sol = grasp->getBestSolution();

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

void execute(Grasp *grasp, chrono::seconds timeout) {
    mutex m;
    condition_variable cv;

    thread t([&m, &cv, &grasp]()
             {
                 grasp->run(true);
                 cv.notify_one();
             });

    t.detach();

    unique_lock<mutex> l(m);
    cv.wait_for(l, timeout);
}