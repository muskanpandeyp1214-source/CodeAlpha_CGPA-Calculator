#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Function to convert letter grade to grade points
double gradeToPoint(string grade) {
    if (grade == "A+" || grade == "a+") return 4.0;
    if (grade == "A"  || grade == "a")  return 4.0;
    if (grade == "A-" || grade == "a-") return 3.7;
    if (grade == "B+" || grade == "b+") return 3.3;
    if (grade == "B"  || grade == "b")  return 3.0;
    if (grade == "B-" || grade == "b-") return 2.7;
    if (grade == "C+" || grade == "c+") return 2.3;
    if (grade == "C"  || grade == "c")  return 2.0;
    if (grade == "C-" || grade == "c-") return 1.7;
    if (grade == "D+" || grade == "d+") return 1.3;
    if (grade == "D"  || grade == "d")  return 1.0;
    if (grade == "D-" || grade == "d-") return 0.7;
    if (grade == "F"  || grade == "f")  return 0.0;
    return -1; // Invalid grade
}

int main() {
    int numCourses;
    int numSemesters;
    double totalCGPA = 0.0;

    cout << "========================================" << endl;
    cout << "       CGPA CALCULATOR" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Enter number of semesters: ";
    cin >> numSemesters;
    cout << endl;

    vector<double> semesterGPAs;
    double grandTotalGradePoints = 0.0;
    double grandTotalCredits = 0.0;

    for (int s = 1; s <= numSemesters; s++) {
        cout << "----------------------------------------" << endl;
        cout << "  SEMESTER " << s << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter number of courses: ";
        cin >> numCourses;
        cout << endl;

        vector<string> courseGrades(numCourses);
        vector<int> courseCredits(numCourses);
        double semesterGradePoints = 0.0;
        double semesterCredits = 0.0;

        for (int i = 0; i < numCourses; i++) {
            string grade;
            int credits;

            cout << "Course " << i + 1 << ":" << endl;
            cout << "  Enter letter grade (e.g. A, B+, C-, F): ";
            cin >> grade;

            double points = gradeToPoint(grade);
            while (points < 0) {
                cout << "  Invalid grade. Try again: ";
                cin >> grade;
                points = gradeToPoint(grade);
            }

            cout << "  Enter credit hours: ";
            cin >> credits;
            while (credits <= 0) {
                cout << "  Credit hours must be positive. Try again: ";
                cin >> credits;
            }

            courseGrades[i] = grade;
            courseCredits[i] = credits;

            semesterGradePoints += points * credits;
            semesterCredits += credits;

            cout << endl;
        }

        double semesterGPA = semesterGradePoints / semesterCredits;
        semesterGPAs.push_back(semesterGPA);
        grandTotalGradePoints += semesterGradePoints;
        grandTotalCredits += semesterCredits;

        // Display semester results
        cout << "  Semester " << s << " Report:" << endl;
        cout << "  ----------------------------------" << endl;
        cout << setw(12) << left << "  Course"
             << setw(10) << "Grade"
             << setw(10) << "Credits"
             << "Grade Points" << endl;
        cout << "  ----------------------------------" << endl;

        for (int i = 0; i < numCourses; i++) {
            double pts = gradeToPoint(courseGrades[i]);
            cout << "  " << setw(11) << left << ("Course " + to_string(i + 1))
                 << setw(10) << courseGrades[i]
                 << setw(10) << courseCredits[i]
                 << fixed << setprecision(2) << (pts * courseCredits[i]) << endl;
        }

        cout << "  ----------------------------------" << endl;
        cout << "  Total Credits:       " << semesterCredits << endl;
        cout << "  Total Grade Points:  " << fixed << setprecision(2) << semesterGradePoints << endl;
        cout << "  Semester GPA:        " << fixed << setprecision(2) << semesterGPA << endl;
        cout << endl;
    }

    // Calculate and display CGPA
    totalCGPA = grandTotalGradePoints / grandTotalCredits;

    cout << "========================================" << endl;
    cout << "  OVERALL RESULT" << endl;
    cout << "========================================" << endl;

    for (int s = 0; s < numSemesters; s++) {
        cout << "  Semester " << s + 1 << " GPA:  "
             << fixed << setprecision(2) << semesterGPAs[s] << endl;
    }

    cout << "  ----------------------------------" << endl;
    cout << "  Total Credits Earned:  " << grandTotalCredits << endl;
    cout << "  Total Grade Points:    " << fixed << setprecision(2) << grandTotalGradePoints << endl;
    cout << "  CGPA:                  " << fixed << setprecision(2) << totalCGPA << endl;
    cout << "========================================" << endl;

    return 0;
}
q