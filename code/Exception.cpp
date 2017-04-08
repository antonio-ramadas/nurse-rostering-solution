//
// Created by António Ramadas on 08/04/2017.
//

#include <ostream>
#include <iostream>
#include "Exception.h"


Exception::Exception(ExceptionsEnum exception, const string &msg) {
    this->exception = exception;
    this->msg = msg;
}

void Exception::printErr() {
    cerr << string("Exception ") << getEnumValue(exception);

    if (!msg.empty())
        cerr << string("; MSG = ") << msg;

    cerr << endl;
}

string Exception::getEnumValue(const ExceptionsEnum &exception)
{
    string match = "";
   switch(exception)
   {
      case ExceptionsEnum::FileNotFound: match = "File Not Found"; break;
       default: match = "Missing Exception Name Assignment"; break;
   }

   return match;
}