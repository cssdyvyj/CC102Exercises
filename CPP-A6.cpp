#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error: Could not open file \"" << filename << "\"" << endl;
        return -1;
    }

    int count = 0;
    int number;

    while (inFile >> number) {
        if (isPrime(number)) {
            count++;
        }
    }

    inFile.close();
    return count;
}

int main() {
    int primeCount = countPrimes("NUMS.TXT");

    if (primeCount >= 0) {
        cout << "Number of prime numbers found: " << primeCount << endl;
    }

    return 0;
}
