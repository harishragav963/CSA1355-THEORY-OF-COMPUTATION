#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool nfa(char *input_string) {
    int current_states[3] = {0}; 
    int next_states[3][2] = {
        {0, 1},  
        {-1, 2},   
        {-1, -1}    
    };

    current_states[0] = 1;

    for (int i = 0; i < strlen(input_string); ++i) {
        char symbol = input_string[i];
        int temp_states[3] = {0};
        for (int j = 0; j < 3; ++j) {
            if (current_states[j] != -1) {
                int next_state = next_states[j][0];
                if (symbol == 'b' && next_state != -1)
                    temp_states[next_state] = 1;
                
                next_state = next_states[j][1];
                if (symbol == 'a' && next_state != -1)
                    temp_states[next_state] = 1;
            }
        }
        for (int j = 0; j < 3; ++j) {
            current_states[j] = temp_states[j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (current_states[i] == 2)
            return true;
    }

    return false;
}

int main() {
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);

    bool accepted = nfa(input_string);

    if (accepted)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
