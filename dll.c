#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
	struct node *prev;
};

typedef struct node * NODE;

NODE getnode() {
	NODE n;
	n = malloc(sizeof(struct node));
	if(n != NULL)
		return n;
	else
	{
		printf("memory could not be allocated\n");
		exit(0);
	}
}

NODE insertFront(NODE head, int item) {
	NODE newn;
	newn = getnode();
	newn->val = item;
	newn->prev = NULL;
	if(head == NULL)
	{
		newn->next = NULL;
		head = newn;
	}
	else
	{
		newn->next = head;
		head->prev = newn;
		head = newn;
	}
	return head;
}

NODE insertLeft(NODE head, int item, NODE n) {
	NODE newn;
	newn = getnode();
	newn->val = item;
	if(n->prev == NULL)
	{
		newn->next = n;
		n->prev = newn;
		newn->prev = NULL;
		head = newn;
	}
	else
	{
		n->prev->next = newn;
		newn->prev = n->prev;
		newn->next = n;
		n->prev = newn;
	} 
	return head;
}

NODE del_val(NODE head,int val) {
	NODE curr = head;
	
	if(head == NULL)
	{
		printf("empty list\n");
		return head;
	}
	
	while(curr != NULL)
	{
		if(curr->val == val)
			{
				if (curr == head) {
					if (head->next != NULL)
						head->next->prev = NULL;
					head = head->next;
					free(curr);
					return head;
				}
				if(curr->next == NULL)
				{
					curr->prev->next = NULL;
					free(curr);
					return head;
				}
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
					free(curr);
					return head;
				}
			}
			curr = curr->next;
	}
	
	if(curr == NULL)
	{
		printf("value not found\n");
		return head;
	}
}

void display(NODE head) {
	NODE curr;
	if(head == NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	curr = head;
	while(curr != NULL)
	{
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

int main() {
	NODE head = NULL;
	NODE curr;
	int ch,item,n,i,c,val,pos;
	while(ch != -1) {
		printf("1.create a DLL\n2.insert left of given node\n3.delete value\n4.display\n");
		printf("enter choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:printf("enter the no.of items\n");
				scanf("%d",&n);
				printf("enter the items\n");
				for(i = 0; i < n; i++)
				{
					scanf("%d",&item);
					head = insertFront(head,item);
				}
				break;
			case 2:
				printf("enter the ele\n");
				scanf("%d", &item);
				printf("enter the nodeval to the left of which new node is inserted\n");
				scanf("%d", &val);	
				curr = head;
				while(curr != NULL)
				{
					if(curr->val == val) {
						head = insertLeft(head,item,curr);
						break;
					}
					curr = curr->next;
				}
				if (curr == NULL) printf("val not found\n");
				break;
			case 3:printf("enter the value of the node to be deleted\n");
				scanf("%d", &val);
				head = del_val(head,val);
				break;
			case 4:display(head);
				break;
			default:printf("invalid input\n");
		}
	}
	return 0;
}
