#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int date;
	struct node *left;	
	struct node *right;	
}Node;


typedef struct {
	Node *root;
}Tree;

void insert(Tree *tree, int value) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->date  = value;
	node->left  = NULL;
	node->right = NULL;
	if (tree->root == NULL)
		tree->root = node;
	else {
		Node *temp = tree->root;	
		while (1) 
		{		
			if (value <= temp->date) {
				if (temp->left == NULL) {	
					temp->left = node;	
					return;
				}
				else {
					temp = temp->left;	
				}
			}
			if (value > temp->date) {
				if (temp->right == NULL) {	
					temp->right = node;
					return;
				}
				else {
					temp = temp->right;	
				}
			}
		}	
	}
}

void preorder(Node *node) {
	if (node == NULL) return; 
	printf("%d\t", node->date);
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node *node) {
	if (node == NULL) return;
	inorder(node->left);
	printf("%d\t", node->date);
	inorder(node->right);
}

void postorder(Node *node) {
	if (node == NULL) return; 
	postorder(node->left);
	postorder(node->right);
	printf("%d\t", node->date);
	
}

int main (void) {
	Tree tree;	
	tree.root = NULL;
	int a[7] = {6, 3, 8, 2, 5, 1, 7};
	int n = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i<n; i++) {
		insert(&tree, a[i]);		
	}
	printf("preorder:\t");
	preorder(tree.root);
	printf("\n");

	printf("inorder:\t");
	inorder(tree.root);
	printf("\n");

	printf("postorder:\t");
	postorder(tree.root);
	printf("\n");

	return 0;
}
