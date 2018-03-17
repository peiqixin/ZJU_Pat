#include <stdio.h>
/*
https://github.com/WangGewu/PAT/blob/master/%E7%94%B2%E7%BA%A7/1074.c
*/
struct Node
{
	int data, next;
} List[100000];
int N, K;
int NewList[100000];
int main(int argc, char const *argv[])
{
	int start;
	scanf("%d %d %d", &start, &N, &K);
	for(int i = 0; i < N; i++)
	{
		int addr;
		scanf("%d", &addr);
		scanf("%d %d", &List[addr].data, &List[addr].next);
	}
	int count = 0;
	for(int i = start; i != -1; i = List[i].next)
		NewList[count++] = i;

	for(int i = 0; i < count / K; i++)
	{
		for(int j = 0; j < K / 2; j++)
		{
			int temp = NewList[i * K + j];
			NewList[i * K + j] = NewList[K * (i + 1) - j - 1];
			NewList[K * (i + 1) - j - 1] = temp;
		}
	}

	for(int i = 0; i < count - 1; i++)
		printf("%05d %d %05d\n", NewList[i], List[NewList[i]].data, NewList[i + 1]);
	printf("%05d %d -1\n", NewList[count - 1], List[NewList[count - 1]].data);
	return 0;
}