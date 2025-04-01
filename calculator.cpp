#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For seeding random number generator
#include <stack>
#include <queue>
#include <sstream>
#include <cctype>
#include <cmath>
#include "calculator.h"

using namespace std;

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
double divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed!" << endl;
        return 0; // Return 0 to indicate an error
    }
    return static_cast<double>(a) / b;
}

// Function to calculate factorial
long long factorial(int n) {
    if (n < 0) return -1; // No factorial for negative numbers
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate Greatest Common Divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate Least Common Multiple (LCM)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to generate a random number within a given range
int generateRandom(int min, int max) {
    if (min > max) {
        cerr << "Error: Invalid range!" << endl;
        return -1; // Return -1 to indicate an error
    }
    return min + rand() % (max - min + 1);
}

// Initialize random seed (Call this once in main() before using generateRandom)
void initRandom() {
    srand(time(0));  // Seed the random number generator
}

// ======================= Expression Evaluation =======================

// Operator precedence map
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}

// Apply an operator to two numbers
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/': return divide(a, b);
        default: return 0;
    }
}

// Convert infix expression to postfix using Shunting Yard Algorithm
queue<string> infixToPostfix(const string& expression) {
    stack<char> operators;
    queue<string> output;
    string number = "";

    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // Ignore spaces
        if (ch == ' ') continue;

        if (isdigit(ch) || ch == '.') {
            number += ch;  // Build multi-digit numbers (e.g., "12", "3.5")
        } else {
            if (!number.empty()) {
                output.push(number);  // Push the full number
                number = "";
            }

            if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                // Pop everything until '('
                while (!operators.empty() && operators.top() != '(') {
                    output.push(string(1, operators.top()));
                    operators.pop();
                }
                if (!operators.empty() && operators.top() == '(') {
                    operators.pop(); // Remove '('
                } else {
                    cerr << "Error: Mismatched parentheses!" << endl;
                    return queue<string>(); // Return empty queue on error
                }
            } else {
                // Pop higher precedence operators before pushing this one
                while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                    output.push(string(1, operators.top()));
                    operators.pop();
                }
                operators.push(ch);
            }
        }
    }

    // Push any remaining number
    if (!number.empty()) {
        output.push(number);
    }

    // Pop remaining operators
    while (!operators.empty()) {
        if (operators.top() == '(') {
            cerr << "Error: Mismatched parentheses!" << endl;
            return queue<string>();  // Return empty queue on error
        }
        output.push(string(1, operators.top()));
        operators.pop();
    }

    return output;
}

// Evaluate postfix expression
double evaluatePostfix(queue<string> postfix) {
    stack<double> values;

    while (!postfix.empty()) {
        string token = postfix.front();
        postfix.pop();

        if (isdigit(token[0])) {  
            values.push(stod(token));  // Convert string to double and push onto stack
        } else {  
            // Check if there are at least two numbers in the stack
            if (values.size() < 2) {
                cerr << "Error: Malformed expression!" << endl;
                return 0;  // Return an error value
            }

            double b = values.top(); values.pop();
            double a = values.top(); values.pop();

            values.push(applyOperation(a, b, token[0]));
        }
    }

    // Check if there's exactly one result left in the stack
    if (values.size() != 1) {
        cerr << "Error: Malformed expression (extra operands)!" << endl;
        return 0;
    }

    return values.top();
}


// Function to evaluate infix expression
double evaluateExpression(const string& expression) {
    queue<string> postfix = infixToPostfix(expression);
    return evaluatePostfix(postfix);
}
