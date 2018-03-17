#include <stdio.h>
#include <stdlib.h>
#define MAXN 10005 
#define MAXM 105
// https://github.com/wlh320/shuaOJ/blob/master/PAT/advanced/1068.cpp
// dynamic programming
int dp[MAXN];
int flag[MAXN][MAXN];
int N, M;
int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	int coins[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &coins[i]);	
	qsort(coins, N, sizeof(int), cmp);
	for(int i = 0; i < N; i++)
		for(int j = M; j >= coins[i]; --j)
			if(dp[j] <= dp[j - coins[i]] + coins[i])
			{
				flag[i][j] = 1;
				dp[j] = dp[j - coins[i]] + coins[i];
			}
	int first = 1;
	if(dp[M] != M)
		printf("No Solution\n");
	else
	{
		while(M > 0)
		{
			if(flag[N][M])
			{
				if(!first)
					printf(" ");
				printf("%d", coins[N]);
				first = 0;
				M -= coins[N];
			}
			N--;
		}
	}
	return 0;
}
