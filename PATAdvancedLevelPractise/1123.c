#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTreeNode * AVLTree;
struct AVLTreeNode
{
	AVLTree Left, Right;
	int Element;
};

int Max(int a, int b)
{
	return a > b ? a : b;
}

int GetHeight(AVLTree T)
{
	if(!T)
		return 0;
	else
		return Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
}

AVLTree SingleRightRotate(AVLTree A)
{
	AVLTree B;
	B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	return B;
}

AVLTree SingleLeftRotate(AVLTree A)
{
	AVLTree B;
	B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	return B;
}

AVLTree DoubleLeftRightRotate(AVLTree A)
{
	A->Left = SingleRightRotate(A->Left);
	return SingleLeftRotate(A);
}

AVLTree DoubleRightLeftRotate(AVLTree A)
{
	A->Right = SingleLeftRotate(A->Right);
	return SingleRightRotate(A);
}

AVLTree Insert(AVLTree T, int data)
{
	if(!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		T->Left = NULL;
		T->Right = NULL;
		T->Element = data;
	}
	else
	{
		if(T->Element > data)
		{
			T->Left = Insert(T->Left, data);
			if(GetHeight(T->Left) - GetHeight(T->Right) == 2)
			{
				if(T->Left->Element < data)
					T = DoubleLeftRightRotate(T);
				else
					T = SingleLeftRotate(T);
			}
		}
		else if(T->Element < data)
		{	
			T->Right = Insert(T->Right, data);
			if(GetHeight(T->Right) - GetHeight(T->Left) == 2)
			{
				if(T->Right->Element < data)
					T = SingleRightRotate(T);
				else
					T = DoubleRightLeftRotate(T);
			}
		}
	}
	return T;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i;
	AVLTree T = NULL;
	for(i = 0; i < N; i++)
	{
		int data;
		scanf("%d", &data);
		T = Insert(T, data);
	}
	AVLTree Queue[N];
	int top, rear;
	top = rear = -1;
	Queue[++top] = T;
	printf("%d", T->Element);
	int Count = 1, flag = 1;
	while(rear < top)
	{
		AVLTree tree = Queue[++rear];
		if(tree->Left)
		{
			printf(" %d", tree->Left->Element);
			Queue[++top] = tree->Left;
			Count++;
		}
		else
			if(Count < N) flag = 0;
		if(tree->Right)
		{
			printf(" %d", tree->Right->Element);
			Queue[++top] = tree->Right;
			Count++;
		}
		else
			if(Count < N) flag = 0;
	}

	if(flag) printf("\nYES\n");
	else printf("\nNO\n");
	return 0;
}