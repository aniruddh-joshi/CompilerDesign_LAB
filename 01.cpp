#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Function to check if a string is a keyword
bool isKeyword(const string& str) {
    static const unordered_set<string> keywords = {"auto", "break", "case", "char", "const", "continue", "default", 
                                            "do", "double", "else", "enum", "extern", "float", "for", "goto", 
                                            "if", "int", "long", "register", "return", "short", "signed", 
                                            "sizeof", "static", "struct", "switch", "typedef", "union", 
                                            "unsigned", "void", "volatile", "while"};
    return keywords.count(str);
}

// Function to check if a character is an operator
bool isOperator(char c) {
    static const string operators = "+-*/%=<>&|^!?:";
    return operators.find(c) != string::npos;
}

int main() {
    cout << "Enter your C++ source code. Press Ctrl+D (Ctrl+Z on Windows) to finish:" << endl;

    string line;
    int keywordCount = 0, operatorCount = 0, identifierCount = 0, newlineCount = 0;

    while (getline(cin, line)) {
        newlineCount++;

        string word;
        bool inWord = false;
        for (char c : line) {
            if (isalnum(c) || c == '_') {
                word += c;
                inWord = true;
            } else {
                if (inWord) {
                    if (isKeyword(word))
                        keywordCount++;
                    else
                        identifierCount++;
                    word.clear();
                    inWord = false;
                }
                if (isOperator(c))
                    operatorCount++;
            }
        }
        if (inWord) {
            if (isKeyword(word))
                keywordCount++;
            else
                identifierCount++;
        }
    }

    cout << "Number of keywords: " << keywordCount << endl;
    cout << "Number of operators: " << operatorCount << endl;
    cout << "Number of identifiers: " << identifierCount << endl;
    cout << "Number of newlines: " << newlineCount << endl;

    return 0;
}




//OUTPUT:
void main(){
int a,b,c;
c=a+b;
}
Number of keywords: 2
Number of operators: 2
Number of identifiers: 7
Number of newlines: 4
