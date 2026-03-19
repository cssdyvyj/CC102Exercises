#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    double gpa;
};

string getStanding(double gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

string fit(string str, int width) {
    if ((int)str.length() > width)
        return str.substr(0, width - 2) + "..";
    return str;
}

int main() {
    int num = 0;
    char choice;

    do {
        system("cls");
        cout << "Enter number of students: ";
        cin >> num;
        cout << endl;

        student arr[num];

        for (int i = 0; i < num; i++) {
            cout << "Student " << i + 1 << endl;

            bool duplicate;
            do {
                duplicate = false;
                cout << "Enter student ID: ";
                cin >> arr[i].studentID;
                cin.ignore();
                for (int j = 0; j < i; j++) {
                    if (arr[j].studentID == arr[i].studentID) {
                        duplicate = true;
                        cout << "ID already exists. Try another." << endl;
                        break;
                    }
                }
            } while (duplicate);

            cout << "Enter name: ";
            getline(cin, arr[i].name);
            cout << "Enter course: ";
            getline(cin, arr[i].course);
            cout << "Enter GPA [0-100]: ";
            cin >> arr[i].gpa;
            cin.ignore();
            cout << endl;
        }

        system("cls");

        cout << left
             << setw(6)  << "ID"
             << setw(20) << "Name"
             << setw(15) << "Course"
             << setw(8)  << "GPA"
             << setw(12) << "Standing"
             << endl;

        cout << string(61, '-') << endl;

        // Table rows
        for (int i = 0; i < num; i++) {
            cout << left
                 << setw(6)  << arr[i].studentID
                 << setw(20) << fit(arr[i].name, 18)
                 << setw(15) << fit(arr[i].course, 13)
                 << setw(8)  << fixed << setprecision(2) << arr[i].gpa
                 << setw(12) << getStanding(arr[i].gpa)
                 << endl;
        }

        cout << string(61, '-') << endl;

        cout << "\nTry again? [y/n]: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
