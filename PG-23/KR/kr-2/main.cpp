// а) Дана функція f повинна змінити контейнер l1  таким чином:
// всі символи, які представляють цифри замінити на символ a.
// Дописати який саме <Алгоритм> треба використати і визначити необхідний функціональний об`єкт Fun,
// який використовується у вказаному алгоритмі для  виконання завдання.

//Б) Використовуючи алгоритми STL , Дописати функцію так:  з контейнера l1 видалити всі елементи,
// які повторюються, залишивши лише по одному екземпляру. Вивести у потік змінений контейнер.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

struct Fun {
    char replacement;

    Fun(char repl) : replacement(repl) {}

    bool operator()(char c) const {
        return isdigit(c);
    }
};

void f(vector<char>& l1, char a) {
    // Замінити всі цифри на символ 'a'
    replace_if(l1.begin(), l1.end(), Fun(a), a);
}
void removeDuplicates(vector<char>& l1) {
    sort(l1.begin(), l1.end());  // Спочатку відсортуємо контейнер
    auto it = unique(l1.begin(), l1.end());  // Залишимо лише унікальні елементи
    l1.erase(it, l1.end());  // Видалимо зайві елементи
}

int main() {
    char val;
    vector<char> l1;
    cout << "Enter characters (press Enter after each character, type 'q' to quit):"<<endl;

    while (cin >> val && val != 'q') {
        l1.push_back(val);
    }
    char a = 'a';
    cout << "Original vector: \n";
    for (char c : l1) {
        cout << c << " ";
    }
    f(l1, a);
    cout << endl;
    cout << "Replaced symbols: \n";
    for (char c : l1) {
        cout << c << " ";
    }

    removeDuplicates(l1);
    cout << endl;
    cout << "Sorted and unique symbols: \n";
    for (char c : l1) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}




