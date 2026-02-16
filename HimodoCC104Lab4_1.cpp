#include <iostream>
using namespace std;

int main() {

    char choice;

    do {
        int student, quiz;

        cout << "Enter number of students: ";
        cin >> student;

        cout << "Enter number of quizzes per student: ";
        cin >> quiz;

        int matrix[student][quiz];

        for (int i = 0; i < student; i++) {
            cout << endl << "Enter scores for Student " << i + 1 << ": ";
            cout << endl;
            for (int j = 0; j < quiz; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> matrix[i][j];
            }
        }

        cout << endl << endl;
        cout << "RESULT TABLE"<< endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Student\t\t";

        for (int j = 0; j < quiz; j++) {
            cout << "Quiz " << j + 1 << "\t\t";
        }
        cout << "Average";
        cout << endl << "-------------------------------------------------------------------------------------------------------------------"<< endl;

        for (int i = 0; i < student; i++) {
            cout << "Student " << i + 1 << "\t";
            double sum = 0;

            for (int j = 0; j < quiz; j++) {
                cout << matrix[i][j] << "\t\t";
                sum += matrix[i][j];
            }

            double average = sum / quiz;
            cout << average;

            cout << endl;
        }

        cout << endl << "-------------------------------------------------------------------------------------------------------------------"<< endl;

        cout << endl;
        cout << "Would you like to run the program again? (Y/N): ";
        cin >> choice;

        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you!";
    cout << endl;

    return 0;
}
