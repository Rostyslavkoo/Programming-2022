// Створіть функцію Modified, яка здійснює модифікацію елементів масиву і повертає рядок, який містить форматне виведення цього масиву у вигляді таблиці:
//
//            |    i   |      a[i]     |    modified a[i]   |
//
//           Числа в таблиці повинні бути вирівняні вправо, 2 точні цифри після коми
//           Функція Modified отримує вказівник на функцію з одним аргументом типу double, (яка
//           здійснює операцію над аргументом і повертає його), масив, який треба модифікувати
//           і з допомогою рядкового потоку утворює рядок з модифікованим масивом
//          Ввести масив дійсних чисел, модифікувати його таким чином:
//
//кожен елемент замінити на його квадрат
//
//кожен елемент a[i] замінити на sin(a[i])+cos(a[i])-tg(a[i])
//
//кожен елемент замінити на найближче ціле число
//Для цього визначити відповідні функції або використати лямбди
//Результат вивести у файл.


#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

string Modified(double (*func)(double), double arr[], int size) {
    stringstream ss;
    ss << "|  i  |     a[i]     |    modified a[i]  |\n";
    ss << "|-----|--------------|-------------------|\n";
    for (int i = 0; i < size; i++) {
        double modified = func(arr[i]);
        ss << "|" << setw(3) << i << setw(3) << "|" << setw(9) << fixed << setprecision(2) << arr[i] << setw(6) << "|" << setw(12) << fixed << setprecision(2) << modified << setw(9) << "|\n";
    }
    return ss.str();
}

int main()
{
    const int size = 5;
    double arr[size] = {1.23, 2.34, 3.45, 4.56, 5.67};

    string modified1 = Modified([](double x) { return x * x; }, arr, size);
    cout << "Modified array (squared):\n" << modified1 << endl;

    string modified2 = Modified([](double x) { return sin(x) + cos(x) - tan(x); }, arr, size);
    cout << "Modified array (sin + cos - tan):\n" << modified2 << endl;

    string modified3 = Modified([](double x) { return round(x); }, arr, size);
    cout << "Modified array (rounded):\n" << modified3 << endl;

    ofstream outfile("modified_arrays.txt");
    if (outfile.is_open()) {
        outfile << "Modified array (squared):\n" << modified1 << endl;
        outfile << "Modified array (sin + cos - tan):\n" << modified2 << endl;
        outfile << "Modified array (rounded):\n" << modified3 << endl;
        outfile.close();
        cout << "Modified arrays written to file 'modified_arrays.txt'" << endl;
    } else {
        cerr << "Unable to open file 'modified_arrays.txt'" << endl;
    }

    return 0;
}