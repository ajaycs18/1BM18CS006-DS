#include <stdio.h>

#define SIZE 3

typedef int queue[SIZE];

void insert(queue q, int *r, int e) {
	if (*r == SIZE) {
		printf("overflow\n");
		return;
	}
	q[(*r)++] = e;
}

int delete(queue q, int *f, int *r) {
	if (*f == *r) {
		printf("underflow\n");
		*f = *r = 0;
		return -999;
	}
	return q[(*f)++];

}

void display(queue q, int f, int r) {
	for (int i = f; i < r; i++) {
		printf("%d ", q[i]);
	}
	printf("\n");
}

int main() {
	queue q;
	int f = 0, r = 0;
	int choice;

	do {
		printf("---------------enter choice-----------\n1. insert\n2. delete\n3. display\n0. exit\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1: 
				;
				int ele;
				printf("enter element to insert: ");
				scanf("%d", &ele);
			       	insert(q, &r, ele);	
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
