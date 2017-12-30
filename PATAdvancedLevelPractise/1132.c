#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int N;

void Judge(char *s)
{
	int length = strlen(s);
	int i;
	long A, B;
	A = B = 0;
	for(i = 0; i < length / 2; i++)
		A += (s[i] - '0') * pow(10, length / 2 - i - 1);
	for(; i < length; i++)
		B += (s[i] - '0') * pow(10, length - i - 1);

	long num = atol(s);

	if(A * B == 0){
		printf("No\n");
		return;
	}
	
	if(num % (A * B) == 0)
		printf("Yes\n");
	else
		printf("No\n");
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int i;
	char s[32];
	for(i = 0; i < N; i++)
	{
		scanf("%s", s);
		Judge(s);
	}
	return 0;
}