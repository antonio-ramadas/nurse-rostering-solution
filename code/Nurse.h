//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_NURSE_H
#define NRS_NURSE_H

#include <string>
#include <vector>
#include "History.h"

using namespace std;

class Nurse {
private:
    string id, contract;
    vector<string> skills;
    History history;
public:
    Nurse(const string &id, const string &contract, const vector<string> &skills);

    const bool hasSkill(const string &skill) const;

    const string &getId() const;

    void setId(const string &id);

    const string &getContract() const;

    void setContract(const string &contract);

    const vector<string, allocator<string>> &getSkills() const;

    void setSkills(const vector<string, allocator<string>> &skills);

    const History &getHistory() const;

    void setHistory(const History &history);
};


#endif //NRS_NURSE_H
