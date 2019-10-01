#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

typedef struct node* NODE;

NODE getNode() {
	NODE n = malloc(sizeof(struct node));
	if (n == NULL) {
		printf("no free space in heap\n");
		exit(0);
	}
	n->val = 0;
	n->next = NULL;
	return n;
}

NODE push(NODE top, int ele, int *count, int size) {
	if (*count == size) {
		printf("Overflow\n");
		return top;
	}
	NODE n = getNode();
	n->val = ele;
	n->next = top;
	top = n;
	++(*count);
	return n;
}

NODE pop(NODE top, int *count, int size) {
	if (top == NULL) {
		printf("Stack is empty\n");
		return NULL;
	}
	NODE popped = top;
	top = top->next;
	printf("Popped: %d\n", popped->val);
	free(popped);
	--(*count);
	return top;
}

void display(NODE top) {
	NODE curr = top;
	if (top == NULL) {
		printf("Stack is empty\n");
		return;
	}
	while (curr != NULL) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

int main() {
	NODE top = NULL;
	int choice, ele, size = 3, count = 0;
	do {
		printf("1. Insert\n2. Pop\n3. Display\n0. Exit\nEnter Choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter element to insert: ");
				scanf("%d", &ele);
				top = push(top, ele, &count, size);
				break;

			case 2: 
				top = pop(top, &count, size);
				break;

			case 3:
				display(top);
				break;
		}
	} while (choice != 0);
	return 0;
}
