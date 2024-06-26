#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool isValidString(const char *str) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '0') {
            count++;
        } else if (str[i] == '1') {
            count--;
        } else {
            return false;
        }
        if (count < 0) {
            return false;
        }
    }
    return count == 0;
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
