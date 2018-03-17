#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int N;

int getExp(char *s, char re[])
{
	int length = strlen(s);
	int i, dotPos, firstPos;
	dotPos = firstPos = -1;
	int count = 0;
	for(i = 0; i < length; i++)
	{
		if(s[i] == '0' && firstPos == -1)
			continue;
		if(s[i]  == '.')
			dotPos = i;
		else
		{
			if(firstPos == -1)
				firstPos = i;
			if(count < N)
				re[count++] = s[i];
		}
	}
	while(count < N)
		re[count++] = '0';
	re[count] = '\0';
	if(firstPos == -1)
		return 0;
	if(dotPos == -1)
		dotPos = length;
	if(dotPos > firstPos)
		return (dotPos - firstPos);
	else
		return (dotPos + 1 - firstPos);
}

int main(int argc, char const *argv[])
{
	char sa[100], sb[100];
	scanf("%d %s %s", &N, sa, sb);
	char rea[N + 1], reb[N + 1];
	int epa = getExp(sa, rea);
	int epb = getExp(sb, reb);
	if(epa == epb && strcmp(rea, reb) == 0)
		printf("YES 0.%s*10^%d\n", rea, epa);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", rea, epa, reb, epb);
	return 0;
}