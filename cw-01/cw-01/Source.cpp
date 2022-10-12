#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

int fibonacci(int num) {
  if (num == 0) {
    return 0;
  }
  if (num == 1) {
    return 1;
  }
  return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {

  // for (int i = 1; i <= 100; i++) {
  //   cout << i << "\t" << 9 / 5.0 * i + 32 << endl;
  // }

  // ціле число  m > 1, отримати найбліьше ціле число k при якому 4 в  степені k
  // < m

  // int m, k = 0;
  // cout << "Enter m:\n";
  // cin >> m;
  // while (pow(4, k) < m)
  //   k++;
  // cout << "k \t" << k;

  //  числа фібоначі

  // int count;
  // cout << "Enter a value:\n";
  // cin >> count;
  // for (int i = 0; i < count; ++i)
  //  cout << fibonacci(i) << " ";

  // задано натуральне число а. Отримати нове число переставляючи числа а у
  // зворотньому напрямку.

  // string myNum;
  // cout << "Enter a value \n";
  // cin >> myNum;
  // int numSize = myNum.size();
  // for (int i = numSize - 1; i >= 0; i--) {
  //   cout << myNum[i];
  // }
  // Використовуючи алгорит Евкліда, знайти НСД двох чисел

  int num1, num2;
  cout << "Enter num1 \n";
  cin >> num1;
  cout << "Enter num2 \n";
  cin >> num2;

  while (num1 != 0 and num2 != 0) {
    if (num1 > num2) {
      num1 = num1 % num2;
    } else {
      num2 = num2 % num1;
    }
  }
  cout << "result \t" << num1 + num2;

  return 0;
}