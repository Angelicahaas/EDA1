#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct Stack {
    Item *arr;
    int capacity;
    int top;
} Stack;

int createStack(Stack *stack, int capacity) {
    stack->capacity = capacity;
    stack->arr = (Item *)malloc(capacity * sizeof(Item));
    stack->top = -1;
    return 1;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int push(Stack *stack, Item item) {
    if (isFull(stack)) return 0;
    stack->arr[++stack->top] = item;
    return 1;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return 0;
    return stack->arr[stack->top--];
}

char cadeia_bem_definida(char *expression) {
    Stack stack;
    int length = 0;

    while (expression[length] != '\0') {
        length++;
    }

    createStack(&stack, length);

    for (int i = 0; i < length; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack)) {
                return 'N';
            }

            char topElement = pop(&stack);

            if ((expression[i] == ')' && topElement != '(') ||
                (expression[i] == ']' && topElement != '[') ||
                (expression[i] == '}' && topElement != '{')) {
                return 'N';
            }
        }
    }

    return isEmpty(&stack) ? 'S' : 'N';
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char expression[100001];
        scanf("%s", expression);
        printf("%c\n", cadeia_bem_definida(expression));
    }

    return 0;
}
