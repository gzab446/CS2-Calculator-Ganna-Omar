#include <iostream>
#include "calculator.h" // Include the header file

using namespace std;

int main() {
    // Initialize random number generator
    initRandom();
    

    // Testing addition
    cout << "Testing Addition: 5 + 3 = " << add(5, 3) << endl;

    // Testing subtraction
    cout << "Testing Subtraction: 10 - 4 = " << subtract(10, 4) << endl;

    // Testing multiplication
    cout << "Testing Multiplication: 6 * 7 = " << multiply(6, 7) << endl;

    // Testing division
    cout << "Testing Division: 15 / 3 = " << divide(15, 3) << endl;
    cout << "Testing Division by zero: 10 / 0 = " << divide(10, 0) << endl;

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

    // Testing random number generation
    cout << "Random number between 1 and 100: " << generateRandom(1, 100) << endl;
    cout << "Random number between 50 and 60: " << generateRandom(50, 60) << endl;
    cout << "Random number in an invalid range (100, 50): " << generateRandom(100, 50) << endl;

    return 0;
}
