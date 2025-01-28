#include "ExpenseTracker.h"
#include <iostream>

using namespace std;

int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        cout << "\nEnter One of the corresponding number choices\n";
        cout << "\nPersonal Expense Tracker\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses by Date\n";
        cout << "3. View Expenses by Amount\n";
        cout << "4. View Expenses by Category\n";
        cout << "5. Save Expenses to File\n";
        cout << "6. Load Expenses from File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string category, date;
            double amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            tracker.addExpense(category, amount, date);
        } else if (choice == 2) {
            tracker.viewExpensesSortedByDate();
        } else if (choice == 3) {
            tracker.viewExpensesSortedByAmount();
        } else if (choice == 4) {
            string category;
            cout << "Enter category: ";
            cin >> category;
            tracker.viewExpensesByCategory(category);
        } else if (choice == 5) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            tracker.saveToFile(filename);
        } else if (choice == 6) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            tracker.loadFromFile(filename);
        }
    } while (choice != 7);

    return 0;
}