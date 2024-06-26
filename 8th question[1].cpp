#include <stdio.h>
#include <string.h>
#192210127

int belongsToCFG(char *str) {
	
    if (*str == '\0') {
        return 1;
    }
    
    if (*str == 'a') {
        return belongsToCFG(str + 1);
    }
    
    return 0;
}

int main() {
    char str[100];

    printf("Enter a string to check if it belongs to the language defined by CFG:\n");
    scanf("%s", str);

    if (belongsToCFG(str)) {
        printf("The string \"%s\" belongs to the language defined by the CFG.\n", str);
    } else {
        printf("The string \"%s\" does not belong to the language defined by the CFG.\n", str);
    }

    return 0;
}
