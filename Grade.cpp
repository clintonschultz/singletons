//
// Created by clinton schultz on 3/7/21.
//
#include <string>

#include "Grade.h"

using namespace std;

// Overloaded constructor
Grade::Grade(int pe, int tp, double w, string a) :
    pointsEarned(pe),
    totalPoints(tp),
    weight(w),
    assignment(a)
{

}

// Getters and Setters
int Grade::getPointsEarned() const
    { return pointsEarned; }

int Grade::setPointsEarned(int earnedPoints)
    { pointsEarned = earnedPoints; }

int Grade::getTotalPoints() const
    { return totalPoints; }

int Grade::setTotalPoints(int pointsTotal)
    { totalPoints = pointsTotal; }

double Grade::getWeight() const
    { return weight; }

double Grade::setWeight(double newWeight)
    { weight = newWeight; }

string Grade::getAssignment() const
    { return assignment; }

string Grade::setAssignment(string newAssignment)
    { assignment = newAssignment; }