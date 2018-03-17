#include <stdio.h>
#include <math.h>
#include <string.h>
// http://chenxaioxi.me/2018/02/07/patA_1103/
int N, K, P;
int Stack[400], top = -1;
int Temp[400], tempTop = -1;
int maxSum = -1;
int vt[400];
void dfs(int num, int nown, int sum)
{
	if((K == tempTop + 1) && nown == N)
	{
		if(sum > maxSum)
		{
			maxSum = sum;
			memcpy(Stack, Temp, N * sizeof(int));
			top = tempTop;
		}
		return;
	}
	if(num == 0 || (tempTop == K - 1) || nown > N)
		return;
	Temp[++tempTop] = num;
	
	dfs(num, nown + vt[num], sum + num);
	tempTop--;
	dfs(num - 1, nown, sum);
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &N, &K, &P);
	int limit = (int)pow(N, 1.0 / P);
	for(int i = 1; i <= limit; i++)
		vt[i] = (int)pow(1.0 * i, P);
	
	dfs(limit, 0, 0);
	
	if(top == -1)
		printf("Impossible");
	else
	{
		printf("%d = %d^%d", N, Stack[0], P);
		for(int i = 1; i <= top; i++)
			printf(" + %d^%d", Stack[i], P);
	}
	printf("\n");
	return 0;
}
