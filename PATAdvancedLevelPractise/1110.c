#include <stdio.h>
#include <stdlib.h>
int Left[20], Right[20], Root;
int N;
int Flag = 1, LastVisit;
void Init()
{
	scanf("%d\n", &N);
	int i;
	int rFlg[N];
	for(i = 0; i < N; i++)
	{
		char l[2], r[2]; // 注意不能用char..
		if(i < N - 1)
			scanf("%s %s\n", l, r);
		else
			scanf("%s %s", l, r);
		if(l[0] != '-')
		{
			int left = atoi(l);
			Left[i] = left;
			rFlg[left] = 1;
		}
		else
			Left[i] = -1;
		if(r[0] != '-')
		{
			int right = atoi(r);
			Right[i] = right;
			rFlg[right] = 1;
		}
		else
			Right[i] = -1;
	}
	for(i = 0; i < N; i++)
		if(rFlg[i] != 1)
		{
			Root = i;
			break;
		}
}

void BuildTree(int Tree[], int index, int root)
{
	// 如果当前的位置已经超过了N
	if(index > N)
	{ 
		Flag = 0;
		return;
	}
	Tree[index] = root;
	if(Left[root] != -1)
		BuildTree(Tree, index * 2, Left[root]);
	if(Right[root] != -1)
		BuildTree(Tree, index * 2 + 1, Right[root]);
}

void Judge()
{
	int Tree[N + 1];
	BuildTree(Tree, 1, Root);
	if(Flag == 1)
		printf("YES %d\n", Tree[N]);
	else
		printf("NO %d\n", Root);
}

int main(int argc, char const *argv[])
{
	Init();
	Judge();
	return 0;
}