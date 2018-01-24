#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct PersonNode *person;
struct PersonNode
{
	char name[9];
	int height;
} Person[10000];

int N, K;

int cmp(const void *a, const void *b)
{
	person pa, pb;
	pa = (person)a;
	pb = (person)b;
	if(pa->height != pb->height)
		return pb->height - pa->height;
	return strcmp(pa->name, pb->name);
}

void Init()
{
	scanf("%d %d", &N, &K);
	int i;
	for(i = 0; i < N; i++)
		scanf("%s %d", Person[i].name, &Person[i].height);
	qsort(Person, N, sizeof(struct PersonNode), cmp);
}

void Print()
{
	int col, remains, i;
	col = N / K;
	remains = N % K;
	int index = 0;
	for(i = 0; i < K; i++)
	{
		if(remains > 0)
		{
			col++;
			remains--;
		}
		else
			remains--;
		int Stack[col];
		int count = 1;
		int j = col / 2;
		while(count <= col)
		{
			Stack[j] = index++;
			if(count % 2)
				j = j - count;
			else
				j = j + count;
			count++;
		}
		for(j = 0; j < col; j++)
		{
			printf("%s", Person[Stack[j]].name);
			if(j < col - 1)
				printf(" ");
		}
		printf("\n");
		if(remains >= 0)
			col--;
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Print();	
	return 0;
}