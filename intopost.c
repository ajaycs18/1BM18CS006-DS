#include <stdio.h>

void push(char stack[], int *top, char ele) {
  if (*top == 99) {
    printf("Stack overflow\n");
    return;
  }
  stack[++(*top)] = ele;
}

char pop(char stack[], int *top) {
  if (*top == -1) {
    printf("Stack underflow\n");
    return '\0';
  }
  return stack[(*top)--];
}

int precedence(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return -1;
  }
}

int isOperand(char c) {
  if (precedence(c) == -1) return 1;
  return 0;
}

int main(int argc, char **argv) {
  char *exp;
  fgets(exp, 100, stdin);
  char stack[100];
  int top = -1, i;

  for (i = 0; exp[i] != '\n'; i++) {
    if (isOperand(exp[i])) {
        if (exp[i] != '(' && exp[i] != ')')
            printf("%c", exp[i]);
    } 
    else {
      if (exp[i] == '(' || precedence(exp[i]) > precedence(stack[top]))
        push(stack, &top, exp[i]);

      else if (exp[i] == ')') {
        char c;
        while ((c = pop(stack, &top)) != '(') printf("%c", c);
      } 

      else {
        while (precedence(stack[top]) >= precedence(exp[i]))
          printf("%c", pop(stack, &top));
        push(stack, &top, exp[i]);
      }
    }
  }

  while (top > -1) {
    if (stack[top] != '(' && stack[top] != ')') printf("%c", pop(stack, &top));
  }

  printf("\n");

  return 0;
}
