#include <stdio.h>
#include <stdlib.h>

int Left[100], Right[100], Data[100], N, Tree[100];
int LeftSize[100], RightSize[100];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int GetSize(int i)
{
	if(Left[i] == -1)
		LeftSize[i] = 0;
	else
		LeftSize[i] = GetSize(Left[i]);
	if(Right[i] == -1)
		RightSize[i] = 0;
	else
		RightSize[i] = GetSize(Right[i]);
	return LeftSize[i] + RightSize[i] + 1;
}

void Init()
{
	scanf("%d", &N);
	int i;
	for(i = 0; i < N; i++)
		scanf("%d %d", &Left[i], &Right[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &Data[i]);
	qsort(Data, N, sizeof(int), cmp);
	GetSize(0);
}

void FindDataPosition(int p, int base)
{
	Tree[p] = Data[base + LeftSize[p]];
	if(Left[p] != -1)
		FindDataPosition(Left[p], base);
	if(Right[p] != -1)
		FindDataPosition(Right[p], LeftSize[p] + base + 1);
}

void LevelTranverse(int num[])
{
	int Queue[N], rear, top, NoSpace = 1;
	rear = top = -1;
	Queue[++top] = 0;
	while(rear < top)
	{
		int root = Queue[++rear];
		if(NoSpace){
			printf("%d", Tree[root]);
			NoSpace = 0;
		}else
			printf(" %d", Tree[root]);
		if(Left[root] != -1)
			Queue[++top] = Left[root];
		if(Right[root] != -1)
			Queue[++top] = Right[root];
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Init();
	FindDataPosition(0, 0);
	LevelTranverse(Tree);
	return 0;
}