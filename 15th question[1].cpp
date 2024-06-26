#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STATES 100
#define MAX_TRANSITIONS 100
#192210127

struct State {
    int id;
    bool is_final;
    int transitions[MAX_TRANSITIONS][2];
};
void epsilon_closure(struct State nfa[], int state_id, bool visited[], int closure[]) {
    visited[state_id] = true;
    closure[state_id] = 1; 
    for (int i = 0; nfa[state_id].transitions[i][0] != -1; ++i) {
        int symbol = nfa[state_id].transitions[i][0];
        int next_state = nfa[state_id].transitions[i][1];
        if (symbol == 0 && !visited[next_state]) {
            epsilon_closure(nfa, next_state, visited, closure);
        }
    }
}
void compute_epsilon_closures(struct State nfa[], int num_states) {
    int epsilon_closures[MAX_STATES][MAX_STATES] = {0}; 

    for (int i = 0; i < num_states; ++i) {
        bool visited[MAX_STATES] = {false};
        int closure[MAX_STATES] = {0};
        epsilon_closure(nfa, i, visited, closure);

        for (int j = 0; j < num_states; ++j) {
            if (closure[j] == 1) {
                epsilon_closures[i][j] = 1;
            }
        }
    }
    printf("Epsilon Closures:\n");
    for (int i = 0; i < num_states; ++i) {
        printf("e-closure(%d): { ", i);
        for (int j = 0; j < num_states; ++j) {
            if (epsilon_closures[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
}

int main() {
    struct State nfa[] = {
        {0, false, {{0, 1}, {0, 2}, {-1, -1}}}, 
        {1, false, {{1, 3}, {-1, -1}}},        
        {2, false, {{0, 3}, {-1, -1}}},        
        {3, true, {{-1, -1}}}                  
    };

    int num_states = 4; 

    compute_epsilon_closures(nfa, num_states);

    return 0;
}
