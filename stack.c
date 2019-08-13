#include <stdio.h>

void push(int *s, int *t, int ele) {
	if (*t == 99) {
		printf("Stack Overflow\n");
		return;
	}
	s[++(*t)] = ele;
}

int pop(int *s, int *t) {
	if (*t == -1) {
		printf("Stack Underflow\n");
		return -1;
	}
	int popped = s[(*t)--];
	return popped;
}

void display(int *s, int t) {
	if (t == -1) {
		printf("Stack is empty\n");
		return;
	}
	int i;
	for (i = 0; i <= t; ++i) {
		printf("%d ", s[i]);
	}
	printf("\n");
}

int main(int ) {
	int stack[100], top = -1;

	push(stack, &top, 1);
	push(stack, &top, 2);
	push(stack, &top, 3);
	push(stack, &top, 4);
	push(stack, &top, 5);

	display(stack, top);

	printf("Popped: %d\n", pop(stack, &top));
	display(stack, top);

	printf("Popped: %d\n", pop(stack, &top));
	display(stack, top);

	return 0;
}
