#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;
struct BSTNode
{
	int key;
	BSTree left, right;
};

int Height[1005] = {0};
int TreeHeight = 0;

void Insert(BSTree *bst, int data, int height)
{
	if(!(*bst))
	{
		BSTree newNode = (BSTree)malloc(sizeof(struct BSTNode));
		newNode->left = newNode->right = NULL;
		newNode->key = data;
		*bst = newNode;
		if(height > TreeHeight)
			TreeHeight = height;
		Height[height]++;
	}
	else if((*bst)->key >= data)
		Insert(&((*bst)->left), data, height + 1);
	else
		Insert(&((*bst)->right), data, height + 1);
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, data;
	BSTree BST = NULL;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &data);
		Insert(&BST, data, 0);
	}
	printf("%d + %d = %d\n", Height[TreeHeight], Height[TreeHeight - 1], Height[TreeHeight] + Height[TreeHeight - 1]);
	return 0;
}