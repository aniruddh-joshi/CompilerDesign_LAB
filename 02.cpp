#include <iostream>
using namespace std;

int main() {
    int nfa[4][2] = {{0}}; // Initialize NFA with zeros
    nfa[1][0] = 2;
    nfa[1][1] = 13;
    nfa[2][0] = 2;
    nfa[2][1] = 1;
    nfa[3][0] = 2;
    nfa[3][1] = 3;

    int dfa[10][2] = {{0}}; // Initialize DFA with zeros
    int dstate[10] = {0}; // Initialize dstate with zeros
    int n = 1, k, flag = 0, m, q, r;
    dstate[n++] = 1;
    
    for (k = 1; dstate[k] != 0; k++) {
        m = dstate[k];
        if (m > 10) {
            q = m / 10;
            r = m % 10;
        } else {
            q = 0;
            r = m;
        }
        for (int j = 0; j < 2; j++) {
            dfa[k][j] = nfa[r][j];
            flag = 0;
            for (int i = 1; i < n; i++) {
                if (dfa[k][j] == dstate[i]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag && dfa[k][j] != 0) {
                dstate[n++] = dfa[k][j];
            }
        }
    }
    
    // Print DFA transition table
    cout << "DFA Transition Table:" << endl;
    cout << "State   |   a   |   b" << endl;
    cout << "-----------------------" << endl;
    for (int i = 1; i < k; i++) {
        cout << "  " << i << "     |   " << dfa[i][0] << "   |   " << dfa[i][1] << endl;
    }

    return 0;
}


//OUTPUT:
DFA Transition Table:
State   |   a   |   b
-----------------------
  1     |   2   |   13
  2     |   2   |   1
  3     |   2   |   3


The code appears to be an implementation of converting a nondeterministic finite automaton (NFA) to a deterministic finite automaton (DFA) using the subset construction method.
It initializes an NFA transition table nfa and then constructs a corresponding DFA transition table dfa along with the DFA states dstate.
