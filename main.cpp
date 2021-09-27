#include <iostream>

#include "Grade.h"
#include "Student.h"

using namespace std;

int main() {

    Grade* g1 = new Grade(27, 30, 10, "Math Quiz");
    Grade* g2 = new Grade(25, 30, 20, "History Quiz");

    Student s1(2512, "Gerome");
    vector<Grade*> grades;
    vector<Grade*> noGrades;
    grades.push_back(g1);
    grades.push_back(g2);
    s1.setGrades(grades);

    Student s2(s1);
    s1.setGrades(noGrades);

    Student s3(3214, "Stacey");
    // s3 = s2;

    // Student class tests
    cout << "Student 1: " << endl;
    s1.printReport();
    cout << "Student 2: " << endl;
    s2.printReport();
    cout << "Student 3: " << endl;
    s3.printReport();

    return 0;
}
