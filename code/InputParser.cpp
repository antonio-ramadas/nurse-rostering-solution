//
// Created by António Ramadas on 21/05/2017.
//

#include <algorithm>
#include "InputParser.h"

InputParser::InputParser (int &argc, char **argv){
    for (int i=1; i < argc; ++i)
        this->tokens.push_back(string(argv[i]));
}

/// @author iain
/// @edit antonio_ramadas - remove quotes from the first and last character, if present, from argument
const string InputParser::getCmdOption(const string &option) {
    vector<string>::const_iterator itr;

    itr =  find(this->tokens.begin(), this->tokens.end(), option);

    if (itr != this->tokens.end() && ++itr != this->tokens.end())
        return removeQuotes(*itr);

    return "";
}

/// @author iain
bool InputParser::cmdOptionExists(const string &option) const{
    return find(this->tokens.begin(), this->tokens.end(), option)
           != this->tokens.end();
}

string InputParser::removeQuotes(const string &sentence) {
    string ret(sentence);

    if (ret.at(0) == '"' && ret.at(ret.size()-1) == '"')
        ret = ret.substr(1, ret.size()-2);

   return ret;
}
