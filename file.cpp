#include <iostream>
#include <limits>

//author: vs code

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cerr << "Error: Division by zero!" << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }
}

// Function to perform the calculation based on the operator
double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return add(num1, num2);
        case '-':
            return subtract(num1, num2);
        case '*':
            return multiply(num1, num2);
        case '/':
            return divide(num1, num2);
        default:
            std::cerr << "Error: Invalid operator!" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
    }
}

int main() {
    double num1, num2, result;
    char operation;
    char choice;

    do {
        std::cout << "Enter first number: ";
        while (!(std::cin >> num1)) {
            std::cerr << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> operation;

        std::cout << "Enter second number: ";
        while (!(std::cin >> num2)) {
            std::cerr << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        result = calculate(num1, num2, operation);

        if (!std::isnan(result)) {
            std::cout << "Result: " << result << std::endl;
        }

        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}