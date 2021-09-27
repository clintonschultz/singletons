
#ifndef SINGLETONASSIGNMENT_LOGGER_H
#define SINGLETONASSIGNMENT_LOGGER_H

#include <string>

using namespace std;

class Logger
{
    private:
        Logger();

    public:
        static Logger& getInstance();
        void log(string output);
};

#endif //SINGLETONASSIGNMENT_LOGGER_H