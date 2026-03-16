#include <iostream>
using namespace std;

void computeGrades(int* grades, int students, int subjects) {

    cout << "\n--- GRADE MATRIX ---" << endl;
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < subjects; j++) {
            cout << *(grades + i * subjects + j) << " ";
        }
        cout << endl;
    }

    cout << "\n--- AVERAGE PER STUDENT ---" << endl;
    for (int i = 0; i < students; i++) {
        double sum = 0;
        for (int j = 0; j < subjects; j++)
            sum += *(grades + i * subjects + j);
        cout << "Student " << i + 1
             << " Average: " << sum / subjects << endl;
    }

    int highest = *(grades);
    for (int i = 0; i < students; i++)
        for (int j = 0; j < subjects; j++)
            if (*(grades + i * subjects + j) > highest)
                highest = *(grades + i * subjects + j);

    cout << "\n--- HIGHEST GRADE ---" << endl;
    cout << "Highest: " << highest << endl;
}


int main() {

    int students, subjects;

    cout << "Enter number of students: "; cin >> students;
    cout << "Enter number of subjects: "; cin >> subjects;

    int grades[students][subjects];

    for (int i = 0; i < students; i++) {
        cout << "\nStudent " << i + 1 << " grades:" << endl;
        for (int j = 0; j < subjects; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin  >> grades[i][j];
        }
    }

    computeGrades(&grades[0][0], students, subjects);

    return 0;
}
