#include <iostream>
#include <string>
using namespace std;

// Define the grammar production rules
string prol[] = { "S", "A", "A", "B", "B", "C", "C" };
string pror[] = { "Aa", "Bb", "Cd", "aB", "@", "Cc", "@" };
string prod[] = { "S-->A", "A-->Bb", "A-->Cd", "B-->aB", "B-->@", "C-->Cc", "C-->" };
string first[] = { "abcd", "ab", "cd", "a@", "@", "c@", "@" };
string follow[] = { "$", "$", "$", "a$", "b$", "c$", "d$" };

string table[5][6];

// Map characters to their corresponding index
int numr(char c) {
    switch (c) {
        case 'S': return 0;
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case '$': return 4;
    }
    return -1;
}

// Generate the predictive parsing table
void generateParsingTable() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            table[i][j] = " ";
        }
    }

    for (int i = 0; i < 7; i++) {
        int k = first[i].size();
        for (int j = 0; j < k; j++) {
            if (first[i][j] != '@') {
                table[numr(prol[i][0]) + 1][numr(first[i][j]) + 1] = prod[i];
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        if (pror[i].size() == 1 && pror[i][0] == '@') {
            int k = follow[i].size();
            for (int j = 0; j < k; j++) {
                table[numr(prol[i][0]) + 1][numr(follow[i][j]) + 1] = prod[i];
            }
        }
    }

    table[0][0] = " ";
    table[0][1] = "a";
    table[0][2] = "b";
    table[0][3] = "c";
    table[0][4] = "d";
    table[0][5] = "$";
    table[1][0] = "S";
    table[2][0] = "A";
    table[3][0] = "B";
    table[4][0] = "C";
}

// Print the parsing table
void printParsingTable() {
    cout << "\nPredictive Parsing Table:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << table[i][j] << "\t";
            if (j == 5)
                cout << "\n";
        }
    }
}

int main() {
    generateParsingTable();
    printParsingTable();
    return 0;
}
