#include <stdio.h>
#include <string.h>
#192210127

int isBelongToCFG(char *str, int start, int end) {
	
    if (start > end) {
        return 1;
    }
    
    if (str[start] == 'A' && str[end] == 'A' && end - start >= 4 &&
        str[start + 1] == '1' && str[start + 2] == '0' && str[start + 3] == '1') {
        	
        return isBelongToCFG(str, start + 1, end - 1);
    }
    
    if (str[start] == '0' && isBelongToCFG(str, start + 1, end)) {
        return 1;
    }
    
    if (str[start] == '1' && isBelongToCFG(str, start + 1, end)) {
        return 1;
    }
    
    if (str[start] == '\0') {
        return 1;
    }
    
    return 0;
}
int belongsToCFG(char *str) {
    int len = strlen(str);
    return isBelongToCFG(str, 0, len - 1);
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
