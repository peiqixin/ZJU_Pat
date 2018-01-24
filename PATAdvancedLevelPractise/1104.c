#include <stdio.h>
// https://github.com/lynnprosper/ZJU_PAT/blob/master/Advanced_Level/1104.%20Sum%20of%20Number%20Segments%20(20)%5B%E6%95%B0%E5%AD%A6%E9%80%BB%E8%BE%91%E9%A2%98%5D.cpp
// 想太复杂了，注意用double
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i;
	double sum = 0;
	for(i = 1; i <= N; i++)
	{
		double x;
		scanf("%lf", &x);
		sum += x * i * (N - i + 1);
	}
	printf("%.2f\n", sum);
	return 0;
}