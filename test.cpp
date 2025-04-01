#include <iostream>
#include "calculator.h" // Include the header file
#include "calculator.cpp"

using namespace std;

int main() {
    // Initialize random number generator
    initRandom();
    
    cout << "===== Basic Arithmetic Operations =====" << endl;

    // Testing addition
    cout << "Testing Addition: 5 + 3 = " << add(5, 3) << endl;

    // Testing subtraction
    cout << "Testing Subtraction: 10 - 4 = " << subtract(10, 4) << endl;

    // Testing multiplication
    cout << "Testing Multiplication: 6 * 7 = " << multiply(6, 7) << endl;

    // Testing division
    cout << "Testing Division: 15 / 3 = " << divide(15, 3) << endl;
    cout << "Testing Division by zero: 10 / 0 = " << divide(10, 0) << endl;

    cout << "\n===== Factorial, GCD, and LCM =====" << endl;

    // Testing factorial
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Factorial of 0: " << factorial(0) << endl;
    cout << "Factorial of -3 (invalid case): " << factorial(-3) << endl;

    // Testing GCD
    cout << "GCD of 18 and 24: " << gcd(18, 24) << endl;
    cout << "GCD of 101 and 103 (prime numbers): " << gcd(101, 103) << endl;

    // Testing LCM
    cout << "LCM of 6 and 8: " << lcm(6, 8) << endl;
    cout << "LCM of 21 and 14: " << lcm(21, 14) << endl;

    cout << "\n===== Random Number Generation =====" << endl;
    
    // Testing random number generation
    cout << "Random number between 1 and 100: " << generateRandom(1, 100) << endl;
    cout << "Random number between 50 and 60: " << generateRandom(50, 60) << endl;
    cout << "Random number in an invalid range (100, 50): " << generateRandom(100, 50) << endl;

    cout << "\n===== Expression Evaluation =====" << endl;

    // Testing infix expression evaluation
    string expr1 = "3 + 4 * (2 - 1) / 5";
    string expr2 = "10 + 2 * 6";
    string expr3 = "100 * 2 + 12";
    string expr4 = "100 * (2 + 12)";
    string expr5 = "100 * (2 + 12) / 14";

    cout << "Expression: " << expr1 << " = " << evaluateExpression(expr1) << endl;
    cout << "Expression: " << expr2 << " = " << evaluateExpression(expr2) << endl;
    cout << "Expression: " << expr3 << " = " << evaluateExpression(expr3) << endl;
    cout << "Expression: " << expr4 << " = " << evaluateExpression(expr4) << endl;
    cout << "Expression: " << expr5 << " = " << evaluateExpression(expr5) << endl;

    return 0;
}
