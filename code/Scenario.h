//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_SCENARIO_H
#define NRS_SCENARIO_H

#include "json.hpp"
#include "ShiftType.h"
#include "Contract.h"
#include "Nurse.h"
#include <vector>

using namespace std;
using json = nlohmann::json;

class Scenario {
private:
    string id;
    int numberOfWeeks;
    vector<ShiftType> shifts;
    vector<string> skills;
    vector<Contract> contracts;
    vector<Nurse> nurses;

    void parseShiftTypes(const json &j);
    void parseForbiddenShiftTypeSuccessions(const json &j);
    void parseContracts(const json &j);
    void parseNurses(const json &j);
public:
    Scenario(const string &path);
};


#endif //NRS_SCENARIO_H
