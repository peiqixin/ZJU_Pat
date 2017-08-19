#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i;
	int flag[N];
	long long a, b, c;
	for(i = 0; i < N; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a + b > c)
			flag[i] = 1;
		else
			flag[i] = 0;
	}
	for(i = 0; i < N; i++){
		if(flag[i])
			printf("Case #%d: true\n", i+1);
		else
			printf("Case #%d: false\n", i+1);
	}
	return 0;
}