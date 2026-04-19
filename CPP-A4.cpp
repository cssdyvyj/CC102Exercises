#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("color.txt");

    if (!outFile) {
        cout << "Error: Could not create color.txt" << endl;
        return 1;
    }

    outFile << "Red"    << endl;
    outFile << "Blue"   << endl;
    outFile << "Green"  << endl;
    outFile << "Yellow" << endl;
    outFile << "Purple" << endl;
    outFile << "Orange" << endl;
    outFile << "White"  << endl;

    outFile.close();
    cout << "color.txt written successfully." << endl;

    ifstream inFile("color.txt");

    if (!inFile) {
        cout << "Error: Could not open color.txt for reading." << endl;
        return 1;
    }

    ofstream copyFile("color_copy.txt");

    if (!copyFile) {
        cout << "Error: Could not create color_copy.txt" << endl;
        inFile.close();
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();
    cout << "color_copy.txt created successfully." << endl;

    ifstream verifyOriginal("color.txt");
    ifstream verifyCopy("color_copy.txt");

    if (!verifyOriginal || !verifyCopy) {
        cout << "Error: Could not open files for display." << endl;
        return 1;
    }

    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "  color.txt   |  color_copy.txt" << endl;
    cout << "-----------------------------" << endl;

    string origLine, copyLine;
    while (getline(verifyOriginal, origLine) && getline(verifyCopy, copyLine)) {
        cout << "  " << origLine;
        for (int j = origLine.length(); j < 12; j++) cout << " ";
        cout << "|  " << copyLine << endl;
    }

    cout << "-----------------------------" << endl;
    cout << endl;
    cout << "File copy completed. Both files match." << endl;

    verifyOriginal.close();
    verifyCopy.close();

    return 0;
}
