#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *left;
	struct node *right;
};
typedef struct node* NODE;

NODE getNode() {
	NODE n = malloc(sizeof(struct node));
	n->val = 0;
	n->left = n->right = NULL;
	return n;	
}

NODE insert(NODE root, int val) {
	if (!root) {
		NODE n = getNode();
		n->val = val;
		return n;
	}
	else if (val < root->val) 
		root->left = insert(root->left, val);
	else if (val > root->val)
		root->right = insert(root->right, val);

	return root;
}

void inorder(NODE root) {
	if (!root) 
		return;

	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void postorder(NODE root) {
	if (!root) 
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

void preorder(NODE root) {
	if (!root) 
		return;

	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}

int min(NODE root) {
	while (root && root->left)
		root = root->left;
	return root->val;
}

NODE delete(NODE root, int val) {
	if (root == NULL) {
		return NULL;
	}

	if (val < root->val)
		root->left = delete(root->left, val);
	else if (val > root->val)
		root->right = delete(root->right, val);
	else {
		NODE temp = root;
		if (temp->left == NULL && temp->right == NULL) {
			free(temp);
			return NULL;
		}
		else if (root->left || root->right) {
			root->val = root->left ? root->left->val : root->right->val;
			root->left ? free(root->left) : free(root->right);
			root->left = NULL;
			root->right = NULL;
			return root;
		}
		else {
			root->val == min(root->right);
			delete(root->right, temp->val);
			return root;
		}
	}
}

int main() {
	int ele, choice, num;
	NODE root = NULL;

	while (1) {
		printf("1. Create\n2. Inorder\n3. Postorder\n4. Preorder\n5. Delete\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: printf("enter number of nodes: ");
				scanf("%d", &num);
				for (int i = 0; i < num; i++) {
					printf("enter node: ");
					scanf("%d", &ele);
					root = insert(root, ele);
				}
				break;

			case 2: inorder(root);
				printf("\n");
				break;
				
			case 3: postorder(root);
				printf("\n");
				break;
				
			case 4: preorder(root);
				printf("\n");
				break;

			case 5: printf("enter val to delete: ");
				scanf("%d", &ele);
				root = delete(root, ele);
				break;
		}
	}

	return 0;
}
