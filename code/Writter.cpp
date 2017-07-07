//
// Created by António Ramadas on 19/05/2017.
//

#include "Writter.h"

string Writter::solPath = "";

void Writter::WriteSolutionToJSONFile(const Solution *solution, string path) {
    if (path == "")
        path = solPath;

    json j;

    j["scenario"] = Scenario::getInstance()->getId();
    j["week"] = Scenario::getInstance()->getCurrentWeek();
    j["assignments"] = json::array();

    vector<string> weekDays = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    for (unsigned int day = 0; day < solution->getTurns().size(); ++day)
        for (Turn *turn : solution->getTurns().at(day))
            for (NurseSolution *nurseSolution : turn->getNurses())
                j["assignments"].push_back({
                        {"nurse", nurseSolution->getNurse()->getId()},
                        {"day", weekDays.at(day)},
                        {"shiftType", turn->getShiftType()->getId()},
                        {"skill", turn->getSkill()}
                });

    ofstream fout(path);
    fout << setw(2) << j;
    fout.close();
}
