#include <stdio.h>
#include <string.h>

int Graph[201][201], N, M, K;

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	int i;
	for(i = 0; i < N; i++)
		memset(Graph[i] + 1, 0, sizeof(int) * N);
	for(i = 0; i < M; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		Graph[v1][v2] = Graph[v2][v1] = 1;
	}

	scanf("%d", &K);
	int Visit[N];
	for(i = 0; i < K; i++)
	{
		int Q, j, S;
		
		scanf("%d %d", &Q, &S);
		int pre = S;
		int flag = 1;

		memset(Visit, 0, sizeof(int) * N);
		for(j = 1; j < Q; j++)
		{
			int adj;
			scanf("%d", &adj);
			if(Visit[adj] == 1)
				flag = 0;
			if(!Graph[pre][adj])
				flag = 0;
			else if(!Visit[adj])
				Visit[adj] = 1;

			pre = adj;
		}
		if(pre != S) flag = 0; // 起始点不等于终点
		if(Q != N + 1) flag = 0; 

		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}