//
// Created by António Ramadas on 02/03/2017.
//

#ifndef NRS_NURSE_H
#define NRS_NURSE_H

#include <string>
#include <vector>

using namespace std;

class Nurse {
private:
    string id, contract;
    vector<string> skills;
public:
    Nurse(const string &id, const string &contract, const vector<string> &skills);
};


#endif //NRS_NURSE_H
