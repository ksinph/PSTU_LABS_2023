#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

struct FoodItem {
    double amount;
    tm expiration_date;
    bool has_expiration_date;

    FoodItem(double amt, tm exp_date) : amount(amt), expiration_date(exp_date), has_expiration_date(true) {}
    FoodItem(double amt) : amount(amt), has_expiration_date(false) {
        expiration_date = {};
    }
};

using FoodMap = map<string, vector<FoodItem>>;

const string DATE_FORMAT = "%Y-%m-%d";

tm parse_date(const string& date_str) {
    tm time_struct = {};
    istringstream ss(date_str);
    ss >> get_time(&time_struct, "%Y-%m-%d");
    time_struct.tm_isdst = -1; // Устанавливаем летнее время в автоматический режим
    mktime(&time_struct); // Нормализуем структуру времени
    return time_struct;
}

void add(FoodMap& items, const string& title, double amount, const string& expiration_date = "") {
    if (items.find(title) == items.end()) {
        items[title] = vector<FoodItem>();
    }
    if (expiration_date.empty()) {
        items[title].emplace_back(amount);
    }
    else {
        items[title].emplace_back(amount, parse_date(expiration_date));
    }
}

void add_by_note(FoodMap& items, const string& note) {
    try {
        size_t last_space = note.rfind(' ');
        double amount = stod(note.substr(last_space + 1));
        string title_and_date = note.substr(0, last_space);

        size_t date_pos = title_and_date.rfind(' ');
        string expiration_date;
        string title;

        if (date_pos != string::npos && title_and_date.length() - date_pos - 1 == 10 && title_and_date[date_pos + 4] == '-') {
            expiration_date = title_and_date.substr(date_pos + 1);
            title = title_and_date.substr(0, date_pos);
        }
        else {
            title = title_and_date;
        }

        add(items, title, amount, expiration_date);
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: некорректный ввод. Убедитесь, что ввод правильный." << endl;
    }
    catch (const out_of_range& e) {
        cout << "Ошибка: введенное значение вне допустимого диапазона." << endl;
    }
}

vector<string> find(const FoodMap& items, const string& needle) {
    vector<string> foods;
    for (const auto& item : items) {
        if (item.first.find(needle) != string::npos) {
            foods.push_back(item.first);
        }
    }
    return foods;
}

double amount(const FoodMap& items, const string& needle) {
    vector<string> foods = find(items, needle);
    double total_amount = 0;
    for (const auto& food : foods) {
        for (const auto& ves : items.at(food)) {
            total_amount += ves.amount;
        }
    }
    return total_amount;
}

tm get_today_date() {
    time_t t = time(nullptr);
    tm today = *localtime(&t);
    today.tm_hour = today.tm_min = today.tm_sec = 0;
    today.tm_isdst = -1; // Устанавливаем летнее время в автоматический режим
    mktime(&today); // Нормализуем структуру времени
    return today;
}

vector<pair<string, double>> expire(const FoodMap& items, int in_advance_days = 0) {
    vector<pair<string, double>> result;
    tm date_delay = get_today_date();
    date_delay.tm_mday += in_advance_days;
    mktime(&date_delay); // Нормализуем структуру времени после изменения

    for (const auto& food : items) {
        double total_amount = 0;
        for (const auto& ves : food.second) {
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

void display_goods(const FoodMap& goods) {
    cout << "Продукты в холодильнике:" << endl;
    for (const auto& item : goods) {
        cout << item.first << " - ";
        for (const auto& spec : item.second) {
            cout << spec.amount << " ";
            if (spec.has_expiration_date) {
                cout << put_time(&spec.expiration_date, "%Y-%m-%d") << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FoodMap goods;
    string command;

    while (true) {
        cout << "Введите команду (add, add_by_note, find, amount, expire, display, exit): ";
        cin >> command;

        if (command == "add") {
            string title, expiration_date;
            double amount;
            cout << "Введите название продукта: ";
            cin.ignore();
            getline(cin, title);
            cout << "Введите количество: ";
            cin >> amount;
            cout << "Введите срок годности (YYYY-MM-DD) или оставьте пустым: ";
            cin.ignore();
            getline(cin, expiration_date);
            add(goods, title, amount, expiration_date);

        }
        else if (command == "add_by_note") {
            string note;
            cout << "Введите описание продукта: ";
            cin.ignore();
            getline(cin, note);
            add_by_note(goods, note);

        }
        else if (command == "find") {
            string needle;
            cout << "Введите строку для поиска: ";
            cin.ignore();
            getline(cin, needle);
            vector<string> results = find(goods, needle);
            for (const auto& result : results) {
                cout << result << endl;
            }

        }
        else if (command == "amount") {
            string needle;
            cout << "Введите название продукта: ";
            cin.ignore();
            getline(cin, needle);
            double total_amount = amount(goods, needle);
            cout << "Общее количество " << needle << ": " << total_amount << endl;

        }
        else if (command == "expire") {
            int days;
            cout << "Введите количество дней для проверки просроченных продуктов: ";
            cin >> days;
            vector<pair<string, double>> expired_items = expire(goods, days);
            cout << "Просроченные продукты:" << endl;
            for (const auto& item : expired_items) {
                cout << item.first << ": " << item.second << endl;
            }

        }
        else if (command == "display") {
            display_goods(goods);

        }
        else if (command == "exit") {
            break;

        }
        else {
            cout << "Неизвестная команда. Попробуйте еще раз." << endl;
        }
    }

    return 0;
}
    