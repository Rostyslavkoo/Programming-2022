// завдання 14
// В текстовому файлі задані дані телефонної книги: дані про абонента: ПІП, адреса, № телефону. Дані можуть повторюватися (абонент може мати декілька телефонів).
//- Визначити необхідні типи (адреса, абонент, телефонна книга)
//- ввести дані з файлу
//- вивести в файл1 список абонентів без повторів, посортований одночасно за ПІП та адресою.
//- за введеною комбінацією декількох букв вивести абонентів, у яких адреса містить цю комбінацію.

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

// Типи даних
struct Address {
    std::string street;
    std::string city;
};

struct Subscriber {
    std::string name;
    Address address;
    std::set<std::string> phone_numbers;
};

using PhoneBook = std::multimap<std::string, Subscriber>;

// Функція для виведення адреси
std::ostream& operator<<(std::ostream& os, const Address& address) {
    os << address.street << ", " << address.city;
    return os;
}

// Функція для виведення абонента
std::ostream& operator<<(std::ostream& os, const Subscriber& subscriber) {
    os << subscriber.name << ", " << subscriber.address << ", ";
    for (const auto& phone_number : subscriber.phone_numbers) {
        os << phone_number << " ";
    }
    return os;
}

int main() {
    std::ifstream input_file("phonebook.txt");
    PhoneBook phone_book;

    // Зчитування даних з файлу
    if (input_file.is_open()) {
        std::string name, street, city, phone_number;
        while (input_file >> name >> street >> city >> phone_number) {
            Subscriber subscriber;
            subscriber.name = name;
            subscriber.address.street = street;
            subscriber.address.city = city;
            subscriber.phone_numbers.insert(phone_number);
            phone_book.insert(std::make_pair(name, subscriber));
        }
    }
    input_file.close();

    // Виведення списку абонентів без повторів, посортованого за ПІП та адресою
    std::ofstream output_file1("output1.txt");
    if (output_file1.is_open()) {
        std::map<std::string, Address> unique_subscribers;
        for (const auto& entry : phone_book) {
            const Subscriber& subscriber = entry.second;
            std::string name = subscriber.name;
            Address address = subscriber.address;
            if (unique_subscribers.count(name) == 0 || unique_subscribers[name].city > address.city) {
                unique_subscribers[name] = address;
            }
        }
        for (const auto& entry : unique_subscribers) {
            output_file1 << entry.first << ", " << entry.second << std::endl;
        }
    }
    output_file1.close();

    // Пошук абонентів за комбінацією букв в адресі
    std::string search_string = "Lviv"; // комбінація букв для пошуку
    std::ofstream output_file2("output2.txt");
    if (output_file2.is_open()) {
        for (const auto& entry : phone_book) {
            const Subscriber& subscriber = entry.second;
            if (subscriber.address.street.find(search_string) != std::string::npos ||
                subscriber.address.city.find(search_string) != std::string::npos) {
                output_file2 << subscriber << std::endl;
            }
        }
    }
    output_file2.close();

    return 0;
}
