#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// reference : https://github.com/lynnprosper/ZJU_PAT/blob/master/Advanced_Level/1107.%20Social%20Clusters%20(30)%5B%E5%B9%B6%E6%9F%A5%E9%9B%86%5D.cpp
#define MAX 1000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAX + 1];
int N, Hobby[MAX + 1];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

SetName Find(SetType S, ElementType X)
{
	if(S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}

void Union(SetType S, SetName root1, SetName root2)
{
	if(S[root1] < S[root2])
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
	else
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int i;
	SetType S;
	memset(Hobby + 1, -1, sizeof(int) * (MAX + 1));
	for(i = 1; i <= N; i++)
	{
		S[i] = -1;
		int M, j;
		scanf("%d:", &M);
		for(j = 0; j < M; j++)
		{
			int hobby;
			scanf("%d", &hobby);
			if(Hobby[hobby] == -1)
			{
				Hobby[hobby] = i;
			}
			else
			{
				int root1 = Find(S, i);
				int root2 = Find(S, Hobby[hobby]);
				Union(S, root1, root2);
			}
		}
	}
	qsort(S + 1, N, sizeof(int), cmp);
	int count = 0;
	for(i = 1; i <= N && S[i] < 0; i++)
		count++;
	printf("%d\n", count);
	for(i = 1; i <= count; i++)
	{
		printf("%d", -S[i]);
		if(i != count)
			printf(" ");
	}
	printf("\n");
	return 0;
}