#include <stdlib.h>
#include <stdio.h>
#define Max 100

typedef struct node *PtrToNode;
typedef PtrToNode Node;

struct node {
	int date;
	Node left;		
	Node right;
};

typedef struct TreeNode *PtrToTnode;
typedef PtrToTnode Tree;
struct TreeNode {
	Node root;
};

typedef struct stack *PtrToSnode;
typedef PtrToSnode Stack;
struct stack {
	int Top;
	Node Array[Max];
};

Stack InitializeStack(Stack S) {
	S = (Stack)malloc(sizeof(struct stack));
	S->Top = 0;	
	int i;
	for (i=0; i<Max; i++)
		S->Array[i] = NULL;
	return S;
}

void Push(Stack S, Node node) {
	printf("%3d", node->date);
	S->Array[S->Top++] = node;
}

void Pop(Stack S) {
	S->Array[--S->Top] = NULL;
}

void Put(Stack S) {
	Node tmp = S->Array[S->Top-1]->left;	
	while (tmp != NULL) {
		Push(S, tmp);	
		tmp = tmp->left;
	}
}

void Stackpreorder(Tree tree, Stack S) {
	Node tmp = tree->root;
	if (tmp == NULL)
		return;
	Push(S, tmp);
	Put(S);
	while (S->Top > 0) {
		if (S->Array[S->Top-1]->right != NULL) {
			tmp = S->Array[S->Top-1]->right;
			Pop(S);
			Push(S, tmp);
			Put(S);
		}
		else  
			Pop(S);
	}
}

Tree InitializeTree(Tree tree) {
	tree = (Tree)malloc(sizeof(struct TreeNode));
	tree -> root = NULL;
	return tree;
}

void Insert(Tree tree, int value) {
	Node new = (Node)malloc(sizeof(struct node));
	new -> left  = NULL;
	new -> right = NULL;
	new -> date  = value;
	if (tree->root == NULL) {
		tree->root = new;			
		return;
	}
	Node tmp = tree->root;
	while (1) {
		if (value <= tmp->date) {
			if (tmp->left == NULL) {
				tmp->left = new;
				break;
			}
			else 
				tmp = tmp->left; 
		}
		if (value > tmp->date) {
			if (tmp->right == NULL) {
				tmp->right = new;
				break;
			}
			else 
				tmp = tmp->right;
		}	
	}	
}


void pre(Node node) {
	if (node == NULL)
		return;
	printf("%3d", node->date);
	pre(node-> left);
	pre(node->right);
}

void preorder(Tree tree) {
	pre(tree->root);
}

int main() {
	Tree tree = InitializeTree(tree);
	Stack S   = InitializeStack(S);
	int n;
	while (scanf("%d", &n)) 
		Insert(tree, n);	
	puts("preorder");
	preorder(tree);
	printf("\n");
	puts("Stack");
	Stackpreorder(tree, S);	
	printf("\n");
}
