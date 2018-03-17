#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int Score[5];
int N, K, M;

struct StudentNode
{
	int id;
	int ps[5] = {-2,-2,-2,-2,-2};
	int total_score = 0;
	int showFlag = 0;
	int fullScoreNum = 0;
} List[MAX];

void Init()
{
	scanf("%d %d %d", &N, &K, &M);
	for(int i = 0; i < K; i++)
		scanf("%d", &Score[i]);

	int id, pid, score;
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &id, &pid, &score);
		id--;
		List[id].id = id + 1;
		if(List[id].ps[pid - 1] < score)
		{
			if(score > -1)
			{
				if(score == Score[pid - 1])
					List[id].fullScoreNum++;
				List[id].showFlag = 1;
				List[id].ps[pid - 1] = score;
			}
			else
				List[id].ps[pid - 1] = 0;
		}
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < K; j++)
			if(List[i].ps[j] > 0)
				List[i].total_score += List[i].ps[j];
}

int cmp(const void *a, const void *b)
{
	struct StudentNode *sta, *stb;
	sta = (struct StudentNode *)a;
	stb = (struct StudentNode *)b;
	if(stb->total_score != sta->total_score)
		return stb->total_score - sta->total_score;
	else{
		if(sta->fullScoreNum != stb->fullScoreNum)
			return stb->fullScoreNum - sta->fullScoreNum;
		else
			return sta->id - stb->id;
	}
}

void Print()
{
	int rank = 0, i;
	int preScore = -1, nowScore;
	int sameCount = 1;
	for(i = 0; i <  N; i++)
	{
		if(!List[i].showFlag)
			continue;
		nowScore = List[i].total_score;
		if(nowScore != preScore)
		{
			rank += sameCount;
			sameCount = 1;
			preScore = nowScore;
		} else
			sameCount++;
		
		printf("%d %05d %d", rank, List[i].id, List[i].total_score);
		int j;
		for(j = 0; j < K; j++)
			if(List[i].ps[j] != -2)
				printf(" %d", List[i].ps[j]);
			else
				printf(" -");
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	Init();
	qsort(List, N, sizeof(struct StudentNode), cmp);
	Print();
	return 0;
}
