//TASK 1 : CGPA Calculator 
//● Take input for the number of courses taken by the student.
//● For each course, input the grade and the credit hours. 
//● Calculate the total credits and total grade points (grade × credit hours). 
//● Compute the GPA for the semester and then the overall CGPA. 
//● Display individual course grades and the final CGPA to the user.

#include <iostream>
using namespace std;

// Function to calculate grade points
float getGradePoints(char grade) {
    if (grade == 'A' || grade == 'a') return 4.0;
    else if (grade == 'B' || grade == 'b') return 3.0;
    else if (grade == 'C' || grade == 'c') return 2.0;
    else if (grade == 'D' || grade == 'd') return 1.0;
    else return 0.0;
}

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    float totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < numCourses; i++) {
        char grade;
        float credits;
        cout << "Enter grade for course " << i + 1 << " (A/B/C/D): ";
        cin >> grade;
        cout << "Enter credits for course " << i + 1 << ": ";
        cin >> credits;

        float gradePoints = getGradePoints(grade) * credits;
        totalGradePoints += gradePoints;
        totalCredits += credits;

        cout << "\nCourse " << i + 1 << ": Grade = " << grade << ", Credits = " << credits << endl;
    }

    float gpa = totalGradePoints / totalCredits;
    cout << "GPA for the semester: " << gpa << endl;
    cout << "CGPA: " << gpa << endl; // Assuming single semester

    return 0;
}
