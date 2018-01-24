#include <stdio.h>
#include <string.h>

int Post[30], In[30], Left[30], Right[30], N;

void Init()
{
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &In[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &Post[i]);
	memset(Left, -1, sizeof(int) * N);
	memset(Right, -1, sizeof(int) * N);
}

void BuildTree(int L, int R, int parent, int n)
{
	int root = Post[parent];
	int i;
	for(i = 0; i < n; i++)
		if(In[i + L] == root)
			break;
	int LeftLength = i;
	int RightLength = n - LeftLength - 1;
	if(LeftLength > 0)
	{
		Left[parent] = parent - RightLength - 1;
		if(LeftLength > 1)
			BuildTree(L, L + LeftLength - 1, Left[parent], LeftLength);
	}
	if(RightLength > 0)
	{
		Right[parent] = parent - 1;
		if(RightLength > 1)
			BuildTree(L + LeftLength + 1, R, Right[parent], RightLength);
	}
}

void LevelTranverse()
{
	int Level = 0;
	int Stack[N], top1 = -1;
	Stack[++top1] = N - 1;

	int TempStack[N], top2;
	printf("%d", Post[N - 1]);

	while(top1 >= 0)
	{
		int j;
		top2 = -1;
		if(Level % 2 == 0)
		{
			for(j = top1; j >= 0; j--)
			{
				int root = Stack[j];
				if(Left[root] != -1)
				{
					TempStack[++top2] = Left[root];
					printf(" %d", Post[TempStack[top2]]);
				}
				if(Right[root] != -1)
				{
					TempStack[++top2] = Right[root];
					printf(" %d", Post[TempStack[top2]]);
				}
			}
		}
		else
		{
			for(j = top1; j >= 0; j--)
			{
				int root = Stack[j];
				if(Right[root] != -1)
				{
					TempStack[++top2] = Right[root];
					printf(" %d", Post[TempStack[top2]]);
				}
				if(Left[root] != -1)
				{
					TempStack[++top2] = Left[root];
					printf(" %d", Post[TempStack[top2]]);
				}

			}
		}
		for(j = 0; j <= top2; j++)
			Stack[j] = TempStack[j];
		top1 = top2;
		Level++;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Init();
	BuildTree(0, N - 1, N - 1, N);
	LevelTranverse();
	return 0;
}