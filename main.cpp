// Simple math calculator
// By Aarav Sharma

// loading the header files
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>

// short format for std
using namespace std;

// calculate function
double calculate(const double a, const char op, const double b, string& errorMessage) {
    // switching the operator to calculate the number
    switch (op) {
        // +
        case '+': return a + b;
        // -
        case '-': return a - b;
        // *
        case '*': return a * b;
        // /
        case '/': return b != 0 ? a / b : 0;
        // neither
        default:
            // will display the error message
            errorMessage = "Invalid operator. Please enter a valid number followed by an operator (+, -, *, /)";
            return 0;
    }
}

// main function
int main() {
    // displaying the title
    cout << "Math Calculator" << endl << endl;

    // string variables
    string input;
    string errorMessage;

    // Variables to hold the numbers and the operation.
    double num1, num2;
    char operation;

    // infinite loop to keep the calculator running until the user wants to exit
    while (true) {
        // Give the input to the user
        cout << ">> ";
        getline(cin, input);

        // Checking if the input string is not empty and contains only numbers and an operator
        stringstream ss(input);
        ss >> num1 >> operation >> num2;

        // Will calculate the result of the number using the calculate function
        const double result = calculate(num1, operation, num2, errorMessage);

        // Display the result if the number is valid otherwise will print the error message
        if (errorMessage.empty()) {
            cout << result << endl << endl;
        }
        else {
            cout << errorMessage << endl << endl;
        }

        // sleep for a few milliseconds
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    // this line will never be executed
    return 0;
}