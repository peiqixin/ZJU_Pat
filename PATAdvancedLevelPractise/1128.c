#include <stdio.h>
#include <string.h>

int K, Seq[1000], Set[1000];

// 判断是否在同一对角线
void Judge(int N)
{
	int curRow, preRow = Seq[0], col = 1;
	for(; col < N; col++)
	{
		curRow = Seq[col];
		if(preRow + 1 == curRow || preRow - 1 == curRow)
		{
			printf("NO\n");
			return;
		}
		preRow = curRow;
	}
	printf("YES\n");
}

int main(int argc, char const *argv[])
{
	scanf("%d", &K);
	int i;
	for(i = 0; i < K; i++)
	{
		int N;
		scanf("%d", &N);

		memset(Set, 0, sizeof(int) * N);
		int j, sameRowFlag = 0;
		for(j = 0; j < N; j++)
		{
			scanf("%d", &Seq[j]);
			Seq[j]--;
			if(Set[Seq[j]] == 0)
				Set[Seq[j]] = 1;
			else
				sameRowFlag = 1;
		}
		if(!sameRowFlag)
			Judge(N);
		else
			printf("NO\n");
	}
	return 0;
}