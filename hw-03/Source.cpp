#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>

using namespace std;

int main() {

	// -- task 5
	//double num;
	//cout << "Enter a number: \t";
	//cin >> num;
	//
	//if (typeid(num).name() != "number") {
	//	cout << "Not a number \n";
	//	return 0;
	//};
	//double result = pow(pow(num, 8) + pow(8, num),1/8.0);
	//cout << "result:" << result << endl;
	
	// -- task 15
	//int entered_month;
	//string MONTHS[] = { "January", "February", "March", "April", "May", "June", "July",
	//	"August", "September", "October", "November", "December" };\
	//cout << "Enter a month number: \t";
	//cin >> entered_month;
	//cout << typeid(entered_month).name();
	//if (entered_month <= 0 || entered_month > 12) {
	//	cout << "Not a months range number \n";
	//	return 0;
	//}
	//cout << MONTHS[entered_month -1];
	
    // -- task 17
	//int num1, num2;
	//cout << "Enter num1 \n -> ";
	//cin >> num1;
	//cout << "Enter num2 \n -> ";
	//cin >> num2;
	//if (cin.fail()) {
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//	cout << "Not a number" << endl;
	//	return 0;
	//}
	// 
	//float ArifmeticAvg = (num1 + num2) / 2.0;
	//float GeomAvg = sqrt(num1 * num2);

	//cout << endl;
	//cout << "RESULTS:" << endl;
	//cout << "Arithmetic avg -> \t" << ArifmeticAvg << endl;
	//cout << "Geometric avg -> \t" << GeomAvg;
	
	// -- task 18
	int num;
	int result = 0;

	cout << "Enter nummer \n -> ";
	cin >> num;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Not a number" << endl;
		return 0;
	}
	if (to_string(num).length() > 3) {
		cout << "number length more than 3 digits";
		return 0;
	}
	while (num != 0) {
		result += num % 10;
		num /= 10;
	}
	cout << "result:\t" << result << endl;


	return 0;
}