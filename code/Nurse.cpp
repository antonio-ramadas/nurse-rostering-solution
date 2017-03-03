//
// Created by António Ramadas on 02/03/2017.
//

#include "Nurse.h"

Nurse::Nurse(const string &id, const string &contract, const vector<string> &skills) {
    this->id = id;
    this->contract = contract;
    this->skills = skills;
}