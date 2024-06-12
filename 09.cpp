#include <iostream>
#include <string>

using namespace std;

int main() {
    string expression = "a = (c * b)";
    string result = "";

    // Break down the expression
    string operand1 = ""; // To store the first operand
    string operand2 = ""; // To store the second operand
    char op; // To store the operator
    char target; // To store the target variable

    // Parse the expression to extract operands and operator
    int i = 4; // Start after the first four characters ("a = (")
    while (expression[i] != ' ') {
        operand1 += expression[i];
        i++;
    }
    i += 3; // Skip the operator and space
    while (expression[i] != ' ') {
        operand2 += expression[i];
        i++;
    }
    op = expression[i + 1];
    target = expression[0];

    // Generate three-address instructions
    string temporary = "t1"; // Temporary variable
    result += temporary + " = " + operand1 + " " + op + " " + operand2;
    result += ";\n";
    result += target + " = " + temporary + ";";

    // Print the generated three-address code
    cout << result << endl;

    return 0;
}
