// Task 12

// Для розв'язування задачі використовувати контейнер list.
// Ввести текст, що складається зі слів, розділених пропусками і
// закінчується крапкою. Знайти і перемістити в інший контейнер
// слова, що складаються лише з цифр. Видалити повторні входження з
// нового контейнеру і роздрукути обидва конейнери  у порядку зростання чисел, що вони представляють

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    list<string> words, digitWords, uniqueDigitWords;

    cout << "Введіть текст: ";
    getline(cin,input);
    // Розбити текст на слова
    stringstream ss(input);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Знайти слова, що складаються лише з цифр та перемістити їх в інший контейнер
    for (auto it = words.begin(); it != words.end(); ) {
        if (all_of(it->begin(), it->end(), ::isdigit)) {
            digitWords.push_back(*it);
            it = words.erase(it);
        }
        else {
            ++it;
        }
    }

    // Видалити повторні входження з нового контейнеру
    uniqueDigitWords = digitWords;
    uniqueDigitWords.sort();
    uniqueDigitWords.unique();

    cout << "Слова, що не складаються з цифр:" << endl;
    words.sort();
    for (auto it = words.begin(); it != words.end(); ++it) {
        cout << *it << endl;
    }

    cout << "Слова, що складаються лише з цифр:" << endl;
    uniqueDigitWords.sort();
    for (auto it = uniqueDigitWords.begin(); it != uniqueDigitWords.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
