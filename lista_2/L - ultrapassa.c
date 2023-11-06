#include <stdio.h>
#include <stdlib.h>

int main() {
    int *list = NULL;
    int num, count = 0;
    int limsum;

    do {
        scanf("%d", &num);
        if (num != 0) {
            list = realloc(list, (count + 1) * sizeof(int));
            list[count] = num;
            count++;
        }
    } while (num != 0);

    scanf("%d", &limsum);

    int result = 0;
    int *newlist = NULL;
    int newListCount = 0;

    for (int i = 0; i < count; i++) {
        result += list[i];
        if (result > limsum) {
            newlist = realloc(newlist, (newListCount + 1) * sizeof(int));
            newlist[newListCount] = list[i];
            newListCount++;
            result = 0;
        }
    }

    for (int i = newListCount - 1; i >= 0; i--) {
        printf("%d\n", newlist[i]);
    }

    free(list); // Liberar a memória alocada para lista
    free(newlist); // Liberar a memória alocada para nova Lista

    return 0;
}
