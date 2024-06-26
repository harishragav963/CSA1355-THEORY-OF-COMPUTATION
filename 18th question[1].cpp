#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STATES 100
#define MAX_SYMBOLS 2
#192210127

typedef struct {
    int numStates;
    int numSymbols;
    int transition[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
    bool finalState[MAX_STATES];
} NFA;

void initializeNFA(NFA *nfa, int numStates, int numSymbols) {
    nfa->numStates = numStates;
    nfa->numSymbols = numSymbols;
    for (int i = 0; i < numStates; ++i) {
        for (int j = 0; j < numSymbols; ++j) {
            for (int k = 0; k < numStates; ++k) {
                nfa->transition[i][j][k] = 0;
            }
        }
        nfa->finalState[i] = false;
    }
}

void addTransition(NFA *nfa, int stateFrom, int symbol, int stateTo) {
    nfa->transition[stateFrom][symbol][stateTo] = 1;
}

void setFinalState(NFA *nfa, int state) {
    nfa->finalState[state] = true;
}

bool simulateNFA(NFA *nfa, const char *input) {
    int currentStates[MAX_STATES] = {0};
    int nextStates[MAX_STATES];
    int numCurrentStates = 1, numNextStates;

    currentStates[0] = 0; 

    for (int i = 0; i < strlen(input); ++i) {
        int symbol = input[i] - '0';
        numNextStates = 0;

        for (int j = 0; j < numCurrentStates; ++j) {
            int currentState = currentStates[j];
            for (int k = 0; k < nfa->numStates; ++k) {
                if (nfa->transition[currentState][symbol][k]) {
                    nextStates[numNextStates++] = k;
                }
            }
        }

        memcpy(currentStates, nextStates, numNextStates * sizeof(int));
        numCurrentStates = numNextStates;

        if (numCurrentStates == 0) {
            return false; 
        }
    }

    for (int i = 0; i < numCurrentStates; ++i) {
        if (nfa->finalState[currentStates[i]]) {
            return true;
        }
    }

    return false;
}

int main() {
    NFA nfa;
    initializeNFA(&nfa, 5, 2); 

    // Transitions for the NFA
    addTransition(&nfa, 0, 0, 1);
    addTransition(&nfa, 1, 0, 2);
    addTransition(&nfa, 2, 0, 2);
    addTransition(&nfa, 2, 1, 3);
    addTransition(&nfa, 3, 1, 4);
    addTransition(&nfa, 4, 0, 3);
    addTransition(&nfa, 4, 1, 4);

    setFinalState(&nfa, 4);

    char input[100];
    printf("Enter a binary string: ");
    scanf("%s", input);

    if (simulateNFA(&nfa, input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}
