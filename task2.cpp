#include <iostream>

using namespace std;

int main()
{
    char operation;
    float num1, num2;

    cout << "Welcome to the calculator program!" << endl;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    switch(operation)
    {
        case '+':
            cout << "Result: " << num1 << " " << operation << " " <<  num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 << " " <<  operation << " " <<  num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 << " " <<  operation << " " <<  num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 == 0)
            {
                cout << "Error! Division by zero is not allowed." << endl;
            }

            else
            {
                cout << "Result: " << num1 << " " <<  operation << " " <<  num2 << " = " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
    }
    return 0;
}
