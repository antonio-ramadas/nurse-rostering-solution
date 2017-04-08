//
// Created by António Ramadas on 08/04/2017.
//

#ifndef NRS_PARSER_H
#define NRS_PARSER_H

#include "json.hpp"
using json = nlohmann::json;

#include "Scenario.h"

class Parser {
public:
    static json ReadJSONFile(const string &path);
};


#endif //NRS_PARSER_H
