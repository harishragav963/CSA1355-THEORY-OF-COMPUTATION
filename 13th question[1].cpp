#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

int dfa(char *input_string) {
    int state = 0;  
    for (int i = 0; i < strlen(input_string); ++i) {
        char symbol = input_string[i];

        switch (state) {
            case 0:
                if (symbol == 'a')
                    state = 1;
                else
                    state = -1; 
                break;

            case 1:
                if (symbol == 'a')
                    state = 1;
                else if (symbol == 'b')
                    state = 2;
                else
                    state = -1; 
                break;

            case 2:
                state = -1; 
                break;
        }

        if (state == -1)
            break;
    }

    return state;
}

int main() {
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);

    int final_state = dfa(input_string);

    if (final_state == 2)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
