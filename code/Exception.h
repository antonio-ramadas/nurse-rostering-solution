//
// Created by António Ramadas on 08/04/2017.
//

#ifndef NRS_EXCEPTION_H
#define NRS_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

//TODO improve this situation
// Every time a new exception is added, a case clause needs to be
// added to the switch case inside getEnumValue function
enum ExceptionsEnum {FileNotFound, NurseNotFound};

class Exception : private std::exception {
private:
    ExceptionsEnum exception;
    string msg = "";

    string getEnumValue(const ExceptionsEnum &exception);

public:
    Exception(ExceptionsEnum exception, const string &msg = "");
    void printErr();
};

#endif //NRS_EXCEPTION_H
