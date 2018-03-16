#include <stdio.h>
#include <string.h>
int K, seq[1000];
int main(int argc, char const *argv[])
{
	scanf("%d", &K);
	int i;
	for(i = 0; i < K; i++)
	{
		int N;
		scanf("%d", &N);

		int flag = 0;
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &seq[j]);
			seq[j]--;
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < i; j++)
				if(seq[i] - seq[j] == i - j || seq[i] - seq[j] == j - i || seq[i] == seq[j])
				{
					flag = 1;
					goto print;
				}
		print:
			if(!flag)
				printf("YES\n");
			else
				printf("NO\n");
	}
	return 0;
}