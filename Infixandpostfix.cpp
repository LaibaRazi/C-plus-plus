#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

double evaluatePostfixExpression(const string& postfix) {
    stack<double> operands;

    for (char c : postfix) {
        if (isdigit(c)) {
            double operand = c - '0';
            operands.push(operand);
        } else if (c == '^') {
            double op2 = operands.top();
            operands.pop();
            double op1 = operands.top();
            operands.pop();
            double result = pow(op1, op2);
            operands.push(result);
        } else {
            double op2 = operands.top();
            operands.pop();
            double op1 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(op1 + op2);
                    break;
                case '-':
                    operands.push(op1 - op2);
                    break;
                case '*':
                    operands.push(op1 * op2);
                    break;
                case '/':
                    operands.push(op1 / op2);
                    break;
            }
        }
    }

    return operands.top();
}

int main() {
    string postfixExpression = "45+8*";
    double result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << endl;
    return 0;
}
