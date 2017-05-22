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
        /// @edit antonio_ramadas - remove quotes from the first and last character, if present, from argument
        const string getCmdOption(const string &option);

        /// @author iain
        bool cmdOptionExists(const string &option) const;
    private:
        vector <string> tokens;

        /// @author antonio_ramadas
        string removeQuotes(const string &sentence);
};


#endif //NRS_INPUTPARSER_H
