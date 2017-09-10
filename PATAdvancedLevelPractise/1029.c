#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N, M, i, j;
	scanf("%d", &N);
	int S1[N];
	for(i = 0; i < N; i++)
		scanf("%d", &S1[i]);
	scanf("%d", &M);
	int S2[M];
	for(j = 0; j < M; j++)
		scanf("%d", &S2[j]);

	int median;
	if((N + M) % 2)
		median = (N + M) / 2;
	else
		median = (N + M) / 2 - 1;

	i = j = 0;
	while(i + j < median && i < N && j < M)
		if(S1[i] <= S2[j])
			i++;
		else
			j++;

	while(i + j < median)
		if(j == M)
			i++;
		else
			j++;

	if(j == M || (i < N && S1[i] <= S2[j]))
		printf("%d\n", S1[i]);
	else
		printf("%d\n", S2[j]);
	return 0;
}