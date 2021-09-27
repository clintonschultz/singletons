//
// Created by clinton schultz on 3/9/21.
//
#include <string>
#include <vector>

#include "Grade.h"
#include "Logger.h"

using namespace std;

#ifndef SINGLETONASSIGNMENT_STUDENT_H
#define SINGLETONASSIGNMENT_STUDENT_H


class Student {
    public:
        Student();

        Student(int, string);

        // The Big Three
        ~Student();             // destructor
        Student(const Student & rhs);    // copy constructor
        const Student & operator=(const Student & rhs);

        int getUniqueID() const;

        void setUniqueID(int id);

        string getName() const;

        void setName(string n);

        vector<Grade*> getGrades() const;

        void setGrades(const vector<Grade*> &g);

        // Calculate grade and return an integer between 0 - 100
        double calculateFinal();

        // Return the corresponding letter grade for the previously calculated score
        string calculateLetterGrade();

        void printReport();

private:
        int uniqueID;
        string name;
        vector<Grade*> grades;
        Logger log = Logger::getInstance();

};


#endif //SINGLETONASSIGNMENT_STUDENT_H
