#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	int coins[N];
	int hash_coins[1001];
	memset(hash_coins, 0, sizeof(int) * 1001);
	int i;
	for(i = 0; i < N; i++){
		scanf("%d", &coins[i]);
		hash_coins[coins[i]]++;
	}
	int count = 0;
	for(i = 0; i < N; i++){
		if(coins[i] >= M)
			break;
		count++;
	}
	qsort(coins, N, sizeof(int), cmp);
	for(i = 0; i < count && coins[i] <= M / 2; i++){
		if(coins[i] != M - coins[i] && hash_coins[M - coins[i]] > 0){
			printf("%d %d\n", coins[i], M - coins[i]);
			return 0;
		}
		else if(coins[i] == M - coins[i] && hash_coins[coins[i]] > 1){
			printf("%d %d\n", coins[i], coins[i]);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}