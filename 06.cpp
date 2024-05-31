#include <iostream>
#include <cstring>

// Function prototypes
bool E();
bool T();
bool F();
bool match(char token);
void error();

// Input string and current position
char input[100];
int position = 0;

// Main function for parsing
int main() {
    std::cout << "Enter an arithmetic expression (using '+' and '*'): ";
    std::cin >> input;

    // Start parsing
    if (E() && position == strlen(input)) {
        std::cout << "Parsing Successful! The expression is valid." << std::endl;
    } else {
        std::cout << "Parsing Error! The expression is invalid." << std::endl;
    }

    return 0;
}

// Predictive parsing functions
bool E() {
    if (T()) {
        while (input[position] == '+') {
            position++;
            if (!T()) {
                error();
                return false;
            }
        }
        return true;
    }
    return false;
}

bool T() {
    if (F()) {
        while (input[position] == '*') {
            position++;
            if (!F()) {
                error();
                return false;
            }
        }
        return true;
    }
    return false;
}

bool F() {
    if (input[position] == '(') {
        position++;
        if (E()) {
            if (input[position] == ')') {
                position++;
                return true;
            }
        }
        error();
        return false;
    } else if (input[position] >= '0' && input[position] <= '9') {
        position++;
        return true;
    } else {
        error();
        return false;
    }
}

// Function to match a token
bool match(char token) {
    if (input[position] == token) {
        position++;
        return true;
    } else {
        return false;
    }
}

// Function to handle parsing errors
void error() {
    std::cerr << "Parsing Error! Unexpected token '" << input[position] << "' at position " << position << std::endl;
}



Example:-
Enter an arithmetic expression (using '+' and '*'): (2+3)*5
Parsing Successful! The expression is valid.
