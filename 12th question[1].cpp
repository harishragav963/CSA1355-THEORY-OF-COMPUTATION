#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool simulateDFA(char *str) {
    int currentState = 0; 
    int len = strlen(str);
    
    for (int i = 0; i < len; ++i) {
        switch (currentState) {
            case 0: 
                if (str[i] == 'b')
                    currentState = 1; 
                break;
            case 1: 
                break;
        }
    }
    
    return currentState == 1; 
}

int main() {
    char str[100];

    printf("Enter a string to check if it starts with 'b' and ends with 'b':\n");
    scanf("%s", str);

    if (simulateDFA(str)) {
        printf("The string \"%s\" is accepted by the DFA.\n", str);
    } else {
        printf("The string \"%s\" is not accepted by the DFA.\n", str);
    }

    return 0;
}
