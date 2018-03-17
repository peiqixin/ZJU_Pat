#include <stdio.h>
#include <math.h>
// 注意在输入的时候，记录是第几级供应商，否则会超时
// 一个测试点未通过，应该是方法有问题，误打误撞拿了24分
#define MAX 100000
int N, Parent[MAX] = {-1}, Retails[MAX], level[MAX] = {0}, top = -1;
double p, r, Amount[MAX];
int main(int argc, char const *argv[])
{
	scanf("%d %lf %lf", &N, &p, &r);
	for(int i = 0; i < N; i++)
	{
		int M;
		scanf("%d", &M);
		for(int j = 0; j < M; j++)
		{
			int pos;
			scanf("%d", &pos);
			level[pos] = level[i] + 1;
			Parent[pos] = i;
		}
		if(M == 0)
		{
			level[i] = level[Parent[i]] + 1;
			double amount;
			scanf("%lf", &amount);
			Retails[++top] = i;
			Amount[i] = amount;
		}
	}
	double sales = 0;
	for(int i = 0; i <= top; i++)
		sales += pow(r * 0.01 + 1, level[Retails[i]]) * Amount[Retails[i]];
	printf("%0.1lf\n", sales * p);
	return 0;
}