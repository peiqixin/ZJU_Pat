#include <stdio.h>
#include <string.h>

int N, M, fa[201], L, gs[10001], c[201][10001];

void Init()
{
	int i;
	scanf("%d", &N);
	scanf("%d", &M);
	for(i = 1; i <= M; i++)
		scanf("%d", &fa[i]);
	scanf("%d", &L);
	for(i = 1; i <= L; i++)
		scanf("%d", &gs[i]);
}

int max(int a, int b)
{
	return a >= b ? a : b;
}

void LCS()
{
	int i, j;
	for(i = 1; i <= M; i++)
		c[i][0] = 0;
	for(j = 0; j <= L; j++)
		c[0][j] = 0;

	for(i = 1; i <= M; i++)
		for(j = 1; j <= L; j++)
			if(fa[i] == gs[j])
				c[i][j] = c[i][j-1] + 1;  // LCS 是 c[i-1][j-1] + 1,而此处可以重复
			else
				c[i][j] = max(c[i-1][j], c[i][j-1]);
}

int main(int argc, char const *argv[])
{
	Init();
	LCS();
	printf("%d\n", c[M][L]);
	return 0;
}