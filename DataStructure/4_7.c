// 04-树7 二叉搜索树的操作集
/*
	函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
	函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
	函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
	函数FindMin返回二叉搜索树BST中最小元结点的指针；
	函数FindMax返回二叉搜索树BST中最大元结点的指针。
	Input:
		10
		5 8 6 2 4 1 0 10 9 7
		5
		6 3 10 0 5
		5
		5 7 0 10 3
	OutPut:
		Preorder: 5 2 1 0 4 8 6 7 10 9
		6 is found
		3 is not found
		10 is found
		10 is the largest key
		0 is found
		0 is the smallest key
		5 is found
		Not Found
		Inorder: 1 2 4 6 8 9
*****/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X )
{
	if(!BST){
		BST = malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
		return BST;
	}else{
		if(X > BST->Data)
			BST->Right = Insert(BST->Right, X);
		else if(X < BST->Data)
			BST->Left = Insert(BST->Left, X);
	}
	return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
	Position tmp;
	if(!BST){
		printf("Not Found\n");
		return NULL;
	}
	else{
		if(BST->Data > X){
			BST->Left = Delete(BST->Left, X);
		}else if(BST->Data < X){
			BST->Right = Delete(BST->Right, X);
		}else{
			if(BST->Left && BST->Right){
				tmp = FindMin(BST->Right);
				BST->Data = tmp->Data;
				BST->Right = Delete(BST->Right, BST->Data);
			}else{
				tmp = BST;
				if(!BST->Left){
					BST = BST->Right;
				}else{
					BST = BST->Left;
				}
				free(tmp);
			}
		}
	}
	return BST;
}

Position Find( BinTree BST, ElementType X )
{
	if(!BST)
		return NULL;
	while(BST){
		if(BST->Data > X)
			BST = BST->Left;
		else if(BST->Data < X)
			BST = BST->Right;
		else
			break;
	}
	return BST;
}

Position FindMin( BinTree BST )
{
	if(!BST)
		return NULL;
	while(BST->Left)
		BST = BST->Left;
	return BST;
}

Position FindMax( BinTree BST )
{
	if(!BST)
		return NULL;
	while(BST->Right)
		BST = BST->Right;
	return BST;
}

void PreorderTraversal( BinTree BT )
{
	if(!BT)
		return;
	printf("%d ", BT->Data);
	if(BT->Left)
		PreorderTraversal(BT->Left);
	if(BT->Right)
		PreorderTraversal(BT->Right);
}

void InorderTraversal( BinTree BT )
{
	if(!BT)
		return;
	if(BT->Left)
		InorderTraversal(BT->Left);
	printf("%d ", BT->Data);
	if(BT->Right)
		InorderTraversal(BT->Right);
}