#include <stdio.h>
#include <string.h>

int main() {
    char num[1001];
    
    while (1) {
        scanf("%s", num);
        if (num[0] == '0') {
            break;
        }

        int sum = 0;
        int len = strlen(num);
        
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }

        int degree = 1;
        
        while (sum != 9 && sum % 9 == 0) {
            char sum_str[1001];
            sprintf(sum_str, "%d", sum);
            sum = 0;

            for (int i = 0; i < strlen(sum_str); i++) {
                sum += sum_str[i] - '0';
            }
            
            degree++;
        }

        if (sum == 9) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, degree);
        } else {
            printf("%s is not a multiple of 9.\n", num);
        }
    }

    return 0;
}
