// Ввести текст, що складається з букв латинського алфавіту та цифр.
// Використовуючи алгоритми STL порахувати скільки в нього входить цифр.
// Перемістити в новий контейнер лише символи з вказаного діапазону.
// Посортувати їх в алфавітному порядку і видалити повтори.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    string text;
    cout << "Enter a text: ";
    getline(cin, text);

    int digitCount = count_if(text.begin(), text.end(), [](char c) {
        return isdigit(c);
    });
    cout << "Amount of numbers: " << digitCount << endl;

    // Задаємо діапазон символів, які потрібно перемістити
    char startRange = 'a';
    char endRange = 'z';

    vector<char> newContainer;
    copy_if(text.begin(), text.end(), back_inserter(newContainer), [startRange, endRange](char c) {
        return c >= startRange && c <= endRange;
    });

    sort(newContainer.begin(), newContainer.end());

    set<char> uniqueChars(newContainer.begin(), newContainer.end());
    newContainer.assign(uniqueChars.begin(), uniqueChars.end());

    cout << "Sorted and unique symbols: ";
    for (char c : newContainer) {
        cout << c;
    }
    cout << endl;

    return 0;
}

