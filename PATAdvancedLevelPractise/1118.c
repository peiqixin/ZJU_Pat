#include <stdio.h>
#include <string.h>

int Set[10001];
int N, M, Max = 0;

int Find(int X)
{
	if(Set[X] < 0)
		return X;
	else
		return Set[X] = Find(Set[X]);
}

void Union(int root1, int root2)
{
	if(Set[root1] < Set[root2])
	{
		Set[root1] += Set[root2];
		Set[root2] = root1;
	}
	else
	{
		Set[root2] += Set[root1];
		Set[root1] = root2;
	}
}

void Init()
{
	int i, j;
	scanf("%d", &N);
	for(i = 1; i < 10001; i++)
		Set[i] = -1;
	for(i = 0; i < N; i++)
	{
		int K;
		scanf("%d", &K);
		int root = -1;
		for(j = 0; j < K; j++)
		{
			int bird;
			scanf("%d", &bird);
			Max = Max >= bird ? Max : bird;
			if(root == -1)
				root = bird;
			else
			{
				int root1 = Find(root);
				int root2 = Find(bird);
				Union(root1, root2);
			}
		}
	}

}

void Solve()
{
	int i, count = 0;
	for(i = 1; i <= Max; i++)
		if(Set[i] < 0)
			count++;
	printf("%d %d\n", count, Max);
	scanf("%d", &M);
	for(i = 0; i < M; i++)
	{
		int b1, b2;
		scanf("%d %d", &b1, &b2);
		if(Find(b1) == Find(b2))
			printf("Yes\n");
		else
			printf("No\n");
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}