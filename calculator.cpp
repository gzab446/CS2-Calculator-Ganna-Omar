#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding random number generator
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
    return static_cast<double>(a) / b; // Cast to double for floating-point division
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
    return (a / gcd(a, b)) * b; // Formula: LCM(a, b) = (a * b) / GCD(a, b)
}

// Function to generate a random number within a given range
int generateRandom(int min, int max) {
    if (min > max) {
        cerr << "Error: Invalid range!" << endl;
        return -1; // Return -1 to indicate an error
    }
    return min + rand() % (max - min + 1); // Generate number between min and max
}

// Initialize random seed (Call this once in main() before using generateRandom)
void initRandom() {
    srand(time(0));
}

