#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

// Function to push a character onto the stack
void push(stack<char>& st, char c) {
    st.push(c);
}

// Function to pop a character from the stack
char pop(stack<char>& st) {
    if (!st.empty()) {
        char c = st.top();
        st.pop();
        return c;
    }
    return 'x'; // Return 'x' if the stack is empty
}

// Function to print the contents of the stack
void printStack(stack<char>& st) {
    cout << "\n\t\t\t $";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    stack<char> stack;
    char input[] = "(a|b)*";
    int length = strlen(input);

    cout << "\n\n\t\t LR PARSING";
    cout << "\n\t\t ENTER THE EXPRESSION: " << input << endl;

    cout << "\n\t\t $";
    for (int i = 0; i < length; i++) {
        if (input[i] == '(' || input[i] == '|' || input[i] == ')' || input[i] == '*') {
            push(stack, input[i]);
            printStack(stack);
        }
    }

    //cout << "\n\n";

    return 0;
}
