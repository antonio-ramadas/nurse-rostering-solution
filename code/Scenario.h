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
#include "WeekData.h"
#include <fstream>
#include <vector>

using namespace std;

class Scenario {
private:
    static Scenario* scenario;
    Scenario();

    string id;
    int currentWeek;
public:
    int getCurrentWeek() const;

private:
    int numberOfWeeks;
    map<string,ShiftType> shifts;
    vector<string> skills;
    map<string,Contract> contracts;
    vector<Nurse> nurses;

    WeekData weekData;

    const vector<string> DaysOfTheWeekVector {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    void parseShiftTypes(const json &j);
    void parseForbiddenShiftTypeSuccessions(const json &j);
    void parseContracts(const json &j);
    void parseNurses(const json &j);

    Nurse & findNurse(const string &name);
public:
    static Scenario* getInstance();

    void parseScenario(const string &path);

    void parseHistory(const string &path);

    map<string,ShiftType> &getShifts();

    const vector<string> &getSkills() const;

    const vector<Nurse> &getNurses() const;

    int getNumberOfWeeks() const;

    const WeekData &getWeekData() const;

    void setWeekData(const WeekData &weekData);

    const vector<string> &getDaysOfTheWeekVector();

    const int getDayOfWeek(const string);

    const Contract getContract(const string contract);
};


#endif //NRS_SCENARIO_H
