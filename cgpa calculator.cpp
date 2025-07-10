#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Vectors for storing grades and credit hours
    vector<float> grades(numCourses);
    vector<int> creditHours(numCourses);

    float totalGradePoints = 0;
    int totalCredits = 0;

    // Input for courses
    for (int i = 0; i < numCourses; ++i) {
        cout << "\n Course " << i + 1 << ":\n";

        cout << "Enter grade (on 10-point scale): ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        // here calculating total grade points
        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

  // For Calculating CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display Results
    cout << "\n ----- Result Summary -----\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": Grade = " << grades[i]
             << ", Credit Hours = " << creditHours[i] << endl;
    }

    cout << fixed << setprecision(2); // format to 2 decimal places
    cout << "\n Final CGPA = " << cgpa << "\n";

    return 0;
}
