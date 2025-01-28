#include "ExpenseTracker.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void ExpenseTracker::addExpense(const string& category, double amount, const string& date) {
    expenses.emplace_back(category, amount, date);
    cout << "Expense added successfully.\n";
}
void ExpenseTracker::generateReport() const {
    map<string, double> categoryTotals;
    map<string, double> monthlyTotals;

    for (const auto& expense : expenses) {
        categoryTotals[expense.category] += expense.amount;
        string month = expense.date.substr(0, 7); // Extract YYYY-MM
        monthlyTotals[month] += expense.amount;
    }

    cout << "\nCategory-wise Expense Report:\n";
    for (const auto& [category, total] : categoryTotals) {
        cout << " - " << category << ": $" << fixed << setprecision(2) << total << '\n';
    }

    cout << "\nMonthly Expense Report:\n";
    for (const auto& [month, total] : monthlyTotals) {
        cout << " - " << month << ": $" << fixed << setprecision(2) << total << '\n';
    }
}
void ExpenseTracker::viewExpensesSortedByDate() const {
    auto sortedExpenses = expenses;
    sort(sortedExpenses.begin(), sortedExpenses.end(),
        [](const Expense& a, const Expense& b) { return a.date < b.date; });

    cout << "Expenses sorted by date:\n";
    for (const auto& expense : sortedExpenses) {
        cout << expense.date << " - " << expense.category << " - $" << expense.amount << '\n';
    }
}

void ExpenseTracker::viewExpensesSortedByAmount() const {
    auto sortedExpenses = expenses;
    sort(sortedExpenses.begin(), sortedExpenses.end(),
        [](const Expense& a, const Expense& b) { return a.amount < b.amount; });

    cout << "Expenses sorted by amount:\n";
    for (const auto& expense : sortedExpenses) {
        cout << expense.date << " - " << expense.category << " - $" << expense.amount << '\n';
    }
}

void ExpenseTracker::viewExpensesByCategory(const string& category) const {
    cout << "Expenses in category '" << category << "':\n";
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            cout << expense.date << " - $" << expense.amount << '\n';
        }
    }
}

void ExpenseTracker::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }
    for (const auto& expense : expenses) {
        file << expense.date << "," << expense.category << "," << expense.amount << '\n';
    }
    file.close();
    cout << "Expenses saved to file.\n";
}

void ExpenseTracker::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file for reading.\n";
        return;
    }
    expenses.clear();
    string date, category;
    double amount;
    char delimiter;
    while (file >> date >> delimiter >> category >> delimiter >> amount) {
        expenses.emplace_back(category, amount, date);
    }
    file.close();
    cout << "Expenses loaded from file.\n";
}