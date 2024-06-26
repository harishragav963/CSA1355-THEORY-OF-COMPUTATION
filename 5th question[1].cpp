#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#192210127

bool isValidString(const char *str) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        if (str[left] == '0' && str[right] == '0') {
            left++;
            right--;
        } 
        else if (str[left] == '1') {
            left++;
        } 
        else if (str[right] == '1') {
            right--;
        } 
       
        else {
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
