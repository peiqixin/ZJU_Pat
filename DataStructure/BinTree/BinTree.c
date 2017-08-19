#include "BinTree.h"
#include <stdlib.h>
Boolean IsEmpty(BinTree BT)
{
	if(BT->Left || BT->Right)
		return false;
	else
		return true;
}
BinTree CreateBinTree()
{
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TNode));
	BT->Left = NULL;
	BT->Right = NULL;
	return BT;
}
void PreOrderTranversal(BinTree BT)
{
	if(IsEmpty(BT))
		return;
	BinTree B;
	B = BT;
	Stack S;
	while(B || !IsEmpty(S)){
		while(B){
			printf("%d\t", BT->Data);
			Push(S,B);
			B = B->Left;
		}
		B = Pop(S);
		if(B->Right){
			Push(B->Right,S);
		}	
	}
	
}
void InOrderTranversal(BinTree BT)
{

}
void PostOrderTranversal(BinTree BT)
{

}
void LevelOrderTranversal(BinTree BT)
{

}
