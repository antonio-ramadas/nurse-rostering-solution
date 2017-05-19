//
// Created by António Ramadas on 19/05/2017.
//

#include "Writter.h"

void Writter::WriteSolutionToJSONFile(const Solution *solution) {
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

    cout << j.dump(4) << endl;
    ofstream fout("./../output/" + Scenario::getInstance()->getId() + ".json");
    fout << setw(4) << j;
    fout.close();
}
