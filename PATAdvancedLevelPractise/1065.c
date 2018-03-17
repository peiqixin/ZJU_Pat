#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i;
	long long int A, B, C, sum;

	for(i = 0; i < N; i++)
	{
		int flag = 0;
		scanf("%lld %lld %lld", &A, &B, &C);
		sum = A + B;
		printf("Case #%d: ", i + 1);
		if(A > 0 && B > 0 && sum <= 0)
			flag = 1;
		else if(A < 0 && B < 0 && sum >= 0)
			flag = 0;
		else if(sum > C)
			flag = 1;
		if(flag)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}