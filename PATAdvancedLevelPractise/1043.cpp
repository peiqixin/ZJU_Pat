#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct BstNode* bst;
struct BstNode
{
	int data;
	bst left, right, parent;
};
bst Bst = NULL;
bst BuildBST(int pre[], int l, int n, bst Bst)
{
	int root = pre[l];
	if (n == 1)
	{
		bst newNode = (bst)malloc(sizeof(struct BstNode));
		newNode->data = root;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = Bst;
		return newNode;
	}
	int i;
	for (i = 0; i < n; i++)
		if (pre[i + l] > root)
			break;
	int leftL = i - 1;
	int rightL = n - leftL - 1;
	bst newNode = (bst)malloc(sizeof(struct BstNode));
	newNode->data = root;
	newNode->parent = Bst;
	if (leftL > 0)
		newNode->left = BuildBST(pre, l + 1, leftL, newNode);
	else
		newNode->left = NULL;
	if (rightL > 0)
		newNode->right = BuildBST(pre, l + leftL + 1, rightL, newNode);
	else
		newNode->right = NULL;
	return newNode;
}

bst findAns(int v1, bst tree)
{
	if (!tree) return NULL;
	while (tree)
	{
		if (v1 < tree->data)
			tree = tree->left;
		else if (v1 > tree->data)
			tree = tree->right;
		else
			return tree;
	}
	return NULL;
}

void tanverse(bst tree)
{
	if (!tree) return;
	printf("%d ", tree->data);
	tanverse(tree->left);
	tanverse(tree->right);
}

int main()
{
	int m, n;
	cin >> m >> n;
	int pre[10000], i;
	for (i = 0; i < n; i++)
		cin >> pre[i];

	Bst = BuildBST(pre, 0, n, Bst);
	for (i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		bst ver1 = findAns(v1, Bst);
		bst ver2 = findAns(v2, Bst);

		if (!ver1 && !ver2) printf("ERROR: %d and %d are not found.\n", v1, v2);
		else if (!ver1) printf("ERROR: %d is not found.\n", v1);
		else if (!ver2) printf("ERROR: %d is not found.\n", v2);
		else
		{
			bst newB = Bst;
			while (1)
			{
				if (newB->data > v1 && newB->data > v2)
					newB = newB->left;
				else if (newB->data < v1 && newB->data < v2)
					newB = newB->right;
				else
				{
					if (newB->data == v1)
					{
						printf("%d is an ancestor of %d.\n", v1, v2);
						break;
					}
					else if (newB->data == v2)
					{
						printf("%d is an ancestor of %d.\n", v2, v1);
						break;
					}
					else
					{
						printf("LCA of %d and %d is %d.\n", v1, v2, newB->data);
						break;
					}
				}
			}
		}
	}
	return 0;
}