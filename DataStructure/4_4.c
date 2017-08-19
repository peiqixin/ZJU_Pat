//04-树4 是否同一棵二叉搜索树 
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode* Tree;
struct TreeNode
{
	int v;
	Tree Left;
	Tree Right;
	int flag;
};
// 构造初始树
Tree MakeTree(int N);
// 插入
Tree Insert(Tree T, int V);
Tree NewNode(int V);
int Check(Tree T, int V);
int Judge(Tree T, int N);
// 清除树中的flag标记
void Reset(Tree T);
void FreeTree(Tree T);

int main(int argc, char const *argv[])
{
	int N, L, i;
	Tree T;

	scanf("%d", &N);
	while(N){
		scanf("%d", &L);
		T = MakeTree(N);
		for(i=0; i<L; ++i){
			if(Judge(T, N))
				printf("Yes\n");
			else
				printf("No\n");
			Reset(T);
		}
		FreeTree(T);
		scanf("%d", &N);
	}

	return 0;
}

Tree MakeTree(int N)
{
	int i, V;
	Tree T;
	scanf("%d", &V);
	T = NewNode(V);
	for(i=1; i<N; ++i){
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

Tree Insert(Tree T, int V)
{
	if(!T){
		return NewNode(V);
	}
	else{
		if(T->v > V)
			T->Left = Insert(T->Left, V);
		else if(T->v < V)
			T->Right = Insert(T->Right, V);
	}
	return T;
}

Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

int Check(Tree T, int V)
{
	// flag equals 1, 
	if(T->flag){
		if(V < T->v) return Check(T->Left, V);
		else if(V > T->v) return Check(T->Right, V);
		else return 0;
	}else{
		if(V == T->v){
			T->flag = 1;
			return 1;
		}
		else
			return 0;
	}
}

int Judge(Tree T, int N)
{
	int flag = 0;
	int i;
	int V;
	for(i=0; i<N; i++){
		scanf("%d", &V);
		if(!flag && !(Check(T, V))) flag = 1;
	}
	if(flag) 
		return 0;
	else
		return 1;
}

void Reset(Tree T)
{
	if(T->Left) Reset(T->Left);
	if(T->Right) Reset(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if(T->Left) FreeTree(T->Left);
	if(T->Right) FreeTree(T->Right);
	free(T);
}