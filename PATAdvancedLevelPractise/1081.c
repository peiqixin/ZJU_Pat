#include <stdio.h>
#include <stdlib.h>
// long long int
long long int ralist[100][2];
int N;

void Init()
{
	scanf("%d", &N);
	int i;
	for(i = 0; i < N; i++)
		scanf("%lld/%lld", &ralist[i][0], &ralist[i][1]);
}

void Simplfy(long long int sum[])
{
	long long int a, b;
	a = sum[0];
	b = sum[1];
	if(a % b == 0){
		a /= b;
		if(b < 0){
			a = -a;
			b = -1;
		}else
			b = 1;
	}else if(b % a == 0){
		b /= a;
		if(a < 0){
			b = -b;
			a = -1;
		}else
			a = 1;
	}else{
		int i;
		for(i = 2; i < a && i < b; i++)
			while(a % i == 0 && b % i == 0){
				a /= i;
				b /= i;
			}
	}
	sum[0] = a;
	sum[1] = b;
}

void AddSum(long long int sum[], long long int ral[])
{
	long long int tmp1 = ral[1];
	long long int tmp2 = sum[1];
	sum[1] *= tmp1;
	sum[0] *= tmp1;
	ral[0] *= tmp2;
	ral[1] *= tmp2;
	sum[0] += ral[0];
	Simplfy(sum);
}

void Solve()
{
	long long int sum[2];
	sum[0] = ralist[0][0];
	sum[1] = ralist[0][1];
	int i;
	for(i = 1; i < N; i++)
		AddSum(sum, ralist[i]);
	Simplfy(sum);
	if(sum[0] == 0)
	{
		printf("0\n");
		return;
	}
	if(sum[0] % sum[1] == 0)
		printf("%lld\n", sum[0] / sum[1]);
	else if(sum[0] < sum[1])
		printf("%lld/%lld\n", sum[0], sum[1]);
	else
		printf("%lld %lld/%lld\n", sum[0] / sum[1], sum[0] - sum[0] / sum[1] * sum[1], sum[1]);
}


int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}