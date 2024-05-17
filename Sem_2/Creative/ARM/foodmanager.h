#ifndef FOODMANAGER_H
#define FOODMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <ctime>

struct FoodItem {
    double amount;
    tm expiration_date;
    bool has_expiration_date;

    FoodItem(double amt, tm exp_date) : amount(amt), expiration_date(exp_date), has_expiration_date(true) {}
    FoodItem(double amt) : amount(amt), has_expiration_date(false) {
        expiration_date = {};
    }
};

using FoodMap = std::map<std::string, std::vector<FoodItem>>;

class FoodManager {
public:
    void add(const std::string &title, double amount, const std::string &expiration_date = "");
    void addByNote(const std::string &note);
    std::vector<std::string> find(const std::string &needle) const;
    double amount(const std::string &needle) const;
    std::vector<std::pair<std::string, double>> expire(int in_advance_days = 0) const;
    std::string display() const;

private:
    FoodMap items;
    tm parseDate(const std::string &date_str) const;
    tm getTodayDate() const;
};

#endif // FOODMANAGER_H
