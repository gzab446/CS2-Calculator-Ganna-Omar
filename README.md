# Calculator Program

This is a simple yet powerful command-line calculator program written in C++. It supports basic arithmetic operations, factorial calculation, GCD and LCM computation, random number generation, and expression evaluation with support for parentheses and operator precedence (e.g., `3 + 4 * (2 - 1) / 5`).

## Features
- **Basic Arithmetic**: Addition, subtraction, multiplication, and division.
- **Factorial Calculation**: Computes the factorial of a non-negative integer.
- **GCD (Greatest Common Divisor)**: Calculates the greatest common divisor of two numbers.
- **LCM (Least Common Multiple)**: Computes the least common multiple of two numbers.
- **Random Number Generation**: Generates a random number within a specified range.
- **Expression Evaluation**: Evaluates mathematical expressions with support for parentheses and operator precedence (e.g., `3 + 4 * (2 - 1) / 5`).

## Requirements

- A C++ compiler (e.g., **g++**)
- C++11 or later
- A text editor to modify the code (optional)

## Setup Instructions

1. **Clone the repository** (or download the source code):
    ```bash
    git clone https://github.com/yourusername/calculator.git
    cd calculator
    ```

2. **Compile the code**:
    ```bash
    g++ -o calculator main.cpp calculator.cpp
    ```

3. **Run the calculator**:
    ```bash
    ./calculator
    ```

## How to Use

### 1. **Basic Arithmetic Operations**

You can perform basic arithmetic operations such as addition, subtraction, multiplication, and division. Simply call the appropriate functions.

**Example:**
```cpp
int result = add(5, 3);  // Adds 5 + 3
2. Factorial Calculation
You can calculate the factorial of a number using the factorial() function. Note that it only works for non-negative integers.

Example:

long long result = factorial(5);  // Computes 5! = 120
3. GCD and LCM Calculations
You can compute the GCD and LCM of two numbers.

Example:

int result_gcd = gcd(18, 24);  // Computes GCD of 18 and 24
int result_lcm = lcm(6, 8);    // Computes LCM of 6 and 8
4. Random Number Generation
You can generate random numbers within a specified range using generateRandom(min, max).

Example:

int random_number = generateRandom(1, 100);  // Generates a random number between 1 and 100
5. Expression Evaluation
The calculator can evaluate mathematical expressions that include addition, subtraction, multiplication, division, and parentheses. The Shunting Yard algorithm is used to convert infix expressions into postfix notation for easy evaluation.

Supported Operators:
+, -, *, /

Order of Operations:
Parentheses () are evaluated first.

Multiplication * and division / have higher precedence than addition + and subtraction -.

Example:
To evaluate an expression like 3 + 4 * (2 - 1), you can use the evaluateExpression() function.

string expr = "3 + 4 * (2 - 1)";
double result = evaluateExpression(expr);  // Evaluates the expression
Supported Expressions:
Valid: 3 + 4 * (2 - 1)

Invalid: 5 + (incomplete expression)

Error Handling: The calculator will print an error message and return a value of 0 for invalid expressions.

6. Random Number Generation:
You can also generate a random number between two specified numbers.

int randNum = generateRandom(1, 100);  // Generates a random number between 1 and 100
Examples of Expressions:
Here are some examples of how you can test the expression evaluation:

"3 + 4 * (2 - 1) / 5" results in 3.8.

"10 + 2 * 6" results in 22.

"100 * 2 + 12" results in 212.

"100 * (2 + 12)" results in 1400.

"100 * (2 + 12) / 14" results in 100.

Error Handling
Division by Zero: The program checks for division by zero and will output an error message instead of crashing.

Malformed Expressions: The program detects and reports errors if the expression is malformed (e.g., missing operands or mismatched parentheses).