//
// Created by António Ramadas on 08/04/2017.
//

#include <fstream>
#include "Reader.h"
#include "Exception.h"


json Reader::ReadJSONFile(const string &path) {
    ifstream i(path);

    if (!i.good()) {
        i.close();
        throw Exception(ExceptionsEnum::FileNotFound, path);
    }

    json j;
    i >> j; //deserialize
    i.close();

   return j;
}
