//
// Created by António Ramadas on 19/05/2017.
//

#include "Writter.h"

void Writter::WriteSolutionToJSONFile(const Solution *solution) {
    json j;
    j["scenario"] = "sce";
    j["week"] = "we";
    j["assignments"] = json::array();

    j["assignments"] = {{"nurse", "P"}, {"day", 0}};

    cout << j.dump(4) << endl;
}
