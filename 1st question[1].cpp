#include <stdio.h>
#include <string.h>
#192210127

typedef enum { q0, q1, q2, q3 } State;

State getNextState(State currentState, char input) {
    switch (currentState) {
        case q0:
            if (input == 'a') return q1;
            else return q3;
        case q1:
            if (input == 'a') return q2;
            else return q1;
        case q2:
            if (input == 'a') return q2;
            else return q1;
        case q3:
            return q3;
        default:
            return q3;
    }
}

int isAcceptedByDFA(const char *input) {
    State currentState = q0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        currentState = getNextState(currentState, input[i]);
    }

    return currentState == q2;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAcceptedByDFA(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }

    return 0;
}
