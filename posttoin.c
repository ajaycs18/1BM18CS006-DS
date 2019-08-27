#include <stdio.h>
#include <stdlib.h>

void push(int s[], int *t, int ele) {
  if (*t == 99) {
    printf("Stack overflow\n");
    return;
  }
  s[++(*t)] = ele;
}

int pop(int s[], int *t) {
  if (*t == -1) {
    printf("Stack underflow\n");
    return '\0';
  }
  return s[(*t)--];
}

int toInt(char num) {
	return (int)num - '0';
}	

int operation(int op1, int op2, char operator) {
	switch (operator) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		default: printf("invalid operator\n");
	}
}

int isOperand(char op){
	if (op >= '0' && op <= '9') return 1;
	else return 0;
}	
 
int main(int argc, char **argv) {
	char *post = argv[1];
	// fgets(post, 100, stdin);
	int stack[100];
	int top = -1;
	int result = 0;
	char literal;

	for (int i = 0; post[i] != '\0'; i++) {
		char literal = post[i];
		if (isOperand(literal)) push(stack, &top, toInt(literal));
		else {
			int op2 = pop(stack, &top), op1 = pop(stack, &top);
			result = operation(op1, op2, literal);
			push(stack, &top, result);
		}
	}	
	printf("%d\n\n", result);
	
	return 0;
}
