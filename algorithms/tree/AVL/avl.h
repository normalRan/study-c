#ifndef AVL_H_

typedef int ElementType;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
struct AvlNode {
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
void Perorder(AvlTree T, void (*func)(Position P));
AvlTree Delete(ElementType X, AvlTree T);
//ElementType Retrieve(Position P);


#endif /* AVL_H_ */
