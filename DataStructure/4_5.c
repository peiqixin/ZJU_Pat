// 04-树5 Root of AVL Tree
#include <stdio.h>
typedef struct TreeNode* Tree;
typedef int ElementType;
struct TreeNode{
	Tree Left;
	Tree Right;
	int Balance
	ElementType Element;
};
void BuildTree(Tree T);
void Insert(Tree T, ElementType V);
Tree NewNode(ElementType V);
int main(int argc, char const *argv[])
{
	Tree T;
	BuildTree(T);
	printf("%d\n", T->Right->Element);
	return 0;
}
void BuildTree(Tree T)
{
	int N;
	scanf("%d", &N);
	int V;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->Right = T->Left = NULL;

	while(N){
		scanf("%d", &V);
		Tree = Insert(T, V);
	}
}

void Insert(Tree T, ElementType V)
{
	Tree t, parent;
	parent = T;
	t = parent->Right;
	int insertFlag = 0;
	if(t){
		while(t){
			if(t->Element > V){
				parent = t;
				t = t->Left;
				insertFlag = 1;
			}else if(t->Element < V){
				parent = t;
				t = t->Right;
				insertFlag = 2;
			}else{
				return;
			}
		}
		if(!parent->Right && !parent->Left){
			Tree tmp = NewNode(V);
			if(insertFlag == 1){
				parent->Left = tmp;
			}else if(insertFlag == 2){
				parent->Right = tmp;
			}
		}
	}else{
		Tree tmp = NewNode(V);
		tmp->Balance = 0;
		T->Right = tmp;
	}
}

Tree NewNode(ElementType V)
{
	Tree T;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->Left = T->Right = NULL;
	T->Element = V;
	return T;
}