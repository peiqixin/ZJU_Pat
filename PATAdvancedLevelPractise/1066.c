#include <stdio.h>
#include <stdlib.h>
typedef struct AVLTreeNode *PtrToAVLTree;
typedef PtrToAVLTree AVLTree;
struct AVLTreeNode
{
	int data;
	AVLTree left, right;
	int height;
};

int Max(int a, int b)
{
	return a > b ? a : b;
}

int GetHeight(AVLTree T)
{
	if(!T) return 0;
	if((!T->left) && (!T->right)) return 1;
	return Max(GetHeight(T->left), GetHeight(T->right)) + 1;
}
// 左单旋
AVLTree SingleLeftRotate(AVLTree A)
{
	AVLTree B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max(GetHeight(B->left), A->height) + 1;
	return B;
}

AVLTree SingleRightRotate(AVLTree A)
{
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max(GetHeight(B->right), A->height) + 1;
	return B;	
}

AVLTree DoubleLeftRightRotate(AVLTree A)
{
	A->left = SingleRightRotate(A->left);
	return SingleLeftRotate(A);
}

AVLTree DoubleRightLeftRotate(AVLTree A)
{
	A->right = SingleLeftRotate(A->right);
	return SingleRightRotate(A);
}

AVLTree Insert(AVLTree T, int x)
{
	if(!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
		T->height = 0;
	}else if(T->data > x){
		T->left = Insert(T->left, x);
		if(GetHeight(T->left) - GetHeight(T->right) == 2){
			if(x > T->left->data)
				T = DoubleLeftRightRotate(T);
			else
				T = SingleLeftRotate(T);
		}
	}else if(T->data < x){
		T->right = Insert(T->right, x);
		if(GetHeight(T->right) - GetHeight(T->left) == 2){
			// 
			if(x > T->right->data)
				T = SingleRightRotate(T);
			else
				T = DoubleRightLeftRotate(T);
		}
	}
	// forgot this.
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}

AVLTree BuildAVLTree()
{
	int N;
	scanf("%d", &N);
	AVLTree T = NULL;
	int data, i;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &data);
		T = Insert(T, data);
	}
	return T;
}

int main(int argc, char const *argv[])
{
	AVLTree T = BuildAVLTree();
	printf("%d\n", T->data);
	return 0;
}