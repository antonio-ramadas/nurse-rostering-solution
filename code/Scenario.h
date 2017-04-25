//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_SCENARIO_H
#define NRS_SCENARIO_H

#include "ShiftType.h"
#include "Contract.h"
#include "Nurse.h"
#include "Reader.h"
#include "Exception.h"
#include <fstream>
#include <vector>

using namespace std;

class Scenario {
private:
    string id;
    int numberOfWeeks;
    vector<ShiftType> shifts;
    vector<string> skills;
    map<string,Contract> contracts;
    vector<Nurse> nurses;

    void parseShiftTypes(const json &j);
    void parseForbiddenShiftTypeSuccessions(const json &j);
    void parseContracts(const json &j);
    void parseNurses(const json &j);

    Nurse & findNurse(const string &name);
public:
    Scenario(const string &path);
    void parseHistory(const string &path);

    const vector<ShiftType> &getShifts() const;

    const vector<string> &getSkills() const;
};


#endif //NRS_SCENARIO_H
