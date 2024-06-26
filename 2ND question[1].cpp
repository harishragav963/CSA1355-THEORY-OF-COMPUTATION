#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

typedef enum {
    START,
    S1,
    S2,
    ACCEPT,
    REJECT
} State;

State getNextState(State currentState, char input) {
    switch (currentState) {
        case START:
            if (input == '0') return S1;
            else return REJECT;
        case S1:
            if (input == '0' || input == '1') return S2;
            else return REJECT;
        case S2:
            if (input == '1') return ACCEPT;
            else return S2;
        case ACCEPT:
            return REJECT;
        case REJECT:
            return REJECT;
        default:
            return REJECT;
    }
}

bool isAccepted(const char* str) {
    State currentState = START;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        currentState = getNextState(currentState, str[i]);
    }

    return currentState == ACCEPT;
}

int main() {
    char input[100];

    printf("Enter a binary string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }

    return 0;
}
