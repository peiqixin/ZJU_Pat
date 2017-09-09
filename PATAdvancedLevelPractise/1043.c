#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode *PtrToBTNode;
struct BTNode
{
	PtrToBTNode left;
	PtrToBTNode right;
	int data;
};
typedef PtrToBTNode BTree;
int index;

PtrToBTNode insert(PtrToBTNode tree, int num)
{
	if(tree == NULL){
		tree = (PtrToBTNode)malloc(sizeof(struct BTNode));
		tree->left = NULL;
		tree->right = NULL;
		tree->data = num;
	}else{
		if(tree->data > num)
			tree->left = insert(tree->left, num);
		else
			tree->right = insert(tree->right, num);
	}
	return tree;
}
// build binary search tree
BTree create(int num[], int N)
{
	BTree tree = NULL;
	int i;
	for(i = 0; i < N; i++)
		tree = insert(tree, num[i]);
	return tree;
}
// build bstree preorder to pre
void pre_order(BTree tree, int pre[])
{
	if(tree){
		pre[index++] = tree->data;
		pre_order(tree->left, pre);
		pre_order(tree->right, pre);
	}
}

void mirror_pre_order(BTree tree, int mirror[])
{
	if(tree){
		mirror[index++] = tree->data;
		mirror_pre_order(tree->right, mirror);
		mirror_pre_order(tree->left, mirror);
	}
}

void post_order(BTree tree, int post[])
{
	if(tree){
		post_order(tree->left, post);
		post_order(tree->right, post);
		post[index++] = tree->data;
	}
}

void post_mirror(BTree tree, int mirror[])
{
	if(tree){
		post_mirror(tree->right, mirror);
		post_mirror(tree->left, mirror);
		mirror[index++] = tree->data;
	}
}

int is_same(int pre[], int num[], int N)
{
	int i;
	for(i = 0; i < N; i++)
		if(pre[i] != num[i])
			return 0;
	return 1;
}

void print(int num[], int N)
{
	printf("YES\n");
	int i = 0;
	printf("%d", num[i]);
	for(i++; i < N; i++)
		printf(" %d", num[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, num[N];
	for(i = 0; i < N; i++)
		scanf("%d", &num[i]);
	BTree binary_tree = create(num, N);

	int pre[N];
	index = 0;
	pre_order(binary_tree, pre);

	int mirror[N];
	index = 0;
	mirror_pre_order(binary_tree, mirror);

	if(is_same(pre, num, N)){
		index = 0;
		post_order(binary_tree, pre);
		print(pre, N);
	}else if(is_same(mirror, num, N)){
		index = 0;
		post_mirror(binary_tree, mirror);
		print(mirror, N);
	}else
		printf("NO\n");
	return 0;
}