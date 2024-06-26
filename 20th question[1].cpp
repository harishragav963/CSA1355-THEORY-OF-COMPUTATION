#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#192210127

bool parseA(const char* str, int* index);
bool parseA(const char* str, int* index) {
    if (str[*index] == '\0') {
        return true;
    }
    if (str[*index] == 'a' || str[*index] == 'b') {
        (*index)++;
        return parseA(str, index);
    }
    return false;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int index = 0;
    if (parseA(input, &index) && input[index] == '\0') {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}
