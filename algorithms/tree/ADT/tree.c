#include <stdio.h>  
#include <stdlib.h>
#include "tree.h"

typedef struct pair {
	Trnode *child;	
	Trnode *parent;	
}Pair;

static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static bool AddNode(Trnode *new_node, Tree *ptree);
static void DeleteNode(Trnode **ptr);
static Pair *SeekItem(const Item *pi, const Tree *ptree);
static void DeleteAllNode(Trnode *p);
static void InOrder(Trnode *p, void(*pfun)(Item item));


/* interface fanc */

void InitializeTree(Tree *ptree) {
	if (ptree == NULL) {
		puts("ptree -> NULL");	
		return;
	}
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree) {
	if (ptree == NULL)
		return false;
	else
		return (ptree->size == 0);
}

bool TreeIsFull(const Tree *ptree) {
	if (ptree == NULL)
		return false;
	else
		return (ptree->size == MAXLIMIT);
}

int TreeItemCount(const Tree *ptree) {
	if (ptree == NULL)
		return 0;
	else
		return (ptree->size);
}

bool AddItem(const Item *pi, Tree *ptree) {
	if (TreeIsFull(ptree)) return false;
	Trnode *new_node = MakeNode(pi);	
	if(AddNode(new_node, ptree)) {
		ptree->size++;
		return true;
	} else 
		return false;
} 

bool InTree(const Item *pi, const Tree *ptree) {
	int ret = 1;
	if (TreeIsEmpty(ptree) || pi == NULL)	
		return false;
	Pair *pair = SeekItem(pi, ptree);
	if (pair->child == NULL) 
		ret = 0;
	free(pair);
	return ret;
}


bool DeleteItem(const Item *pi, Tree *ptree) {
	Pair *pair = SeekItem(pi, ptree);
	if (pair->child == NULL) {
		free(pair);
		return false;
	}
	else if (pair->parent == NULL) 
		DeleteNode(&(ptree->root));		
	else {
		Trnode *node = pair->parent;
		if (pair->child == node->left)		
			DeleteNode(&(node->left));
		else
			DeleteNode(&(node->right));
	}
	free(pair);
	ptree->size--;
	return true;
}


void Traverse(const Tree *ptree, void(*pfun)(Item item)) {	
	if (TreeIsEmpty(ptree)) return;
	InOrder(ptree->root, (*pfun));	
}


void DeleteTree(Tree *ptree) {
	DeleteAllNode(ptree->root);
	ptree->size = 0;
}



/* static fanc */

static Trnode *MakeNode(const Item *pi) {
	Trnode *node = (Trnode *)malloc(sizeof(Trnode));	
	if (pi != NULL) {
		node->item = *pi;	
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

static bool ToLeft(const Item *i1, const Item *i2) {
	if (*i1 > *i2)	
		return true;
	else
		return false;
}


static bool ToRight(const Item *i1, const Item *i2) {
	if (*i1 < *i2)	
		return true;
	else
		return false;
}

static Pair *SeekItem(const Item *pi, const Tree *ptree) {
	Pair *pair = (Pair *)malloc(sizeof(Pair));
	pair->parent = NULL;
	pair->child  = NULL;
	if (TreeIsEmpty(ptree) || pi == NULL) {		
		return pair;
	}
	pair->child  = ptree->root;
	while (pair->child != NULL) {
		if (ToLeft( &(pair->child->item), pi)) {
			if (pair->child->left) { 
				pair->parent = pair->child;
				pair->child  = pair->child->left;
			}
			else 
				break;	
		}	
		else if (ToRight( &(pair->child->item), pi)) {
			if (pair->child->right) {
				pair->parent = pair->child;		
				pair->child  = pair->child->right;
			}
			else
				break;
		}	
		else 
			break;	
	}
	return pair;
}

static void DeleteNode(Trnode **ptr) {
	if ((*ptr)->left == NULL && (*ptr)->right == NULL) {
		free(*ptr);
		*ptr == NULL;	
		return;
	}		
	else if ( (*ptr)->left && (*ptr)->right == NULL) {
		Trnode *p = (*ptr)->left;
		free(*ptr);	
		*ptr = p;
		return;
	}
	else if ( (*ptr)->right && (*ptr)->left == NULL) {
		Trnode *p = (*ptr)->right;
		free(*ptr);	
		*ptr = p;
		return;
	}
	else {
		Trnode *pf = (*ptr)->left;	
		Trnode *pr = (*ptr)->right;
		free(*ptr);
		*ptr = pf; 
		Trnode *temp = *ptr;
		while (temp->right != NULL) {
			if (temp->right == NULL)
				break;
			else 
 			temp = temp->right;	
		}
		temp->right = pr;
		return;
	}
}

static bool AddNode(Trnode *new_node, Tree *ptree) {
	if (!ptree)  return false;
	if (TreeIsEmpty(ptree)) {
		ptree->root = new_node;
		return true;
	}
	Pair *pair = SeekItem( &(new_node->item), ptree);
	if (new_node->item < pair->child->item) {	
		pair->child->left = new_node;
	}
	else if (new_node->item > pair->child->item)
		pair->child->right = new_node;
	else {
		free(pair);
		return false;
	}
	free(pair);
	return true;
}



static void DeleteAllNode(Trnode *p) {
	if (p == NULL) 	
		return;
	free(p);
	DeleteAllNode(p->left);
	DeleteAllNode(p->right);
}


static void InOrder(Trnode *p, void(*pfun)(Item item)) {
	if (p == NULL) return;	
	InOrder(p->left, (*pfun));
	(*pfun)(p->item);
	InOrder(p->right, (*pfun));
}



