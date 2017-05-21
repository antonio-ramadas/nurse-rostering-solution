//
// Created by António Ramadas on 21/05/2017.
//

#ifndef NRS_INPUTPARSER_H
#define NRS_INPUTPARSER_H

#include "string"
#include "vector"

using namespace std;

class InputParser {
    public:
        InputParser (int &argc, char **argv);

        /// @author iain
        const string& getCmdOption(const string &option) const;

        /// @author iain
        bool cmdOptionExists(const string &option) const;
    private:
        vector <string> tokens;
};


#endif //NRS_INPUTPARSER_H
