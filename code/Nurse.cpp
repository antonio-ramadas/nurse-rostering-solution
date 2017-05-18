//
// Created by António Ramadas on 02/03/2017.
//

#include <iostream>
#include "Nurse.h"

Nurse::Nurse(const string &id, const string &contract, const vector<string> &skills) {
    this->id = id;
    this->contract = contract;
    this->skills = skills;
}

const string &Nurse::getId() const {
    return id;
}

void Nurse::setId(const string &id) {
    Nurse::id = id;
}

const string &Nurse::getContract() const {
    return contract;
}

void Nurse::setContract(const string &contract) {
    Nurse::contract = contract;
}

const vector<string, allocator<string>> &Nurse::getSkills() const {
    return skills;
}

void Nurse::setSkills(const vector<string, allocator<string>> &skills) {
    Nurse::skills = skills;
}

const History &Nurse::getHistory() const {
    return history;
}

void Nurse::setHistory(const History &history) {
    Nurse::history = history;
}

const bool Nurse::hasSkill(const string &skill) const {
    return any_of(begin(skills), end(skills), [&](string skillElem) {
        return skill == skillElem;
    });
}
