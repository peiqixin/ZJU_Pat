#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct BookNode *Book;
struct BookNode
{
	char id[8];
	char title[81];
	char author[81];
	char keywords[60];
	char publisher[81];
	int year;
} BookList[10000];

int N, M;

int cmp(const void *a, const void *b)
{
	Book ba, bb;
	ba = (Book)a;
	bb = (Book)b;
	return strcmp(ba->id, bb->id);
}

void Init()
{
	scanf("%d\n", &N);
	int i;
	for(i = 0; i < N; i++)
	{
		gets(BookList[i].id);
		gets(BookList[i].title);
		gets(BookList[i].author);
		gets(BookList[i].keywords);
		gets(BookList[i].publisher);
		scanf("%d\n", &BookList[i].year);
	}
	qsort(BookList, N, sizeof(struct BookNode), cmp);
}

void SearchByTitle(char str[])
{
	int i, Count = 0;
	for(i = 0; i < N; i++)
		if(strcmp(BookList[i].title, str) == 0)
		{
			Count++;
			printf("%s\n", BookList[i].id);
		}
	if(Count == 0)
		printf("Not Found\n");
}

void SearchByAuthor(char str[])
{
	int i, Count = 0;
	for(i = 0; i < N; i++)
		if(strcmp(BookList[i].author, str) == 0)
		{
			Count++;
			printf("%s\n", BookList[i].id);
		}
	if(Count == 0)
		printf("Not Found\n");
}

void SearchByPublisher(char str[])
{
	int i, Count = 0;
	for(i = 0; i < N; i++)
		if(strcmp(BookList[i].publisher, str) == 0)
		{
			Count++;
			printf("%s\n", BookList[i].id);
		}
	if(Count == 0)
		printf("Not Found\n");
}

void SearchByYear(char str[])
{
	int SearchYear = 0, i;
	for(i = 0; i < 4; i++)
		SearchYear += (str[i] - '0') * pow(10, 3 - i);
	int Count = 0;
	for(i = 0; i < N; i++)
		if(BookList[i].year == SearchYear)
		{
			Count++;
			printf("%s\n", BookList[i].id);
		}
	if(Count == 0)
		printf("Not Found\n");
}

void SearchByKeyWord(char str[])
{
	int i, Count = 0;
	for(i = 0; i < N; i++)
		if(strstr(BookList[i].keywords, str))
		{
			Count++;
			printf("%s\n", BookList[i].id);
		}
	if(Count == 0)
		printf("Not Found\n");
}

void Solve()
{
	scanf("%d\n", &M);
	int i;
	char query[100];
	for(i = 0; i < M; i++)
	{
		gets(query);
		int searchFlag = query[0] - '0';
		printf("%s\n", query);
		switch(searchFlag)
		{
			case 1:
				SearchByTitle(query + 3);
				break;
			case 2:
				SearchByAuthor(query + 3);
				break;
			case 3:
				SearchByKeyWord(query + 3);
				break;
			case 4:
				SearchByPublisher(query + 3);
				break;
			case 5:
				SearchByYear(query + 3);
				break;
		}
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}