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

int precedance(char c) {
  switch (c) {
    case '(':
    case ')':
      return 0;
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
  if (precedance(c) == -1) return 1;
  return 0;
}

int main(int argc, char **argv) {
  char *exp = argv[1];
  char stack[100];
  int top = -1;

  for (int i = 0; exp[i] != '\0'; i++) {
    if (isOperand(exp[i])) {
      printf("%c", exp[i]);
    } 
    else {
      if (exp[i] == '(')
        push(stack, &top, exp[i]);

      else if (exp[i] == ')') {
        char c;
        while ((c = pop(stack, &top)) != '(') printf("%c", c);
      } 

      else if (precedance(exp[i]) < precedance(stack[top])) {
        while (precedance(stack[top]) >= precedance(exp[i]))
          printf("%c", pop(stack, &top));
        push(stack, &top, exp[i]);
      }

      else {
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
