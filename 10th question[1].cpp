#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool simulateNFA(char *str) {
    int currentState = 0; 
    int len = strlen(str);
    
    for (int i = 0; i < len; ++i) {
        switch (currentState) {
            case 0: 
                if (str[i] == '1')
                    currentState = 1; 
                break;
            case 1: // State q1
                if (str[i] == '1')
                    currentState = 1; 
                break;
        }
    }
    
    return currentState == 1; 
}

int main() {
    char str[100];

    printf("Enter a string to check if it starts with '1' and ends with '1':\n");
    scanf("%s", str);

    if (simulateNFA(str)) {
        printf("The string \"%s\" is accepted by the NFA.\n", str);
    } else {
        printf("The string \"%s\" is not accepted by the NFA.\n", str);
    }

    return 0;
}
