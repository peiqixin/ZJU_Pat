#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StuNode
{
	char id[11];
	char name[11];
	int grade;
};

struct StuNode StuList[40000];
int N;
int minIntval, maxIntval;

int cmp(const void *a, const void *b)
{
	struct StuNode *stua, *stub;
	stua = (struct StuNode *) a;
	stub = (struct StuNode *) b;
	if(stua->grade != stub->grade)
		return stub->grade - stua->grade;
	return strcmp(stua->name, stub->name);
}

void Init()
{
	scanf("%d", &N);
	int i;
	for(i = 0; i < N; i++)
		scanf("%s %s %d", StuList[i].name, StuList[i].id, &StuList[i].grade);
	scanf("%d %d", &minIntval, &maxIntval);
}

void Sovle()
{
	qsort(StuList, N, sizeof(struct StuNode), cmp);
	int i, printFlg = 0;
	for(i = 0; i < N; i++){
		if(StuList[i].grade >= minIntval && StuList[i].grade <= maxIntval){
			printf("%s %s\n", StuList[i].name, StuList[i].id);
			printFlg = 1;
		}
	}
	if(printFlg == 0)
		printf("NONE\n");
}

int main(int argc, char const *argv[])
{
	Init();
	Sovle();
	return 0;
}
