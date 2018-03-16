#include <stdio.h>
int dp[205][10005];
int fc[205], s[10005];
int N, L;

int max(int a, int b)
{
	return a > b ? a : b;
}
void LCS()
{
	for(int i = 0; i <= N; i++)
		dp[i][0] = 0;
	for(int i = 1; i <= L; i++)
		dp[0][i] = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= L; j++)
			if(fc[i] == s[j])
				dp[i][j] = dp[i][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

int main(void)
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &fc[i + 1]);
	scanf("%d", &L);
	for(int i = 0; i < L; i++)
		scanf("%d", &s[i] + 1);
	LCS();
	printf("%d", dp[N][L]);
	return 0;
}
