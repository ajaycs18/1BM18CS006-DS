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

NODE createLL(int val) {
	NODE n = getNode();
	n->val = val;
	return n;
}

NODE insertBeg(NODE head, int val) {
	if (head == NULL) {
		head = getNode();
		head->val = val;
		return head;
	}
	NODE n = getNode();
	n->val = val;
	n->next = head;
	head = n;
	return head;
}

void insertEnd(NODE head, int val){
	if (head == NULL) {
		printf("list is empty\n");
		return;
	}
	NODE temp = head, n = getNode();
	n->val = val;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
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
		printf("1. create ll\n2. insert beg\n3. insert at pos\n4. insert end\n5. display ll\n6. quit\n");
	      	scanf("%d", &choice);
		switch (choice) {
			case 1:
			       	printf("enter value of first node: ");
				scanf("%d", &val);
				head = createLL(val);	
				break;
			case 2: 
				printf("enter value of node: ");
				scanf("%d", &val);
				head = insertBeg(head, val);
				break;
			case 3: 
				printf("enter value of node: ");
				int pos;
				scanf("%d", &val);
				printf("enter pos of node: ");
				scanf("%d", &pos);
				head = insertPos(head, val, pos);
				break;
			case 4: 
				printf("enter value of node: ");
				scanf("%d", &val);
				insertEnd(head, val);
				break;

			case 5:
				displayLL(head);
				break;

			case 6: 
				return 0; // return from main()
		}	
	} while (1);
}

