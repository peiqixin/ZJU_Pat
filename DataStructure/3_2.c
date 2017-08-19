//03-树2 List Leaves
#include <stdio.h>
#define MAXSIZE 10
#define Null -1
typedef int Tree;
struct TreeNode
{
	int Left;
	int Right;
}T[MAXSIZE];

Tree BuildTree(struct TreeNode T[]);
void LevelOrder(struct TreeNode T[], Tree root);

int main(int argc, char const *argv[])
{
	Tree root;
	root = BuildTree(T);
	//printf("root = %d\n", root);
	LevelOrder(T, root);
	return 0;
}
Tree BuildTree(struct TreeNode T[])
{
	int N;
	Tree root;
	scanf("%d\n", &N);
	if(N){
		int i;
		int check[N];
		for (i = 0; i < N; ++i)
			check[i] = 0;
		char cl,cr;
		for (i = 0; i < N; ++i)
		{
			scanf("%c %c\n", &cl, &cr);
			if(cl != '-'){
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}else{
				T[i].Left = Null;
			}
			if(cr != '-'){
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}else{
				T[i].Right = Null;
			}
		}
		for (i = 0; i < N; ++i)
			if(!check[i]) break;
		root = i;
	}
	return root;
}
void LevelOrder(struct TreeNode T[], Tree root)
{
	if(root == Null){
		printf("tree is null\n");
		return;
	}
	int queue1[] = {0,0,0,0};
	int top1 = -1;
	queue1[++top1] = root;

	int queue2[] = {0,0,0,0};
	int top2;

	int i;
	int flag = 1;
	while(top1!=-1){
		i = 0;
		top2 = -1;
		while(i <= top1){
			if(T[queue1[i]].Left != Null){
				queue2[++top2] = T[queue1[i]].Left;
				//printf("T[queue1[i]].Left=%d\n", T[queue1[i]].Left);
			}
			if(T[queue1[i]].Right != Null){
				queue2[++top2] = T[queue1[i]].Right;
				//printf("T[queue1[i]].Right=%d\n", T[queue1[i]].Right);
			}
			if((T[queue1[i]].Left == Null) && (T[queue1[i]].Right == Null)){
				if(flag){
					printf("%d", queue1[i]);
					flag = 0;
				}
				else{
					printf(" ");
					printf("%d", queue1[i]);
				}
			}
			i++;
		}
		//
		i = 0;
		top1 = -1;
		while(i <= top2){
			queue1[++top1] = queue2[i];
			i++;
		}
	}
	printf("\n");
}
