#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
bool isValidCharacters(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

bool isValidString(const char *str) {
     if (!isPalindrome(str)) {
        return false;
    }

    if (!isValidCharacters(str)) {
        return false;
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
