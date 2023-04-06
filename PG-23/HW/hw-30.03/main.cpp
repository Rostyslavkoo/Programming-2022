//Створити шаблонну функцію сортування і використати її для сортування масиву
// цілих чисел, рядків та обʼєктів типу Person (структура з полями імʼя та адреса) за іменем.
#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

struct Person {
    string name;
    string address;
};

template <typename T>
void my_sort(vector<T>& v) {
    if constexpr (is_same_v<T, Person>) {
        sort(v.begin(), v.end(), [](const T& a, const T& b) {
            return a.name < b.name;
        });
    }
    else if constexpr (is_same_v<T, string>) {
        sort(v.begin(), v.end());
    }
    else if constexpr (is_integral_v<T>) {
        sort(v.begin(), v.end());
    }
}

int main() {
    vector<int> ints = { 3, 1, 4, 1, 5, 9, 2, 6 };
    my_sort(ints);
    cout << "Sorted by name: \n";
    for (int i : ints) {
        cout << i << ' ';
    }
    cout << '\n';

    vector<string> strings = { "abc", "qwe", "ldog", "gds", "igoa" };
    my_sort(strings);
    cout << "Strings sorted by name:\n";
    for (string s : strings) {
        cout << s << ' ';
    }
    cout << '\n';
    cout << '\n';

    vector<Person> people = { {"Ivan", "Hoholya 13"}, {"Alina", "Kochybunskogo 16"}, {"Rostyk", "Franka 13"} };
    my_sort(people);
    cout << "People sorted by name:\n";
    for (const Person& p : people) {
        cout << p.name << " - " << p.address << "\n";
    }
    return 0;
}