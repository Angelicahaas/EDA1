#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findMaxSubstr(const char* str, const char* sub) {
    if (strlen(str) < strlen(sub))
        return 0;

    if (strncmp(str, sub, strlen(sub)) == 0) {
        if (strncmp(str + strlen(str) - strlen(sub), sub, strlen(sub)) == 0) {
            return strlen(str);
        } else {
            char* newStr = malloc(strlen(str) - 1);
            strncpy(newStr, str, strlen(str) - 1);
            int result = findMaxSubstr(newStr, sub);
            free(newStr);
            return result;
        }
    }

    return findMaxSubstr(str + 1, sub);
}

int main() {
    char str[101];
    char sub[101];

    scanf("%s", str);
    scanf("%s", sub);

    int result = findMaxSubstr(str, sub);
    printf("%d\n", result);
}
