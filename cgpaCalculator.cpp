#include <bits/stdc++.h>

using namespace std;

int main() {
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> grades(numCourses);
    vector<int> credits(numCourses);
    vector<double> gradePoints(numCourses);

    double totalCredits = 0;
    double totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (O, A+, A, B+, B, C, F): ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> credits[i];

        // Convert grade to grade point
        if (grades[i] == "O")
            gradePoints[i] = 10;
        else if (grades[i] == "A+")
            gradePoints[i] = 9;
        else if (grades[i] == "A")
            gradePoints[i] = 8;
        else if (grades[i] == "B+")
            gradePoints[i] = 7;
        else if (grades[i] == "B")
            gradePoints[i] = 6;
        else if (grades[i] == "C")
            gradePoints[i] = 5;
        else
            gradePoints[i] = 0; // F grade

        totalCredits += credits[i];
        totalGradePoints += gradePoints[i] * credits[i];
    }

    // Calculate GPA / CGPA
    double cgpa = totalGradePoints / totalCredits;

    // Display result
    cout << "\n------ Course Details ------" << endl;

    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i]
             << " | Grade Point: " << gradePoints[i]
             << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << fixed << setprecision(2);
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}