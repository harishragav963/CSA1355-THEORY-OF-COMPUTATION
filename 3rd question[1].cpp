#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool isValidString(const char *str) {
    int len = strlen(str);
    
    if (len < 2) {
        return false;
    }

    if (str[0] != '0' || str[len - 1] != '1') {
        return false;
    }

    for (int i = 1; i < len - 1; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }

    return true;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does NOT belong to the language defined by the CFG.\n");
    }

    return 0;
}
