#include <stdio.h>
#include <stdbool.h>
typedef struct TNode *Position;
typedef Position BinTree;
typedef int ElementType;
struct Tnode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
bool IsEmpty(BinTree BT);
BinTree CreateBinTree();
void PreOrderTranversal(BinTree BT);
void InOrderTranversal(BinTree BT);
void PostOrderTranversal(BinTree BT);
void LevelOrderTranversal(BinTree BT);
