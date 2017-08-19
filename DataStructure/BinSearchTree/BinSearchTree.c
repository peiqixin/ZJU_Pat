#include "BinSearchTree"
#include <stdio.h>

Position Find(ElementType X, BinSearchTree BST)
{
	if(!BST){
		printf("BinSearchTree is null!\n");
		return -1;
	}
	while(BST){
		if(BST->Element > X){
			BST = BST->Right;
		}else if(BST->Element < X){
			BST = BST->Left;
		}else{
			return BST;
		}
	}
	printf("Element X is not exist!\n");
	return -1;
}

Position FindMin(ElementType X)
{
	if(!BST){
		printf("BinSearchTree is null!\n");
		return -1;
	}
	while(BST->Left){
		BST = BST->Left;
	}
	return BST;
}

Position FindMax(ElementType X)
{
	if(!BST){
		printf("BinSearchTree is null!\n");
		return -1;
	}
	while(BST->Right){
		BST = BST->Right;
	}
	return BST;
}

BinSearchTree Insert(ElementType X, BinSearchTree BST)
{
	if(!BST){
		BST = (BinSearchTree)malloc(sizeof(BTNode));
		BST->Element X;
		BST->Right = BST->Left = NULL;
	}else if(BST->Element > X){

	}
}
BinSearchTree Delete(ElementType X, BinSearchTree BST)
{

}