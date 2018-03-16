#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int P, M, N;
struct StudentNode
{
	char id[21];
	int gp, gmid, gfinal, g;
};
struct StudentNode stuList[30001];
int count = 0;

int FindIndex(char name[])
{
	int i, index = -1;
	for(i = 0; i < count; i++)
		if(strcmp(stuList[i].id, name) == 0)
		{
			index = i;
			break;
		}
	return index;
}

int cmp(const void *a, const void *b)
{
	struct StudentNode * stua = (struct StudentNode *)a;
	struct StudentNode * stub= (struct StudentNode *)b;
	if(stua->g != stub->g)
		return stub->g - stua->g;
	else
		return strcmp(stua->id, stub->id);
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &P, &M, &N);
	int i;
	for(i = 0; i < P; i++)
	{
		char name[21];
		int score;
		scanf("%s %d", name, &score);
		if(score >= 200)
		{
			strcpy(stuList[count].id, name);
			stuList[count].gp = score;
			stuList[count].gmid = stuList[count].gfinal = -1;
			count++;
		}
	}
	for(i = 0; i < M; i++)
	{
		char name[21];
		int score;
		scanf("%s %d", name, &score);
		int index = FindIndex(name);
		if(index != -1)
			stuList[index].gmid = score;
	}

	for(i = 0; i < N; i++)
	{
		char name[21];
		int score;
		scanf("%s %d", name, &score);
		if(score < 60)
			continue;
		int index = FindIndex(name);
		if(index != -1)
			stuList[index].gfinal = score;
	}

	for(i = 0; i < count; i++)
	{
		if(stuList[i].gfinal < 60)
			stuList[i].g = -1;
		else if(stuList[i].gmid <= stuList[i].gfinal)
			stuList[i].g = stuList[i].gfinal;
		else
			stuList[i].g = (int)((double)stuList[i].gmid * 0.4 + (double)stuList[i].gfinal * 0.6 + 0.5);
	}
	qsort(stuList, count, sizeof(struct StudentNode), cmp);

	for(i = 0; i < count; i++)
	{
		if(stuList[i].g != -1)
			printf("%s %d %d %d %d\n", stuList[i].id, stuList[i].gp, stuList[i].gmid, stuList[i].gfinal, stuList[i].g);
	}
	return 0;
}