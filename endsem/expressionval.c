#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STK {
    char stk[1000];
    int top;
};

struct STK* createSTK() {
    struct STK* s = (struct STK*)malloc(sizeof(struct STK));
    s->top = -1;
    return s;
}

int isOperator(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '/') {
        return 1;
    }
    return 0;
}

struct STK* push(struct STK* s, char val) {
    s->top++;
    s->stk[s->top] = val;
    return s;
}

char top(struct STK* s) {
    return s->stk[s->top];
}

int isEmpty(struct STK* s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

struct STK* pop(struct STK* s) {
    if (s->top >= 0) {
        s->top--;
    }
    return s;
}

int getPri(char s) {
    if (s == '+' || s == '-') {
        return 0;
    } else if (s == '*' || s == '/') {
        return 1;
    }
    return -1;  // Invalid operator
}

char* postfix(char exp[], int len) {
    struct STK* val = createSTK();
    struct STK* sym = createSTK();
    int i = 0;

    while (i < len) {
        if (isOperator(exp[i])) {
            while (!isEmpty(sym) && getPri(top(sym)) >= getPri(exp[i])) {
                char tmpTopVal = top(sym);
                sym = pop(sym);
                val = push(val, tmpTopVal);
            }
            sym = push(sym, exp[i]);
        } else if (exp[i] == '(') {
            sym = push(sym, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmpty(sym) && top(sym) != '(') {
                char tmpTopVal = top(sym);
                sym = pop(sym);
                val = push(val, tmpTopVal);
            }
            if (!isEmpty(sym) && top(sym) == '(') {
                sym = pop(sym);
            }
        } else {
            val = push(val, exp[i]);
        }
        i++;
    }

    while (!isEmpty(sym)) {
        char tmpTopVal = top(sym);
        sym = pop(sym);
        val = push(val, tmpTopVal);
    }

    // Allocate memory for the result string
    char* result = (char*)malloc((val->top + 2) * sizeof(char));

    // Copy characters from val->stk to the result string
    for (int i = 0; i <= val->top; i++) {
        result[i] = val->stk[i];
    }

    result[val->top + 1] = '\0';  // Add the null terminator

    return result;
}

int main() {
    char exp[] = "A+B*C-(D/E+F*G)-H";
    int len = strlen(exp);
    char* result = postfix(exp, len);
    printf("Postfix expression: %s\n", result);
    free(result);  // Don't forget to free the dynamically allocated memory
    return 0;
}
