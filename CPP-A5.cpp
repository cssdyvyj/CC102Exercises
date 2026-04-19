#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ofstream outFile("original.txt");

    if (!outFile) {
        cout << "Error: Could not create original.txt" << endl;
        return 1;
    }

    outFile << "One"   << endl;
    outFile << "Two"   << endl;
    outFile << "Three" << endl;
    outFile << "Four"  << endl;
    outFile << "Five"  << endl;
    outFile << "Six"   << endl;

    outFile.close();
    cout << "original.txt written successfully." << endl;

    ifstream inFile("original.txt");

    if (!inFile) {
        cout << "Error: Could not open original.txt for reading." << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");

    if (!sortedFile) {
        cout << "Error: Could not create sorted.txt" << endl;
        return 1;
    }

    for (int i = 0; i < words.size(); i++) {
        sortedFile << words[i] << endl;
    }

    sortedFile.close();
    cout << "sorted.txt written successfully." << endl;

    ifstream showOriginal("original.txt");
    ifstream showSorted("sorted.txt");

    if (!showOriginal || !showSorted) {
        cout << "Error: Could not open files for display." << endl;
        return 1;
    }

    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "  original.txt  |  sorted.txt" << endl;
    cout << "-----------------------------" << endl;

    string origLine, sortLine;
    while (getline(showOriginal, origLine) && getline(showSorted, sortLine)) {
        cout << "  " << origLine;
        for (int j = origLine.length(); j < 14; j++) cout << " ";
        cout << "|  " << sortLine << endl;
    }

    cout << "-----------------------------" << endl;

    showOriginal.close();
    showSorted.close();

    return 0;
}
