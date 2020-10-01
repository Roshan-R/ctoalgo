#include <ctype.h>

typedef struct {
    /* Declare the stack */
    float arr[100];
}
Stack;
Stack stack;
int top = -1;
/*
Complete the evaluate function which takes the postfix expression
and the length of expression as arguments and returns the result.
*/
void push(float x) {
    stack.arr[++top] = x;
}
float pop() {
    return stack.arr[top--];
}
float evaluate(char expression[], int len) {
    int i;
    char ch;
    float val;
    float A, B;
    for (i = 0; i < len; i++) {
        ch = expression[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            A = pop();
            B = pop();
            switch (ch) /* ch is an operator */ {
            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;
            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
    }
    return pop();
}
