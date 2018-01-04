#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char unit[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char decade[][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int N;
int FindIndex(char str[], int flg)
{
	if(flg == 1)
	{
		int i;
		for(i = 0; i < 13; i++)
			if(strncmp(str, unit[i], 3) == 0)
				return i;
		return -1;
	}
	else
	{
		int i;
		for(i = 1; i < 13; i++)
			if(strncmp(str, decade[i], 3) == 0)
				return i;
		return -1;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d\n", &N);
	int i;
	for(i = 0; i < N; i++)
	{
		char str[9];
		gets(str);
		if(str[0] >= '0' && str[0] <= '9')
		{
			int x = atoi(str);
			int index = x / 13;
			if(index != 0 && x % 13 != 0)
				printf("%s %s\n", decade[index], unit[x % 13]);
			else if(index != 0 && x % 13 == 0)
				printf("%s\n", decade[index]);
			else
				printf("%s\n", unit[x % 13]);
		}
		else
		{
			int len = strlen(str);
			if(len > 4)
			{
				int des = FindIndex(str, 2);
				int uni = FindIndex(str + 4, 1);
				printf("%d\n", des * 13 + uni);
			}
			else
			{
				int uni = FindIndex(str, 1);
				if(uni == -1)
				{
					uni = FindIndex(str, 2);
					printf("%d\n", uni * 13);
				}
				else
					printf("%d\n", uni);
			}
		}
	}
	return 0;
}