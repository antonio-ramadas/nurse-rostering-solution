//
// Created by António Ramadas on 21/05/2017.
//

#include "InputParser.h"

InputParser::InputParser (int &argc, char **argv){
    for (int i=1; i < argc; ++i)
        this->tokens.push_back(string(argv[i]));
}

/// @author iain
/// @edit antonio_ramadas - remove quotes from the first and last character, if present, from argument
const string InputParser::getCmdOption(const string &option) const{
    vector<string>::const_iterator itr;
    itr =  find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        const string &cmdOption = *itr;
        string ret(cmdOption);

        if (ret.at(0) == '"' && ret.at(ret.size()-1) == '"')
            ret = ret.substr(1, ret.size()-2);

        return ret;
    }
    static const string empty_string("");
    return empty_string;
}

/// @author iain
bool InputParser::cmdOptionExists(const string &option) const{
    return find(this->tokens.begin(), this->tokens.end(), option)
           != this->tokens.end();
}
