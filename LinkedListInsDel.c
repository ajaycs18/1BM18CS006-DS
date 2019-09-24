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

NODE deleteBeg(NODE head) {
	if (head == NULL) {
		printf("list is empty\n");
		return NULL;
	}
	printf("deleted element: %d\n", head->val);
	NODE curr = head;
	head = head->next;
	free(curr);
	return head;
}

NODE deleteEnd(NODE head) {
	if (head == NULL) {
		printf("list is empty\n");
		return NULL;
	}
	if (head->next == NULL) {
		printf("deleted element: %d\n", head->val);
		return NULL;
	}
	NODE curr = head->next, prev = head;
	while (curr->next != NULL) { 
		prev = curr;
		curr = curr->next;
	}
	printf("deleted element: %d\n", curr->val);
	prev->next = NULL;
	free(curr);
	return head;
}

NODE deleteEle(NODE head, int ele) {
	if (head == NULL) {
		printf("list is empty\n");
		return NULL;
	}
	else if (head->val == ele) {
		printf("deleted element: %d\n", head->val);
		free(head);
		return NULL;
	}
	else {
		NODE curr = head->next, prev = head;
		while (curr->val != ele) {
			prev = curr;
			curr = curr->next;
			if (curr == NULL) {
				printf("element %d not found\n", ele);
				return head;
			}
		}
		printf("deleted element: %d\n", curr->val);
		prev->next = curr->next;
		free(curr);
		return head;
	}
	
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
	int ele;
	do {
		int choice, val;
		printf("1. insert beg\n2. insert at pos\n3. insert end\n4. delete beg\n5. delete element\n6. delete end\n7. display ll\n8. quit\n");
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
				head = deleteBeg(head);
				break;
				
			case 5:
				printf("enter the element to delete: ");
				scanf("%d", &ele);
				head = deleteEle(head, ele);
				break;
				
			case 6:
				head = deleteEnd(head);
				break;

			case 7:
				displayLL(head);
				break;

			case 8: 
				return 0; // return from main()
		}	
	} while (1);
}
