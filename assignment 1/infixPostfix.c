#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

void push(Stack *s, int item) {
    if (s->top == (MAX - 1)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop '('
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(s.items[s.top]) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (isOperator(ch)) {
            int b = pop(&s);
            int a = pop(&s);
            switch (ch) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                case '^': push(&s, (int)pow(a, b)); break;
            }
        }
    }
    return pop(&s);
}

void menu() {
    printf("Menu:\n");
    printf("1. Convert Infix to Postfix\n");
    printf("2. Evaluate Postfix Expression\n");
    printf("3. Exit\n");
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;
            case 2:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                printf("Result: %d\n", evaluatePostfix(postfix));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
