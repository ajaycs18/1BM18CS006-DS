#include <stdio.h>

#define SIZE 3

typedef int queue[SIZE];

void insert(queue q, int *f, int *r, int ele) {
	if (*f == *r + 1 || *r == SIZE-1) {
		printf("overflow\n");
		return;
	}
	else if (*f == -1) *f = 0;

	*r = (*r + 1) % SIZE;
	q[*r] = ele;
}

int delete(queue q, int *f, int *r) {
	int item = q[*f];

	if (*f > *r) {
		printf("underflow\n");
		*f = *r = -1;
		return -999;
	}

	*f = (*f + 1) % SIZE;
	return item;
}

void display(queue q, int f, int r) {
	printf("circular queue: ");

	if (f != -1 && r != -1) {
		for (int i = f; i != r; i = (i + 1) % SIZE) {
			printf("%d ", q[i]);
		}
		printf("%d\n", q[r]);
	}
	printf("\n");
}

int main() {
	queue q;
	int f = -1, r = -1; 
	int choice;

	do {
		printf("---------enter choice----------\n1. insert\n2. delete\n3. display\n0. exit\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				; // empty statement to allow below declaration
				int ele;
				printf("enter element to insert: ");
				scanf("%d", &ele);
				insert(q, &f, &r, ele);
				break;

			case 2: 
				printf("deleted element: %d\n", delete(q, &f, &r));
				break;

			case 3:
				display(q, f, r);
				break;
		}

	} while (choice != 0);

	return 0;
}
