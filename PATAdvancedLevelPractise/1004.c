#include <stdio.h>
#include <string.h>

int N, M;
int Parent[101], NonCount[101], Level[101], Child[101];

void Init()
{
	scanf("%d %d", &N, &M);
	memset(Child, 0, sizeof(int) * (N + 1));
	int i;
	for(i = 0; i < M; i++)
	{
		int parent, K;
		scanf("%d %d", &parent, &K);
		int j, child;
		for(j = 0; j < K; j++)
		{
			scanf("%d", &child);
			Parent[child] = parent;
			Child[parent] = 1;
		}
	}
}

void Solve()
{
	int i, parent;
	memset(Level, -1, sizeof(int) * (N + 1));
	Level[1] = 1;
	for(i = 2; i <= N; i++)
	{
		parent = Parent[i];
		int level = 0;
		while(parent != -1){
			level++;
			if(Level[parent] != -1)
			{
				level += Level[parent];
				break;
			}
			parent = Parent[parent];
		}
		Level[i] = level;
	}
	int MaxLevel = 0;
	memset(NonCount, 0, sizeof(int) * (N + 1));
	for(i = 1; i <= N; i++)
	{
		if(Child[i] == 0)
			NonCount[Level[i]]++;
		if(Level[i] > MaxLevel)
			MaxLevel = Level[i];
	}
	for(i = 1; i <= MaxLevel; i++)
	{
		printf("%d", NonCount[i]);
		if(i != MaxLevel)
			printf(" ");
		else
			printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}