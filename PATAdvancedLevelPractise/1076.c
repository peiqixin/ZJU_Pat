#include <stdio.h>
#include <string.h>

#define MAX 1001
// 有向图  邻接矩阵 BFS

int N, L;
int Graph[MAX][MAX];
int visit[MAX];

void Init()
{
	scanf("%d %d", &N, &L);
	int i;
	for(i = 1; i <= N; i++)
	{
		int n, j;
		scanf("%d", &n);
		if(n <= 0) continue;
		for(j = 1; j <= n; j++)
		{
			int v;
			scanf("%d", &v);
			Graph[i][v] = 1;
		}
	}
}

void BFS(int v)
{
	memset(visit, 0, sizeof(int) * (N + 1));
	visit[v] = 1;
	int level = 0;
	int queue[N];
	int top, rear;
	top = rear = -1;
	queue[++top] = v;

	int count = 0; // potential number

	int last = v;
	int cur_last;
	while(rear < top)
	{
		if(level == L) break;

		int u, w;
		u = queue[++rear];

		for(w = 1; w <= N; w++)
		{
			if(Graph[w][u] == 1 && !visit[w]) // 如果 w 关注了 u
			{
				visit[w] = 1;
				count++;
				queue[++top] = w;
				cur_last = w;
			}
		}

		if(u == last)
		{
			level++;
			last = cur_last;
		}
	}
	// while(1)
	// {
	// 	int u, i, queue2[N], top2 = -1;
	// 	for(i = 0; i <= top; i++)
	// 	{
	// 		u = queue[i];
	// 		int w;
	// 		for(w = 1; w <= N; w++)
	// 		{
	// 			if(Graph[w][u] == 1 && !visit[w]) // 如果 w 关注了 u
	// 			{
	// 				visit[w] = 1;
	// 				count++;
	// 				queue2[++top2] = w;
	// 			}
	// 		}
	// 	}
	// 	level++;
	// 	if(level == L || top2 == -1) // 如果达到层数或者遍历完
	// 		break;
	// 	int j;
	// 	top = -1;
	// 	for(j = 0; j <= top2; j++)
	// 		queue[++top] = queue2[j];
	// }
	printf("%d\n", count);
}


int main(int argc, char const *argv[])
{
	Init();
	int n;
	scanf("%d", &n);
	int user[n];
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &user[i]);

	for(i = 0; i < n; i++)
		BFS(user[i]);
	return 0;
}