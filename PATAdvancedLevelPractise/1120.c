#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int N, i;
	scanf("%d", &N);

	int Count[50], Stack[N], Top = -1;
	char str[5];
	memset(Count, 0, sizeof(int) * 50);
	for(i = 0; i < N; i++)
	{
		scanf("%s", str);
		int friendID = 0, j;
		for(j = 0; j < strlen(str); j++)
			friendID += str[j] - '0';
		if(Count[friendID] == 0)
		{
			Stack[++Top] = friendID;
			Count[friendID]++;
		}
	}
	printf("%d\n", Top + 1);
	qsort(Stack, Top + 1, sizeof(int), cmp);
	for(i = 0; i <= Top; i++)
	{
		printf("%d", Stack[i]);
		if(i != Top)
			printf(" ");
	}
	printf("\n");
	return 0;
}