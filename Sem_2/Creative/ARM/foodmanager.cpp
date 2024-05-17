#include "foodmanager.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

void FoodManager::add(const std::string &title, double amount, const std::string &expiration_date) {
    if (items.find(title) == items.end()) {
        items[title] = std::vector<FoodItem>();
    }
    if (expiration_date.empty()) {
        items[title].emplace_back(amount);
    } else {
        items[title].emplace_back(amount, parseDate(expiration_date));
    }
}

void FoodManager::addByNote(const std::string &note) {
    try {
        size_t last_space = note.rfind(' ');
        double amount = std::stod(note.substr(last_space + 1));
        std::string title_and_date = note.substr(0, last_space);

        size_t date_pos = title_and_date.rfind(' ');
        std::string expiration_date;
        std::string title;

        if (date_pos != std::string::npos && title_and_date.length() - date_pos - 1 == 10 && title_and_date[date_pos + 4] == '-') {
            expiration_date = title_and_date.substr(date_pos + 1);
            title = title_and_date.substr(0, date_pos);
        } else {
            title = title_and_date;
        }

        add(title, amount, expiration_date);
    } catch (const std::invalid_argument &e) {
        // Handle invalid argument exception
    } catch (const std::out_of_range &e) {
        // Handle out of range exception
    }
}

std::vector<std::string> FoodManager::find(const std::string &needle) const {
    std::vector<std::string> foods;
    for (const auto &item : items) {
        if (item.first.find(needle) != std::string::npos) {
            foods.push_back(item.first);
        }
    }
    return foods;
}

double FoodManager::amount(const std::string &needle) const {
    std::vector<std::string> foods = find(needle);
    double total_amount = 0;
    for (const auto &food : foods) {
        for (const auto &ves : items.at(food)) {
            total_amount += ves.amount;
        }
    }
    return total_amount;
}

std::vector<std::pair<std::string, double>> FoodManager::expire(int in_advance_days) const {
    std::vector<std::pair<std::string, double>> result;
    tm date_delay = getTodayDate();
    date_delay.tm_mday += in_advance_days;
    mktime(&date_delay); // Normalize time structure after modification

    for (const auto &food : items) {
        double total_amount = 0;
        for (const auto &ves : food.second) {
            if (ves.has_expiration_date && difftime(mktime(&const_cast<tm&>(ves.expiration_date)), mktime(&date_delay)) <= 0) {
                total_amount += ves.amount;
            }
        }
        if (total_amount > 0) {
            result.emplace_back(food.first, total_amount);
        }
    }
    return result;
}

std::string FoodManager::display() const {
    std::ostringstream oss;
    oss << "Продукты в холодильнике:\n";
    for (const auto &item : items) {
        oss << item.first << " - ";
        for (const auto &spec : item.second) {
            oss << spec.amount << " ";
            if (spec.has_expiration_date) {
                oss << std::put_time(&spec.expiration_date, "%Y-%m-%d") << " ";
            }
        }
        oss << "\n";
    }
    return oss.str();
}

tm FoodManager::parseDate(const std::string &date_str) const {
    tm time_struct = {};
    std::istringstream ss(date_str);
    ss >> std::get_time(&time_struct, "%Y-%m-%d");
    time_struct.tm_isdst = -1; // Set daylight saving time to automatic
    mktime(&time_struct); // Normalize time structure
    return time_struct;
}

tm FoodManager::getTodayDate() const {
    time_t t = time(nullptr);
    tm today = *localtime(&t);
    today.tm_hour = today.tm_min = today.tm_sec = 0;
    today.tm_isdst = -1; // Set daylight saving time to automatic
    mktime(&today); // Normalize time structure
    return today;
}
