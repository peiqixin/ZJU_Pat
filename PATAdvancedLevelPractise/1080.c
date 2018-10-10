#include <stdio.h>
#include <stdlib.h>

struct StudentNode
{
	int Ge, Gi, finalG, id, choices[5], rank;
}StuList[40000];

struct SchoolNode
{
	int size, stus[40000], quota, minRank;
}Schools[100];

int N, M, K;
int cmp(const void *a, const void *b)
{
	struct StudentNode *sta = (struct StudentNode *)a;
	struct StudentNode *stb = (struct StudentNode *)b;
	if(sta->finalG != stb->finalG)
		return stb->finalG - sta->finalG;
	else
		return stb->Ge - sta->Ge;
}
int cmp1(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &N, &M, &K);
	int i;
	for(i = 0; i < M; i++)
		scanf("%d", &Schools[i].quota);
	for(i = 0; i < N; i++)
	{
		scanf("%d %d", &StuList[i].Ge, &StuList[i].Gi);
		StuList[i].finalG = StuList[i].Ge + StuList[i].Gi;
		StuList[i].id = i;
		for(int j = 0; j < K; j++)
			scanf("%d", &StuList[i].choices[j]);
	}
	qsort(StuList, N, sizeof(struct StudentNode), cmp);

	StuList[i].rank = 1;
	for(int i = 1; i < N; i++)
		if(StuList[i].finalG == StuList[i - 1].finalG && StuList[i].Ge == StuList[i - 1].Ge)
			StuList[i].rank = StuList[i - 1].rank;
		else
			StuList[i].rank = StuList[i - 1].rank + 1;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < K; j++)
		{
			int schId = StuList[i].choices[j];
			if(Schools[schId].quota > 0)
			{
				Schools[schId].stus[Schools[schId].size++] = StuList[i].id;
				Schools[schId].quota--;  // 该学校配额减少一名
				Schools[schId].minRank = StuList[i].rank;
				break; //换下一个同学
			}
			else
			{
				// 最后一名被录取的学生id
				// int stuId = Schools[schId].stus[Schools[schId].size - 1];
				// 如果配额已满，并且最后一名被录取的学生成绩与当前学生排名相同，则必须录取该同学 不对，为什么？
				// if(StuList[stuId].finalG == StuList[i].finalG && StuList[stuId].Ge == StuList[i].Ge)
				if(StuList[i].rank == Schools[schId].minRank)
				{
					Schools[schId].stus[Schools[schId].size++] = StuList[i].id;
					Schools[schId].quota--;
					break;
				}
			}
		}
	}
	for(int i = 0; i < M; i++)
		if(Schools[i].size > 0)
		{
			qsort(Schools[i].stus, Schools[i].size, sizeof(int), cmp1);
			for(int j = 0; j < Schools[i].size - 1; j++)
				printf("%d ", Schools[i].stus[j]);
			printf("%d\n", Schools[i].stus[Schools[i].size - 1]);
		}else
			printf("\n");
	return 0;
}