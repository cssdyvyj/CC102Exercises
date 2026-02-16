#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 2D array: rows = products (5), columns = salespeople (4)
    double sales[5][4];
    int salesperson, product;
    double amount;
    char continueInput, choice;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            sales[i][j] = 0;
        }
    }

    do {
        cout <<endl << "--- Monthly Sales Summary Program ---" << endl;
        cout << "Enter sales data for the month" << endl;
        cout << "-------------------------------------" <<endl << endl;


        do {

            cout << "Enter salesperson number [1-4]: ";
            cin >> salesperson;

            while (salesperson < 1 || salesperson > 4) {
                cout << "Invalid input! Enter 1-4: ";
                cin >> salesperson;
            }


            cout << "Enter product number [1-5]: ";
            cin >> product;

            while (product < 1 || product > 5) {
                cout << "Invalid input! Enter 1-5: ";
                cin >> product;
            }

            // Get amount
            cout << "Enter amount sold: ";
            cin >> amount;

            while (amount < 0) {
                cout << "Invalid! Amount cannot be negative: ";
                cin >> amount;
            }

            sales[product - 1][salesperson - 1] += amount;

            cout << endl << "Sale recorded!" << endl;

            cout << "Enter another sale? (Y/N): ";
            cin >> continueInput;
            cout << endl;

        } while (continueInput == 'Y' || continueInput == 'y');

        cout << endl << "======================================" << endl;
        cout << "         SALES REPORT" << endl;
        cout << "======================================" << endl << endl;

        cout << setw(10) << "Product";
        for (int sp = 1; sp <= 4; sp++) {
            cout << setw(12) << "Person " << sp;
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;

        for (int p = 0; p < 5; p++) {
            cout << setw(10) << "Product " << (p + 1);
            for (int sp = 0; sp < 4; sp++) {
                cout << setw(15) << fixed << setprecision(2) << sales[p][sp];
            }
            cout << endl;
        }

        cout << "\n\nTotal Sales per Product:" << endl;
        cout << "------------------------" << endl;

        double grandTotal = 0;

        for (int p = 0; p < 5; p++) {
            double rowTotal = 0;
            for (int sp = 0; sp < 4; sp++) {
                rowTotal += sales[p][sp];
            }
            cout << "Product " << (p + 1) << ": " << fixed << setprecision(2)
                 << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "\n\nTotal Sales per Salesperson:" << endl;
        cout << "----------------------------" << endl;

        for (int sp = 0; sp < 4; sp++) {
            double colTotal = 0;
            for (int p = 0; p < 5; p++) {
                colTotal += sales[p][sp];
            }
            cout << "Salesperson " << (sp + 1) << ": " << fixed << setprecision(2)
                 << colTotal << endl;
        }

        cout << "\n======================================" << endl;
        cout << "GRAND TOTAL: " << fixed << setprecision(2) << grandTotal << endl;
        cout << "======================================" << endl;

        // Reset array for next run
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                sales[i][j] = 0;
            }
        }

        cout << endl << endl<< "Run program again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you!" << endl;

    return 0;
}
