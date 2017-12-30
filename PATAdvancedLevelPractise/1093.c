#include <stdio.h>
#include <string.h>

int Parent[100];
int LevelCount[10];
int Level[100];
int N, M;

void Init()
{
	scanf("%d %d", &N, &M);
	memset(Parent, -1, sizeof(int) * 100);
	memset(Level, -1, sizeof(int) * 100);
	memset(LevelCount, 0, sizeof(int) * 10);
	LevelCount[1] = 1;
	Level[1] = 1;
	int p, child, i;
	for(i = 0; i < M; i++){
		int n, j;
		scanf("%d %d", &p, &n);
		for(j = 0; j < n; j++){
			scanf("%d", &child);
			Parent[child] = p;
		}
	}
}

void Solve()
{
	int level, i, MaxLevel, MaxLevelCount;
	MaxLevel = MaxLevelCount = 1;
	for(i = 1; i <= N; i++){
		level = 0;
		int parent = Parent[i];
		while(parent != -1){
			level++;
			if(Level[parent] != -1){
				level += Level[parent];
				break;
			}
			parent = Parent[parent];
		}
		LevelCount[level]++;
		if(LevelCount[level] > MaxLevelCount){
			MaxLevelCount = LevelCount[level];
			MaxLevel = level;
		}
	}
	printf("%d %d\n", MaxLevelCount, MaxLevel);
}


int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}