// Task 13

// При виконанні завдання використовувати контейнер stack з STL, а також об'єктно-орієнтований підхід
// У вхідному файлі записана (без помилок) формула такого виду:
//<формула>::=<цифра> | (<формула> <знак> <формула>)
//<знак>::=
//<цифра>:!=0|1|2|3|4|5|6|7|8|9
//Ввести цю формулу і обчислити її значення.
//Наприклад  5->5, ((2-4)*6)->-12)

// (2-4)*6) *-246

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Expression {
private:
    stack<char> operators;
    stack<int> operands;

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int performOperation(char op, int operand1, int operand2) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                return operand1 / operand2;
            default:
                return 0;
        }
    }

public:
    int evaluateExpression(const string& formula) {
        for (char c : formula) {
            if (c == '(') {
                operators.push(c);
            } else if (isdigit(c)) {
                operands.push(c - '0');  // Converting a character-number into a numerical value
            } else if (isOperator(c)) {
                while (!operators.empty() && operators.top() != '(' &&
                       ((c != '*' && c != '/') || (operators.top() != '+' && operators.top() != '-'))) {
                    int operand2 = operands.top();
                    operands.pop();
                    int operand1 = operands.top();
                    operands.pop();
                    char op = operators.top();
                    operators.pop();
                    int result = performOperation(op, operand1, operand2);
                    operands.push(result);
                }
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    int operand2 = operands.top();
                    operands.pop();
                    int operand1 = operands.top();
                    operands.pop();
                    char op = operators.top();
                    operators.pop();
                    int result = performOperation(op, operand1, operand2);
                    operands.push(result);
                }
                if (!operators.empty())
                    operators.pop();
            }
        }

        while (!operators.empty()) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            char op = operators.top();
            operators.pop();
            int result = performOperation(op, operand1, operand2);
            operands.push(result);
        }

        return operands.top();
    }
};

int main() {
    string formula;
    cout << "Enter the formula: ";
    getline(cin, formula);

    Expression expression;
    int result = expression.evaluateExpression(formula);
    cout << "Result: " << result << endl;

    return 0;
}


