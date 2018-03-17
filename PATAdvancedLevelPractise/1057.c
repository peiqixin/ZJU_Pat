#include <stdio.h>
#define BLOCK_MAX 317 //一共317块
#define BLOCK_NUM 316 //每块316
#define MAX 100010

// http://chenxaioxi.me/2018/02/19/patA_1057/
// 桶排序 分块排序
int b[BLOCK_MAX] = {0}, a[MAX]={0};

int N, Stack[MAX], top = 0;

void Pop()
{
	if(top < 1)
		printf("Invalid\n");
	else
	{
		a[Stack[top]]--;
		b[Stack[top] / BLOCK_NUM]--;
		printf("%d\n", Stack[top--]);
	}
}

void PeekMedian()
{
	if(top < 1)
		printf("Invalid\n");
	else
	{
		int i, j, k = (top + 1) / 2, sum = 0;
		for(i = 0; i <= BLOCK_MAX; i++)
		{
			if(sum + b[i] >= k) break;
			sum += b[i];
		}
		for(j = i * BLOCK_NUM; j < MAX; j++)
		{
			sum += a[j];
			if(sum >= k) break;
		}
		printf("%d\n", j);
	}
}

void Solve()
{
	char struction[11];
	int i;
	for(i = 0; i < N; i++)
	{
		scanf("%s", struction);
		if(struction[1] == 'o')
			Pop();
		else if(struction[1] == 'e')
			PeekMedian();
		else
		{
			int num;
			scanf("%d", &num);
			Stack[++top] = num;
			a[num]++;
			b[num / BLOCK_NUM]++;
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	Solve();
	return 0;
}
