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

NODE enqueue(NODE front, int ele, int *count, int size) {
	if (*count == size) {
		printf("Overflow\n");
		return front;
	}
	NODE n = getNode();
	n->val = ele;
	if (front == NULL) {
		front = n;
		++(*count);
		return front;
	}
	NODE last = front;
	while (last->next != NULL) last = last->next;
	last->next = n;
	last = n;
	++(*count);
	return front;
}

NODE dequeue(NODE front, int *count, int size) {
	if (front == NULL) {
		printf("Queue is empty\n");
		return NULL;
	}
	NODE n = front;
	printf("Deleted Element: %d\n", n->val);
	front = front->next;
	free(n);
	--(*count);
	return front;
}

void display(NODE front) {
	if (front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	NODE n = front;
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

int main() {
	NODE front = NULL, rear = NULL;
	int choice, ele, count = 0, size = 3;
	do {
                printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nEnter Choice: ");
                scanf("%d", &choice);

                switch(choice) {
                        case 1:
                                printf("Enter element to insert: ");
                                scanf("%d", &ele);
                                front = enqueue(front, ele, &count, size);
                                break;

                        case 2:
                                front = dequeue(front, &count, size);
                                break;

                        case 3:
                                display(front);
                                break;
                }
        } while (choice != 0);
}

