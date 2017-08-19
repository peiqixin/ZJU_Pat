#ifdef __BINSEARCHTREE_H__
#define __BINSEARCHTREE_H__
typedef struct BinTreeNode BTNode;
typedef BTNode* BinSearchTree;
typedef int ElementType;
typedef BinSearchTree Position;
struct BinTreeNode{
	ElementType Element;
	BinSearchTree Left;
	BinSearchTree Right;
};
// search element x, return x's position
Position Find(ElementType X, BinSearchTree BST);
// find min element
Position FindMin(ElementType X);
// find max element 
Position FindMax(ElementType X);
BinSearchTree Insert(ElementType X, BinSearchTree BST);
BinSearchTree Delete(ElementType X, BinSearchTree BST);
#endif