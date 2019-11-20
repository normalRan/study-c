#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

typedef int Item;

typedef struct trnode {
	Item item;
	struct trnode *left;
	struct trnode *right;
}Trnode;

typedef struct tree {
	Trnode *root; 
	int size;
}Tree;

#define MAXLIMIT 5

/* interface fanc */

/* operation : Initialize tree										*/
/* precondition : ptree -> tree										*/
/* post condition : Initialize ptree								*/
void InitializeTree(Tree *ptree);


/* operation : make sure whether tree is empty						*/
/* preconditon : ptree -> tree										*/
/* post condition : if empty return true else return false			*/
bool TreeIsEmpty(const Tree *ptree);

/* operation : make sure whether tree is full						*/
/* preconditon : ptree -> tree										*/
/* post condition :if empty return true else return false			*/
bool TreeIsFull(const Tree *ptree);


/* operation : count item											*/
/* preconditon : ptree -> tree										*/
/* post condition : return item number								*/
int TreeItemCount(const Tree *ptree);


/* operation : add item for tree									*/
/* preconditon : ptree -> tree										*/
/*               pi -> item                                         */
/* post condition : if success return true else return false		*/
bool AddItem(const Item *pi, Tree *ptree);

/* operation : search item in tree                                  */
/* preconditon : ptree -> tree                                      */
/*               pi -> item                                         */
/* post condition : if success return true else return false        */
bool InTree(const Item *pi, const Tree *ptree);


/* operation : delete item of tree                                  */
/* preconditon : ptree -> tree                                      */
/*               pi -> item                                         */
/* post condition : if success return true else return false        */
bool DeleteItem(const Item *pi, Tree *ptree);

/* operation : Traverse tree                                        */
/* preconditon : ptree -> tree                                      */
/*               pfun -> func                                       */
void Traverse(const Tree *ptree, void(*pfun)(Item item));


/* operation : delete tree                                          */
/* precondition : ptree -> tree                                     */
void DeleteTree(Tree *ptree);

#endif

