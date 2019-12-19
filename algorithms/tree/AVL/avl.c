#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static int Max(int a, int b);
static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K1);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
static Position MakeNode(ElementType X);

/* intetface */

AvlTree MakeEmpty(AvlTree T) {				
	if (T == NULL)	
		return;
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	free(T);
}

Position Find(ElementType X, AvlTree T) {
	Position tmp  = T;	
	while (tmp != NULL) {
		if (tmp->Element == X)	
			break;
		if (tmp->Element < X)
			tmp  = tmp->Left;
		else
			tmp  = tmp->Right;
	}
	
	return T;	
}

Position FindMin(AvlTree T) {
	Position tmp = T;
	while (tmp->Left != NULL) 
		tmp = tmp->Left;
	return tmp;
}

Position FindMax(AvlTree T) {
	Position tmp = T;
	while (tmp->Right != NULL)
		tmp = tmp->Right;
	return tmp;
}

AvlTree Insert(ElementType X, AvlTree T) {
	if (T == NULL) {	
		Position New = MakeNode(X);
		if (!New)
			error("Out of space !!!");
		else
			T = New;
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);	
		if (Height(T->Right) - Height(T->Left) == 2) 
			if (X > T->Right->Element) 
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	}
	/* Else X is in the tree we do nothing */		
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

AvlTree Delete(ElementType X, AvlTree T) {
	if (T == NULL) 
		return NULL;
	if (T->Element == X) {

	 	if (!T->Left && !T->Right) {
	 			free(T);
				return NULL;
		}	
		else if (T->Left && !T->Right) {
			Position tmp = T;
			T = T->Left;
			free(tmp);
		}	
		else if (T->Right && !T->Left) {
			Position tmp  = T;
			T = T->Right;
			free(tmp);
		}
		else {
			ElementType t = FindMin(T->Right)->Element;
			Delete(t, T);
			T->Element = t;
		}

	}	
	else if (X < T->Element ) {
		T->Left = Delete(X, T->Left);
		if (Height(T->Right) - Height(T->Left) == 2)	
			T = SingleRotateWithRight(T);
	}
	
	else if (X > T->Element) {
		T->Right = Delete(X, T->Right);	
		if (Height(T->Left) - Height(T->Right) == 2)
			T = SingleRotateWithLeft(T);
	}
	/* Else X is not in tree we do nothing */
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}


void Perorder(AvlTree T, void (*func)(Position P)) {
	if (T == NULL)
		return;
	func(T);
	Perorder(T->Left, func);
	Perorder(T->Right, func);
}

//AvlTree Delete(ElementType X, AvlTree T) {}

//ElementType Retrieve(Position P) {}

/* static */

static int Height(Position P) {
	if (P == NULL)		
		return 0;
	else
		return P->Height;
}

static int Max(int a, int b) {
	if (a > b)
		return a;
	else 
		return b;
}
	

static Position SingleRotateWithLeft(Position K2) {
	Position K1;				
	K1 = K2->Left;
	K2->Left  = K1->Right;
	K1->Right = K2;
	
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K2), Height(K1->Left)) + 1;

	return K1;
}


static Position SingleRotateWithRight(Position K1) {
	Position K2;	
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(Height(K1), Height(K2->Right)) + 1;

	return K2;
}

static Position DoubleRotateWithLeft(Position K3) {
	/* Rotate between K1 and K2 */
	K3->Left = SingleRotateWithRight(K3->Left);
	/* Rotate between K2 and K3 */
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K1) {
	/* Rotate between K2 and K3 */
	K1->Right = SingleRotateWithLeft(K1->Right);		
	/* Rotate between K1 and K2 */
	return SingleRotateWithRight(K1);
}

static Position MakeNode(ElementType X) {
	Position new = (Position)malloc(sizeof(struct AvlNode));
	new -> Element = X;
	new -> Left  = NULL;
	new -> Right = NULL;
	new -> Height = 0;
}





