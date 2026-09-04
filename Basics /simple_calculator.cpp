#include <iostream>
using namespace std;

int main() {
    float a, b;
    char op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Enter operator (+ - * /): ";
    cin >> op;

    if (op == '+')
        cout << "Result = " << a + b;
    else if (op == '-')
        cout << "Result = " << a - b;
    else if (op == '*')
        cout << "Result = " << a * b;
    else if (op == '/')
        cout << "Result = " << a / b;
    else
        cout << "Invalid operator";

    return 0;
}
