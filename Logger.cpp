//
// Created by clinton schultz on 3/9/21.
//

#include <string>
#include <iostream>

using namespace std;

#include "Logger.h"

Logger::Logger()
{

}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(string output)
{
    cout << output << endl;
}


