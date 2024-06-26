#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#192210127

bool parseS(const char* str, int* index);
bool parseA(const char* str, int* index);

bool parseS(const char* str, int* index) {
    int startIndex = *index;
    if (parseA(str, index) && parseA(str, index) && parseA(str, index) && str[*index] == '\0') {
        return true;
    } else {
        *index = startIndex;
        return false;
    }
}


bool parseA(const char* str, int* index) {
    if (str[*index] == 'a' || str[*index] == 'b') {
        (*index)++;
        parseA(str, index);
        return true;
    }
    return true; 
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int index = 0;
    if (parseS(input, &index)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}
