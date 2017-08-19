// AVLTree
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode* Position;
typedef Position AVLTree;
typedef int ElementType;

struct AVLNode
{
	AVLTree Left;
	AVLTree Right;
	int Height;
	ElementType Element;
};

AVLTree SingleLeftRotation ( AVLTree A );
AVLTree SingleRightRotation ( AVLTree A );
AVLTree DoubleLeftRightRotation ( AVLTree A );
AVLTree DoubleRightLeftRotation ( AVLTree A );
AVLTree Insert( AVLTree T, ElementType X );
int GetHeight(AVLTree T);
void PrintAVLTree(AVLTree T);

int Max ( int a, int b )
{
	return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int V;
	AVLTree T = NULL;
	while(N){
		scanf("%d", &V);
		T = Insert(T, V);
		N--;
	}
	//PrintAVLTree(T);
	printf("%d\n", T->Element);
	return 0;
}

AVLTree SingleLeftRotation ( AVLTree A )
{
	/* 注意：A必须有一个左子结点B */
	/* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */     
	AVLTree B;
	B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;

	return B;
}

AVLTree SingleRightRotation ( AVLTree A )
{
	/* 注意：A必须有一个右子结点B */
	/* 将A与B做右单旋，更新A与B的高度，返回新的根结点B */     
	AVLTree B;
	B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;

	return B;
}

AVLTree DoubleLeftRightRotation ( AVLTree A )
{
	/* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
	/* 将A、B与C做两次单旋，返回新的根结点C */

	/* 将B与C做右单旋，C被返回 */
	A->Left = SingleRightRotation(A->Left);
	/* 将A与C做左单旋，C被返回 */
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation ( AVLTree A )
{
	/* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
	/* 将A、B与C做两次单旋，返回新的根结点C */

	/* 将B与C做左单旋，C被返回 */
	A->Right = SingleLeftRotation(A->Right);
	/* 将A与C做右单旋，C被返回 */
	return SingleRightRotation(A);
}

AVLTree Insert( AVLTree T, ElementType X )
{
	if(!T){
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Left = T->Right = NULL;
		T->Element = X;
		T->Height = 0;
	}
	/* 插入左子树 */
	else if(X < T->Element){
		T->Left = Insert(T->Left, X);
		if(GetHeight(T->Left) - GetHeight(T->Right) == 2){
			/* */
			if(X < T->Left->Element){
				T = SingleLeftRotation(T);
			}
			/* */
			else{
				T = DoubleLeftRightRotation(T);
			}
		}
	}
	else if(X > T->Element){
		T->Right = Insert(T->Right, X);
		if(GetHeight(T->Left) - GetHeight(T->Right) == -2){
			if(X > T->Right->Element){
				T = SingleRightRotation(T);
			}
			/* */
			else{
				T = DoubleRightLeftRotation(T);
			}
		}
	}

	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

int GetHeight(AVLTree T)
{
	if(!T)
		return 0;
	else if((!T->Right) && (!T->Left))
		return 1;
	else
		return Max(1 + GetHeight(T->Right), 1 + GetHeight(T->Left));
}

//PreOrder
void PrintAVLTree(AVLTree T)
{
	if(T){
		printf("T->Height=%d\n", T->Height);
		if(T->Left){
			PrintAVLTree(T->Left);
		}
		if(T->Right){
			PrintAVLTree(T->Right);
		}
	}
	else{
		printf("AVLTree is NULL\n");
	}
}