#include <stdio.h>
#include <string.h>
#define INF 0x7fff
// 参考https://github.com/lynnprosper/ZJU_PAT/blob/master/Advanced_Level/1018.%20Public%20Bike%20Management%20(30).cpp
int CMax, N, Sp, M;
int Graph[501][501];
int Vertex[501];
int min_send = INF;
int min_back = INF;
int cur_send = 0;
int cur_back = 0;
int visit[501] = {0};
int min_len = INF;
int cur_len = 0;
int min_path[501], cur_path[501];
int min_Top = -1;
int cur_Top = -1;


void Init()
{
	scanf("%d %d %d %d", &CMax, &N, &Sp, &M);
	int i;
	for(i = 0; i <= 500; i++)
		memset(Graph[i], 0, sizeof(int) * 501);	
	for(i = 1; i <= N; i++)
		scanf("%d", &Vertex[i]);
	for(i = 0; i < M; i++)
	{
		int v1, v2, time;
		scanf("%d %d %d", &v1, &v2, &time);
		Graph[v1][v2] = time;
		Graph[v2][v1] = time;
	}
	CMax /= 2;
}

void CurToMin()
{
	int i;
	for(i = 0; i <= cur_Top; i++)
		min_path[i] = cur_path[i];
	min_Top = cur_Top;
}

void DFS(int v)
{
	visit[v] = 1;
	if(cur_len > min_len)
		return;
	if(v == Sp)
	{
		// printf("cur_len = %d, cur_back = %d, cur_send = %d\n", cur_len, cur_back, cur_send);
		if(cur_len < min_len)
		{
			CurToMin();
			min_len = cur_len;
			min_send = cur_send;
			min_back = cur_back;
		}
		else if(cur_len == min_len)
		{
			if(cur_send < min_send)
			{
				CurToMin();
				min_send = cur_send;
				min_back = cur_back;
			}
			else if(cur_send == min_send && cur_back < min_back)
			{
				CurToMin();
				min_back = cur_back;
			}
		}
		return;
	}

	int i;
	for(i = 1; i <= N; i++)
	{
		if(!visit[i] && Graph[v][i])
		{
			int last_send = cur_send;
			int last_back = cur_back;
			cur_len += Graph[v][i];
			cur_path[++cur_Top] = i;

			if(cur_back + Vertex[i] < CMax)
			{
				cur_send = cur_send + CMax - cur_back - Vertex[i];
				cur_back = 0;
			}
			else
				cur_back = cur_back + Vertex[i] - CMax;
			DFS(i);
			cur_Top--;
			visit[i] = 0;
			cur_len -= Graph[v][i];
			cur_send = last_send;
			cur_back = last_back;
		}
	}
}

int main(int argc, char const *argv[])
{
	Init();
	DFS(0);
	printf("%d 0", min_send);
	int i;
	for(i = 0; i <= min_Top; i++)
		printf("->%d", min_path[i]);
	printf(" %d\n", min_back);
	return 0;
}