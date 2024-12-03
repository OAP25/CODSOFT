#include <iostream>
using namespace std;

int main() {
    double num1;  // First number
    double num2;  // Second number
    char op;      // Operation which has to be performed

    cout << "Enter two numbers separated by space: ";
    cin >> num1 >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> op;

     // Using switch cases to perform different operations
    switch (op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;  // Error Handling
            break;
        default:
            cout << "Error: Invalid operation." << endl;
    }

    return 0;
}
