#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode
{
	int Element;
	int Count;
};

int N, K, A[50000], top, Index[50000];
// 2017.3 PAT
void Init()
{
	scanf("%d %d", &N, &K);
	int i;
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	memset(Index, -1, sizeof(int) * N);
}

int cmp(const void *a, const void *b)
{
	struct StackNode* sa = (struct StackNode*)a;
	struct StackNode* sb = (struct StackNode*)b;
	return sa->Count - sb->Count;
}

void Swap(struct StackNode Stack[], int i)
{
	int ct, et;
	ct = Stack[i].Count;
	et = Stack[i].Element;
	Stack[i].Count = Stack[i + 1].Count;
	Stack[i].Element = Stack[i + 1].Element;
	Stack[i + 1].Count = ct;
	Stack[i + 1].Element = et;	
	Index[Stack[i + 1].Element] = i + 1;
	Index[Stack[i].Element] = i;
}

void Adjust(struct StackNode Stack[], int index)
{
	int i;
	for(i = index - 1; i >= 0; i--)
	{
		if(Stack[i].Count < Stack[i + 1].Count)
			Swap(Stack, i);
		else if(Stack[i].Count == Stack[i + 1].Count && Stack[i].Element > Stack[i + 1].Element)
			Swap(Stack, i);
		else
			break;
	}
}

void Push(struct StackNode Stack[], int ele)
{
	int index;
	if(Index[ele] == -1)
	{
		Stack[++top].Element = ele;
		Stack[top].Count = 1;
		Index[ele] = top;
		index = top;
	}
	else
	{
		Stack[Index[ele]].Count++;
		index = Index[ele];
	}
	Adjust(Stack, index);
}

int main(int argc, char const *argv[])
{
	Init();
	struct StackNode Stack[N];
	int i;
	top = -1;
	Push(Stack, A[0]);
	for(i = 1; i < N; i++)
	{
		printf("%d:", A[i]);
		int j;
		for(j = 0; j <= top && j < K; j++)
			printf(" %d", Stack[j].Element);
		printf("\n");
		Push(Stack, A[i]);
	}
	return 0;
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12

5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
*/