#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enum for different types of AST nodes
enum NodeType {
    VARIABLE,
    MULTIPLICATION
};

// AST Node structure
struct Node {
    NodeType type;
    string value;
    Node* left; // Pointer to left child
    Node* right; // Pointer to right child

    Node(NodeType t, string val) : type(t), value(val), left(nullptr), right(nullptr) {}
};

// Function to generate machine code from AST
void generateMachineCode(Node* root, vector<string>& machineCode) {
    if (root == nullptr) return;

    switch (root->type) {
        case VARIABLE:
            // Push variable value onto stack
            machineCode.push_back("PUSH " + root->value);
            break;
        case MULTIPLICATION:
            // Generate machine code for left and right children
            generateMachineCode(root->left, machineCode);
            generateMachineCode(root->right, machineCode);
            // Perform multiplication operation
            machineCode.push_back("POP R1"); // Pop the second operand from stack
            machineCode.push_back("POP R2"); // Pop the first operand from stack
            machineCode.push_back("MUL R1, R1, R2"); // Multiply and store the result in R1
            machineCode.push_back("PUSH R1"); // Push the result onto the stack
            break;
    }
}

int main() {
    // Create AST for expression: a * b
    Node* root = new Node(MULTIPLICATION, "");
    root->left = new Node(VARIABLE, "a");
    root->right = new Node(VARIABLE, "b");

    // Generate machine code from the AST
    vector<string> machineCode;
    generateMachineCode(root, machineCode);

    // Print the generated machine code
    cout << "Generated machine code:" << endl;
    for (const auto& instruction : machineCode) {
        cout << instruction << endl;
    }

    // Clean up the memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
