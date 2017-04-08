//
// Created by António Ramadas on 08/04/2017.
//

#ifndef NRS_EXCEPTION_H
#define NRS_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

enum ExceptionsEnum {FileNotFound};

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
