#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool is_terminal(char symbol);
bool is_nonterminal(char symbol);
bool parse_S(char *input, int *index);
bool parse_A(char *input, int *index);
bool is_terminal(char symbol) {
    return (symbol == '0' || symbol == '1');
}
bool is_nonterminal(char symbol) {
    return (symbol == 'S' || symbol == 'A');
}
bool parse_S(char *input, int *index) {
    int start_index = *index;
    if (parse_A(input, index)) {
        // Match '00'
        if (input[*index] == '0') {
            (*index)++;
            if (input[*index] == '0') {
                (*index)++;
                // Match A
                if (parse_A(input, index)) {
                    return true;
                }
            }
        }
    }
    *index = start_index;
    return false;
}
bool parse_A(char *input, int *index) {
    int start_index = *index;
    if (input[*index] == '\0') {
        return true;
    }
    if (is_terminal(input[*index]) && input[*index + 1] == 'A') {
        (*index)++;
        (*index)++;
        if (parse_A(input, index)) {
            return true;
        }
    }
    *index = start_index;
    return false;
}
bool belongs_to_CFG(char *input) {
    int index = 0;
    return parse_S(input, &index) && input[index] == '\0';
}

int main() {
    char input[100];
    printf("Enter a string to check: ");
    scanf("%s", input);

    if (belongs_to_CFG(input)) {
        printf("The string \"%s\" belongs to the CFG language.\n", input);
    } else {
        printf("The string \"%s\" does not belong to the CFG language.\n", input);
    }

    return 0;
}
