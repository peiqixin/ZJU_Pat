#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
找规律题：
个位：1-9，共有一个1
十位：如果十位数==1，则必定会有从后一位开始个1
*/
int N;
int Length[] = {0, 1, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};

int main(int argc, char const *argv[])
{
	char str[32];
	scanf("%s", str);
	int count = 0;
	int len = strlen(str);
	for(int i = 0; i < len - 1; i++)
	{
		if(str[i] == '1')
		{
			int tmp = 0;
			if(i < len - 1)
				tmp = atoi(str + i + 1) + 1;
			count += tmp;
		}
		else if(str[i] > '1')
		{
			count += pow(10, len - 1 - i);
		}
		count += Length[len - i] * (str[i] - '0');
	}
	if(str[strlen(str) - 1] > '0')
		count++;
	printf("%d\n", count);
	return 0;
}