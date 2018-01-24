#include <stdio.h>
#include <math.h>
#include <string.h>

int N;
double P, r;
int Parent[100000], Retails[100000], Count;

void Init()
{
	scanf("%d %lf %lf", &N, &P, &r);
	int i;
	Count = 0;
	for(i = 0; i < N; i++)
	{
		int M, j;
		scanf("%d", &M);
		if(M == 0)
		{
			Retails[Count++] = i;
			continue;
		}
		for(j = 0; j < M; j++)
		{
			int child;
			scanf("%d", &child);
			Parent[child] = i;
		}
	}
}

int GetLevel(int i, int Level[])
{
	int level = 0;
	if(Level[i] > -1)
		return Level[i];
	else
		level =  1 + GetLevel(Parent[i], Level);
	Level[i] = level;
	return Level[i];
}

void Solve()
{
	int Level[N];
	memset(Level, -1, sizeof(int) * N);
	Level[0] = 0;
	int MinLevel, MinNum, i;
	MinLevel = 0x7fffffff;
	MinNum = 1;
	for(i = 0; i < Count; i++)
	{
		int level = GetLevel(Retails[i], Level);
		if(level < MinLevel)
		{
			MinLevel = level;
			MinNum = 1;
		}
		else if(level == MinLevel)
			MinNum++;
	}
	double price = P * pow(1 + r / 100, MinLevel);
	printf("%.4lf %d\n", price, MinNum);
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}