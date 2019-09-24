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
		return -1;
	}
	n->val = 0;
	n->next = NULL;
	return n;
}

NODE insertBeg(NODE head, int val) {
	NODE n = getNode();
	n->val = val;
	n->next = head;
	head = n;
	return head;
}

NODE insertEnd(NODE head, int val) { 
	NODE temp = head, n = getNode();
	n->val = val;
	if (head == NULL) 
	    return n;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	return head;
}

NODE insertPos(NODE head, int val, int pos) {
	if (head == NULL) {
		if (pos == 1) {
			head = getNode();
			head->val = val;
			return head;
		}
		printf("list is empty\n");
		return NULL;
	}
	NODE temp = head, n = getNode();
	n->val = val;
	if (pos == 1) {
		n->next = head;
		head = n;
		return head;
	}
	int count = 1;
	while (count < pos-1) {
		temp = temp->next;
		if (temp == NULL) {
			printf("position out of range\n");
			return head;
		}
		count++;
	}
	n->next = temp->next;
	temp->next = n;
}

void displayLL(NODE head) {
	if (head == NULL) {
		printf("list is empty\n");
		return;
	}
	NODE temp = head;
	while (temp != NULL) {
		printf("%d->", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	NODE head = NULL;
	do {
		int choice, val;
		printf("1. insert beg\n2. insert at pos\n3. insert end\n4. display ll\n5. quit\n");
	      	scanf("%d", &choice);
		switch (choice) {
			case 1: 
				printf("enter value of node: ");
				scanf("%d", &val);
				head = insertBeg(head, val);
				break;
			case 2: 
				printf("enter value of node: ");
				int pos;
				scanf("%d", &val);
				printf("enter pos of node: ");
				scanf("%d", &pos);
				head = insertPos(head, val, pos);
				break;
			case 3: 
				printf("enter value of node: ");
				scanf("%d", &val);
				head = insertEnd(head, val);
				break;

			case 4:
				displayLL(head);
				break;

			case 5: 
				return 0; // return from main()
		}	
	} while (1);
}
