#include <iostream>
using namespace std;

struct student {
int studentID;
string name;
string course;
double gpa;
};

int main () {

    int num = 0;
    char choice;
    do{
        system("cls");

        cout << "Enter number of students: ";
        cin >> num;
        cout << endl;

        student arr[num];

        for (int i=0; i < num; i++){
            cout << "Student " << i+1 << endl;

            bool duplicate;
            do {
                duplicate = false;
                cout << "Enter student ID: ";
                cin >> arr[i].studentID;
                cin.ignore();

                for (int j = 0; j < i; j++) {
                    if (arr[j].studentID == arr[i].studentID) {
                        duplicate = true;
                        cout << "ID " << arr[i].studentID << " already exists. Please enter another ID." << endl << endl;
                        break;
                    }
                }
            } while (duplicate);

            cout << "Enter student's name: ";
            getline(cin, arr[i].name);

            cout << "Enter course: ";
            getline(cin, arr[i].course);

            cout << "Enter GPA [0-100]: ";
            cin >> arr[i].gpa;
            cin.ignore();

            cout << endl;

        }

        cout << "==================================" << endl << endl;

        //output
        for (int i=0; i < num; i++){
            cout << "Student " << i+1 << endl;
            cout << "ID: " << arr[i].studentID << endl;
            cout << "Name: " << arr[i].name << endl;
            cout << "Course: " << arr[i].course << endl;
            cout << "GPA: " << arr[i].gpa << endl;
            cout << "Academic Standing: ";

            if (arr[i].gpa >= 90){
                cout << "Excellent" << endl;
            } else if (arr[i].gpa >= 80){
                cout << "Very Good" << endl;
            } else if (arr[i].gpa >= 70){
                cout << "Good" << endl;
            } else if (arr[i].gpa >= 60){
                cout << "Passing" << endl;
            } else if (arr[i].gpa > 60){
                cout << "Failed" << endl;
            }

            cout << endl;
        }

        cout << endl << "Do you want to try again [y/n]: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');


    return 0;
}
