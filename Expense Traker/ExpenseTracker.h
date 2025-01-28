#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <string>
#include <vector>

struct Expense {
    std::string category;
    double amount;
    std::string date; 

    Expense(const std::string& cat, double amt, const std::string& dt)
        : category(cat), amount(amt), date(dt) {}
};

class ExpenseTracker {
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const std::string& category, double amount, const std::string& date);
    void viewExpensesSortedByDate() const;
    void viewExpensesSortedByAmount() const;
    void viewExpensesByCategory(const std::string& category) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif 