#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 30
struct Stack {
    char items[MAX];
    int top;
};

struct EvalStack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void initEvalStack(struct EvalStack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isEvalEmpty(struct EvalStack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

void evalPush(struct EvalStack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '#';
    } else {
        return s->items[(s->top)--];
    }
}

int evalPop(struct EvalStack *s) {
    if (isEvalEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// Function to check Stack Precedence
int stackprec(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}
// Function to check Input Precedence
int inprec(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^':
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

// Function to convert Infix to Postfix Expression
void infixtopostfix(char infix[], char postfix[]) {
    struct Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char symbol;
    push(&s, '#');

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        while (stackprec(s.items[s.top]) > inprec(symbol)) {
            postfix[j++] = pop(&s);
        }
        if (stackprec(s.items[s.top]) != inprec(symbol)) {
            push(&s, symbol);
        } else {
            pop(&s);
        }
    }
    while (s.items[s.top] != '#') {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// Function to Evaluate Postfix Expression
void postfixevaluate(char postfix[]) {
    struct EvalStack s;
    initEvalStack(&s);
    int i, op1, op2, res;
    char ch;

    for (i = 0; i < strlen(postfix); i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            evalPush(&s, ch - '0');
        } else {
            if (isEvalEmpty(&s)) {
                printf("Not enough operands\n");
            } else {
                op2 = evalPop(&s);
                op1 = evalPop(&s);
                switch (ch) {
                    case '+': res = op1 + op2; break;
                    case '-': res = op1 - op2; break;
                    case '/': res = op1 / op2; break;
                    case '*': res = op1 * op2; break;
                    case '%': res = op1 % op2; break;
                    default: printf("Invalid Operator\n");
                }
                evalPush(&s, res);
            }
        }
    }
    printf("Final Result = %d\n", evalPop(&s));
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;

    printf("Menu\n1.Enter Infix Expression\n2.Convert to Postfix\n3.Evaluate Postfix\n4.Exit\n");
    for (;;) {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter the Infix Expression: ");
                scanf("%s", infix);
                break;
            case 2: 
                infixtopostfix(infix, postfix);
                printf("The Postfix Expression is: %s\n", postfix);
                break;
            case 3: 
                postfixevaluate(postfix);
                break;
            case 4: 
                printf("!! THANK YOU !!\n");
                exit(0);
            default: 
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
