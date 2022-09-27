#include <iostream>
#include <cmath>

using namespace  std;

int main() {
	int num1, num2;
	cout << "Enter num1 \n -> ";
	cin >> num1;
	cout << "Enter num2 \n -> ";
	cin >> num2;



	float ArifmeticAvg = (num1 + num2) / 2;
	float GeomAvg = sqrt(num1 * num2);

	cout << endl;
	cout << "RESULTS:" << endl;
	cout << "Arithmetic avg -> \t" << ArifmeticAvg << endl;
	cout << "Geometric avg -> \t" << GeomAvg;

	return 0;
}