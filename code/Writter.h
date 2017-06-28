//
// Created by António Ramadas on 19/05/2017.
//

#ifndef NRS_WRITTER_H
#define NRS_WRITTER_H

#include "json.hpp"
#include "solution/Solution.h"

using json = nlohmann::json;

#include <string>
using namespace std;

class Writter {
public:
    static string solPath;
    static void WriteSolutionToJSONFile(const Solution *solution, string path = "");
};


#endif //NRS_WRITTER_H
