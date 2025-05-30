

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <queue>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

// Function to calculate factorial
long long factorial(int n);

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b);

// Function to calculate LCM (Least Common Multiple)
int lcm(int a, int b);

// Function to generate a random number within a given range
int generateRandom(int min, int max);

void initRandom();

//Functions to evaluate mathematical expression
int precedence(char op);
double applyOperation(double a, double b, char op);
std::queue<std::string> infixToPostfix(const std::string& expression);
double evaluatePostfix(std::queue<std::string> postfix);
double evaluateExpression(const std::string& expression);


#endif
