#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<char, vector<string>> productions;
unordered_map<char, unordered_set<char>> firstSets;
unordered_map<char, unordered_set<char>> followSets;

void calculateFirst(char nonTerminal);
void calculateFollow(char nonTerminal);

int main() {
    // Define the grammar productions
    productions['S'] = {"A"};
    productions['A'] = {"Bd"};
    productions['B'] = {"b"};

    // Calculate FIRST sets
    for (auto &production : productions) {
        calculateFirst(production.first);
    }

    // Initialize FOLLOW(S) with '$'
    followSets['S'].insert('$');

    // Calculate FOLLOW sets
    for (auto &production : productions) {
        calculateFollow(production.first);
    }

    // Print FIRST sets
    cout << "FIRST Sets:\n";
    for (auto &[nonTerminal, firstSet] : firstSets) {
        cout << "FIRST(" << nonTerminal << ") = { ";
        for (char terminal : firstSet) {
            cout << terminal << " ";
        }
        cout << "}\n";
    }

    // Print FOLLOW sets
    cout << "\nFOLLOW Sets:\n";
    for (auto &[nonTerminal, followSet] : followSets) {
        cout << "FOLLOW(" << nonTerminal << ") = { ";
        for (char terminal : followSet) {
            cout << terminal << " ";
        }
        cout << "}\n";
    }

    return 0;
}

void calculateFirst(char nonTerminal) {
    if (firstSets.find(nonTerminal) != firstSets.end()) return;

    for (auto &production : productions[nonTerminal]) {
        char firstSymbol = production[0];
        if (isupper(firstSymbol)) {
            calculateFirst(firstSymbol);
            for (char terminal : firstSets[firstSymbol]) {
                if (terminal != 'e') firstSets[nonTerminal].insert(terminal);
            }
        } else if (firstSymbol != 'e') {
            firstSets[nonTerminal].insert(firstSymbol);
        }
    }
}

void calculateFollow(char nonTerminal) {
    for (auto &[leftSide, rightSides] : productions) {
        for (auto &rightSide : rightSides) {
            for (int i = 0; i < rightSide.size() - 1; ++i) {
                if (rightSide[i] == nonTerminal) {
                    char nextSymbol = rightSide[i + 1];
                    if (isupper(nextSymbol)) {
                        for (char terminal : firstSets[nextSymbol]) {
                            if (terminal != 'e') followSets[nonTerminal].insert(terminal);
                        }
                        if (firstSets[nextSymbol].find('e') != firstSets[nextSymbol].end()) {
                            followSets[nonTerminal].insert(followSets[leftSide].begin(), followSets[leftSide].end());
                        }
                    } else {
                        followSets[nonTerminal].insert(nextSymbol);
                    }
                }
            }
        }
    }
}
