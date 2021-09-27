//
// Created by clinton schultz on 3/7/21.
//
#include <string>

using namespace std;

#ifndef SINGLETONASSIGNMENT_GRADE_H
#define SINGLETONASSIGNMENT_GRADE_H

class Grade {
    public:
        // Overloaded constructor
        Grade(int, int, double, string);
        int getPointsEarned() const;
        int setPointsEarned(int earnedPoints);

        int getTotalPoints() const;
        int setTotalPoints(int pointsTotal);

        double getWeight() const;
        double setWeight(double newWeight);

        string getAssignment() const;
        string setAssignment(string newAssignment);

    private:
        int pointsEarned, totalPoints;
        double weight;
        string assignment;
};

#endif //SINGLETONASSIGNMENT_GRADE_H
