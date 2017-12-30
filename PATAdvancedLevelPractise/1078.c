#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100000
int isPrime(int n)
{
	if(n == 1) return 0;
	int i;
	for(i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int NextPrime(int N)
{
	if(isPrime(N))
		return N;
	while(1)
	{
		if(!isPrime(N))
			N++;
		else
			break;
	}
	return N;
}

int Hash(int key, int M, int hash[])
{
	int pos = key % M;
	if(!hash[pos])
	{
		hash[pos] = 1;
		return pos;
	}
	int CNum = 0; // 冲突次数
	int k = 0;
	while(k <= M / 2)
	{
		++CNum;
		if(CNum % 2){
			k++;
			pos = (pos + k * k) % M;
		}else{
			pos -= k * k;
			while(pos < 0)
				pos += M;
		}
		if(hash[pos] == 0){
			hash[pos] = 1;
			return pos;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &M, &N);
	M = NextPrime(M);
	int hash[M];
	memset(hash, 0, M * sizeof(int));

	int i, key;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &key);
		int pos = Hash(key, M, hash);
		if(pos == -1)
			printf("-");
		else
			printf("%d", pos);
		if(i != N - 1)
			printf(" ");
	}
	printf("\n");
	return 0;
}