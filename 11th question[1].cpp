#include <stdio.h>
#include <stdbool.h>
#define MAX_STATES 100
#192210127

typedef struct {
    int state;       
    bool isFinal;        
    int transitions[MAX_STATES]; 
} NFAState;
void epsilonClosure(NFAState nfa[], int numStates, int state, bool visited[]) {
    visited[state] = true; 
    for (int i = 0; i < numStates; ++i) {
        int nextState = nfa[state].transitions[i];
        if (nextState != -1 && !visited[nextState]) {
            epsilonClosure(nfa, numStates, nextState, visited);
        }
    }
}
void findAllEpsilonClosures(NFAState nfa[], int numStates) {
    printf("e-closures for all states:\n");
    for (int i = 0; i < numStates; ++i) {
        bool visited[MAX_STATES] = { false };
        epsilonClosure(nfa, numStates, i, visited);
        
        printf("E(%d): { ", i);
        for (int j = 0; j < numStates; ++j) {
            if (visited[j]) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
}

int main() {
    int numStates;
    
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &numStates);
    
    NFAState nfa[numStates];
    for (int i = 0; i < numStates; ++i) {
        printf("Enter the number of transitions for state q%d (enter -1 to end): ", i);
        int transition;
        int index = 0;
        
        while (true) {
            scanf("%d", &transition);
            if (transition == -1) break;
            nfa[i].transitions[index++] = transition;
        }
        nfa[i].transitions[index] = -1; 
    }
    findAllEpsilonClosures(nfa, numStates);
    
    return 0;
}
