#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLACK 0
#define RED 1

typedef struct RBTreeNode* RBTree;
struct RBTreeNode
{
	int data, color;
	RBTree left, right;
};
int Flag;

RBTree BuildTree(int A[], int r, int n)
{
	RBTree T = (RBTree)malloc(sizeof(struct RBTreeNode));
	T->data = abs(A[r]);
	if(A[r] >= 0)
		T->color = BLACK;
	else
		T->color = RED;

	int i, leftFlag = 0;
	//查找是否有左儿子
	if(r < n - 1 && abs(A[r]) > abs(A[r + 1]))
		leftFlag = 1;
	//查找是否有右儿子
	for(i = r + 1; i < n; i++)
		if(abs(A[r]) < abs(A[i]))
			break;

	if(leftFlag)
		T->left = BuildTree(A, r + 1, i);
	else
		T->left = NULL;

	if(i < n)
		T->right = BuildTree(A, i, n);
	else
		T->right = NULL;

	return T;
}

int GetBlackHeight(RBTree T)
{
	if(!T)
		return 0;
	else
	{
		if(T->color == BLACK)
			return 1 + GetBlackHeight(T->left);
		else
			return 0 + GetBlackHeight(T->left);
	}
}

void Judge(RBTree rbTree, int RootFlag)
{
	if(!rbTree)
		return;
	if(RootFlag && rbTree->color == RED)
	{
		Flag = 0;
		return;
	}

	if(rbTree->color == RED)
		if(!((rbTree->left && rbTree->right && rbTree->left->color == BLACK && rbTree->right->color == BLACK) || (rbTree->left == NULL && rbTree->right == NULL)))
		{
			Flag = 0;
			return;
		}
	if(GetBlackHeight(rbTree->left) != GetBlackHeight(rbTree->right))
	{
		Flag = 0;
		return;
	}
	Judge(rbTree->left, 0);
	Judge(rbTree->right, 0);
}

int main(int argc, char const *argv[])
{
	int K, i;
	scanf("%d", &K);
	for(i = 0; i < K; i++)
	{
		int N, j;
		scanf("%d", &N);
		int A[N];
		for(j = 0; j < N; j++)
			scanf("%d", &A[j]);
		RBTree rbTree = BuildTree(A, 0, N);
		Flag = 1;
		Judge(rbTree, 1);
		if(Flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
