// Task 11

// Використати контейнер vector та його ітератор для роботи з масивами даних. Також реалізувати перехоплення винятків.
//В текстовому файлі знаходяться дані про оплачені рахунки за газ та воду. Для рахунків за газ – це прізвище абонента,
// кількість прописаних осіб, оплачена сума; для рахунків за воду – це прізвище абонента, останній показ лічильника, оплачений об’єм води, оплачена сума.

//1) зчитати дані з файлу у контейнер, відобразити на екрані (і записати у відповідні файли) окремо рахунки за газ,
// окремо за воду. При цьому рахунки за газ повинні бути посортовані у алфавітному порядку абонентів, а рахунки за воду – у порядку спадання сум.

//2) порахувати скільки абонентів заплатили за газ, а не заплатили за воду



#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Клас, який описує рахунок за газ або воду
class Bill {
public:
    string surname;
    double amount;
    Bill(string s, double a) : surname(s), amount(a) {}
};

// Оператор порівняння для сортування рахунків за газом по абонентах
bool gasCompare(const Bill& a, const Bill& b) {
    return a.surname < b.surname;
}

// Оператор порівняння для сортування рахунків за водою по сумі
bool waterCompare(const Bill& a, const Bill& b) {
    return a.amount > b.amount;
}

int main() {
    try {
        vector<Bill> gasBills;
        vector<Bill> waterBills;

        // Відкриття файлу з даними
        ifstream inFile("bills.txt");
        if (!inFile.is_open()) {
            throw runtime_error("Unable to open file!");
        }

        // Зчитування даних з файлу та додавання їх до відповідного контейнера
        string type;
        while (inFile >> type) {
            string surname;
            double value1, value2;
            inFile >> surname >> value1 >> value2;
            if (type == "gas") {
                gasBills.emplace_back(surname, value2);
            } else if (type == "water") {
                waterBills.emplace_back(surname, value2);
            }
        }

        // Сортування рахунків та виведення їх на екран
        sort(gasBills.begin(), gasBills.end(), gasCompare);
        sort(waterBills.begin(), waterBills.end(), waterCompare);

        cout << "Gas bills:" << endl;
        for (const auto& bill : gasBills) {
            cout << bill.surname << " " << bill.amount << endl;
        }

        cout << endl << "Water bills:" << endl;
        for (const auto& bill : waterBills) {
            cout << bill.surname << " " << bill.amount << endl;
        }

        // Підрахунок кількості абонентів, які заплатили за газ, а не за воду
        int gasPaid = 0;
        int waterUnpaid = 0;

        for (const auto& bill : gasBills) {
            gasPaid++;
            for (const auto& wBill : waterBills) {
                if (bill.surname == wBill.surname) {
                    gasPaid--;
                    waterUnpaid++;
                    break;
                }
            }
        }

        cout << endl << "Number of subscribers who paid for gas and did not pay for water: " << gasPaid << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}