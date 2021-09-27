//
// Created by clinton schultz on 3/9/21.
//
#include <string>
#include <vector>
#include <iostream>

#include "Student.h"
#include "Logger.h"

using namespace std;

// Generic constructor
Student::Student()
{

}

// Overloaded constructor
Student::Student(int id, string n) : uniqueID(id), name(n)
{

}

// The Big Three
Student::~Student()             // destructor
{
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] != nullptr)
        {
           delete grades[i];
        }
    }
}

Student::Student(const Student & rhs) : uniqueID(rhs.uniqueID), name(rhs.name)   // copy constructor
{
    grades.clear();
    for (int i = 0; i < rhs.grades.size(); i++)
    {
        Grade* g = rhs.grades[i];
        grades.push_back(new Grade(g->getPointsEarned(), g->getTotalPoints(), g->getWeight(), g->getAssignment()));
    }
}

const Student & Student::operator=(const Student & rhs)
{
    if (this != &rhs) {
        grades.clear();
        uniqueID = rhs.uniqueID;
        name = rhs.name;
        for (int i = 0; i < rhs.grades.size(); i++) {
            Grade* g = rhs.grades[i];
            grades.push_back(new Grade(g->getPointsEarned(), g->getTotalPoints(), g->getWeight(), g->getAssignment()));
        }
    }
    return *this;
}

// Getters and setters
int Student::getUniqueID() const
    { return uniqueID; }

void Student::setUniqueID(int id)
    { uniqueID = id; }

string Student::getName() const
    { return name; }

void Student::setName(string n)
    { name = n; }

vector<Grade*> Student::getGrades() const
    { return grades; }

void Student::setGrades(const vector<Grade*> &g) {
    grades.clear();
    for (int i = 0; i < g.size(); i++) {
        Grade *gr = g[i];
        grades.push_back(new Grade(gr->getPointsEarned(), gr->getTotalPoints(), gr->getWeight(), gr->getAssignment()));
    }
}

// Member functions
// Calculate grade and return an integer between 0 - 100
double Student::calculateFinal()
{
    double finalGrade;
    double weightSum;
    for (int i = 0; i < grades.size(); i++) {
        double grade = (double(grades[i]->getPointsEarned())/double(grades[i]->getTotalPoints()));
        finalGrade +=  grade * grades[i]->getWeight();
        weightSum += grades[i]->getWeight();
        log.log("Weight Sum: " + to_string(weightSum));
        log.log("Final Grade: " + to_string(finalGrade));
    }
    if (weightSum == 0.0) { weightSum = 1.0; }
    return (finalGrade/weightSum) * 100.0;
}

// Return the corresponding letter grade for the previously calculated score
string Student::calculateLetterGrade() {
    string letterGrade = "NA";

    if (grades.empty())
    {
        return letterGrade;
    }

    int grade = calculateFinal();
    log.log("Final grade: " + to_string(grade));

    if (grade < 60) { letterGrade = "F"; }
    if (grade >= 60 && grade <= 73) { letterGrade = "D-"; }
    if (grade >= 64 && grade <= 66) { letterGrade = "D"; }
    if (grade >= 67 && grade <= 70) { letterGrade = "D+"; }
    if (grade > 70 && grade <= 73) { letterGrade = "C-"; }
    if (grade >= 74 && grade <= 76) { letterGrade = "C"; }
    if (grade >= 77 && grade <= 80) { letterGrade = "C+"; }
    if (grade > 80 && grade <= 83) { letterGrade = "B-"; }
    if (grade >= 84 && grade <= 86) { letterGrade = "B"; }
    if (grade >= 87 && grade <= 90) { letterGrade = "B+"; }
    if (grade > 90 && grade <= 93) { letterGrade = "A-"; }
    if (grade >= 94 && grade <= 96) { letterGrade = "A"; }
    if (grade >= 97) { letterGrade = "A+"; }

    return letterGrade;
}

// Return a string report
void Student::printReport()
{
    string output = getName() + " with ID Number: " + to_string(getUniqueID()) + " ended with a " + calculateLetterGrade();
    log.log(output);
    for (int i = 0; i < grades.size(); i++) {
        log.log(grades[i]->getAssignment() + " "
        + to_string(grades[i]->getTotalPoints()) + " "
        + to_string(grades[i]->getPointsEarned()) + " "
        + to_string(grades[i]->getWeight()));
   }
}
