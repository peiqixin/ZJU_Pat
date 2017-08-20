#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_NODE 30

typedef struct tree_node* ptr_tree_node;
typedef ptr_tree_node ptr_tree;
struct tree_node
{
	ptr_tree_node left;
	ptr_tree_node right;
	int data;
};
ptr_tree_node solve(int postL, int inL, int n, int post[], int in[])
{
	if(n == 0)
		return NULL;
	if(n == 1){
		ptr_tree_node new_node = (ptr_tree_node)malloc(sizeof(ptr_tree_node));
		new_node->data = post[postL];
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	int root;
	root = post[postL];
	ptr_tree_node new_node = (ptr_tree_node)malloc(sizeof(ptr_tree_node));
	new_node->data = root;
	int i;
	for(i = 0; i < n; i++)
		if(in[i + inL] == root)
			break;
	// 左子树结点个数
	int L = i;
	// 右子树结点个数
	int R = n - L - 1;
	new_node->left = solve(postL - R - 1, inL, L, post, in);
	new_node->right = solve(postL - 1, inL + L + 1, R, post, in);
	return new_node;
}

void level_tranversal(ptr_tree tree)
{
	if(tree){
		ptr_tree_node ptr = tree;
		ptr_tree_node queue[MAX_TREE_NODE];
		int front, rear;
		front = rear = -1;
		queue[++front] = ptr;
		printf("%d", ptr->data);
		while(front != rear){
			ptr = queue[++rear];
			if(ptr->left){
				queue[++front] = ptr->left;
				printf(" %d", ptr->left->data);
			}
			if(ptr->right){
				queue[++front] = ptr->right;
				printf(" %d", ptr->right->data);
			}
		}
		printf("\n");
	}else{
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	if(N <= 0) return 0;
	int post[N], in[N];
	int i;
	for(i = 0; i < N; i++)
		scanf("%d", &post[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &in[i]);
	ptr_tree tree = solve(N - 1, 0, N, post, in);
	level_tranversal(tree);
	return 0;
}