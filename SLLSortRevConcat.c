#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};
typedef struct node* NODE;

NODE getNode() {
	NODE n = malloc(sizeof(struct node));
	n->val = 0;
	n->next = NULL;
	return n;
}

void display(NODE head) {
	if (head == NULL) { 
		printf("Empty list\n");
		return;
	}
	while (head != NULL) {
		printf("%d->", head->val);
		head = head->next;
	}
	printf("\n");
}

NODE rev(NODE head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL) 
		return head;

	NODE tail = rev(head->next);
	head->next->next = head;
	head->next = NULL;
	return tail;
}

NODE sort(NODE head) {
	int len = 0;
	NODE curr = head;

	while (curr != NULL) {
		curr = curr->next;
		len++;
	} 

	for (int i = 0; i < len - 1; i++) {
		curr = head;
		for (int j = 0; j < len - 1 - i; j++) {
			if (curr->val > curr->next->val) {
				int temp = curr->val;
				curr->val = curr->next->val;
				curr->next->val = temp;
			}
			curr = curr->next;
		}
	}

	return head;
}

NODE concat(NODE h1, NODE h2) {
	if (h1 == NULL || h2 == NULL)
		return h1 == NULL ? h2 : h1;

	NODE head = h1;
	while (h1->next != NULL) h1 = h1->next;
	
	h1->next = h2;
	return head;
}

NODE insertBeg(NODE head, int val) {
	NODE n = getNode();
	n->val = val;
	n->next = head;
	return n;
}

int main() {
	int val = 0, choice;
	NODE head1 = NULL, head2 = NULL, head12 = NULL;

	printf("Enter LL 1, enter -1 to stop: ");
	scanf("%d", &val);
	while (val != -1) {
		head1 = insertBeg(head1, val);
		scanf("%d", &val);
	}

	printf("Enter LL 2, enter -1 to stop: ");
	scanf("%d", &val);
	while (val != -1) {
		head2 = insertBeg(head2, val);
		scanf("%d", &val);
	}
	
	while (1) {
		printf("1. Sort\n2. Reverse\n3. Concatenate\n4. Display\n");
		printf("Enter Choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				head1 = sort(head1);
				head2 = sort(head2);
				break;

			case 2:
				head1 = rev(head1);
				head2 = rev(head2);
				break;

			case 3:
				head12 = concat(head1, head2);
				break;

			case 4:
				printf("List 1: ");
				display(head1);
				printf("List 2: ");
				display(head2);
				printf("Concatenated List: ");
				display(head12);
				break;
		}
	}

	return 0;
}
