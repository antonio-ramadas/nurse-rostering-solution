//
// Created by António Ramadas on 21/05/2017.
//

#include "InputParser.h"

InputParser::InputParser (int &argc, char **argv){
    for (int i=1; i < argc; ++i)
        this->tokens.push_back(string(argv[i]));
}

/// @author iain
const string& InputParser::getCmdOption(const string &option) const{
    vector<string>::const_iterator itr;
    itr =  find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }
    static const string empty_string("");
    return empty_string;
}

/// @author iain
bool InputParser::cmdOptionExists(const string &option) const{
    return find(this->tokens.begin(), this->tokens.end(), option)
           != this->tokens.end();
}
