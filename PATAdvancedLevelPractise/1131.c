#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0xffffff

typedef struct ArcNode* Arc;
struct ArcNode
{
	int adjV;
	Arc nextArc;
};

typedef struct
{
	Arc firstArc;
} GList[10000];

typedef struct GraphNode* Graph;
struct GraphNode
{
	GList G;
	int arcnum, vexnum;
};

int minLength = INF, minTransfers = INF;
int minPath[10000], curPath[10000], minTop, curTop;
Graph graph = NULL;
int S, D, Visit[10000];

int Map[10000][10000];

void Insert(int v1, int v2)
{
	Arc newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->adjV = v1;
	newArc->nextArc = graph->G[v2].firstArc;
	graph->G[v2].firstArc = newArc;

	newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->adjV = v2;
	newArc->nextArc = graph->G[v1].firstArc;
	graph->G[v1].firstArc = newArc;
}

void Init()
{
	int M, i;
	scanf("%d", &M);
	graph = (Graph)malloc(sizeof(struct GraphNode));

	for(i = 0; i < M; i++)
	{
		int K, j, v1;
		scanf("%d %d", &K, &v1);
		for(j = 1; j < K; j++)
		{
			int v2;
			scanf("%d", &v2);
			Insert(v1, v2);
			Map[v1][v2] = Map[v2][v1] = i + 1;
			v1 = v2;
		}
	}
}

void CurToMin()
{
	memcpy(minPath, curPath, sizeof(int) * (curTop + 1));
	minTop = curTop;
}

// dfs, 回溯剪枝
void dfs(int stp, int curLength, int curTransfers)
{
	if(curLength > minLength)
		return;

	Visit[stp] = 1;
	curPath[++curTop] = stp;

	if(stp == D)
	{
		if(curLength < minLength || (curLength == minLength && curTransfers < minTransfers))
		{
			minLength = curLength;
			minTransfers = curTransfers;
			CurToMin();
		}
	}

	Arc arc = graph->G[stp].firstArc;
	while(arc)
	{
		if(!Visit[arc->adjV])
		{
			if(curTop > 1 && Map[curPath[curTop - 2]][curPath[curTop - 1]] != Map[curPath[curTop - 1]][curPath[curTop]])
				dfs(arc->adjV, curLength + 1, curTransfers + 1);
			else if(curTop > 0 && Map[curPath[curTop - 1]][curPath[curTop]] != Map[curPath[curTop]][arc->adjV])
				dfs(arc->adjV, curLength + 1, curTransfers + 1);
			else
				dfs(arc->adjV, curLength + 1, curTransfers);
		}
		arc = arc->nextArc;
	}
	Visit[stp] = 0;
	curTop--;
}

int main(int argc, char const *argv[])
{
	Init();
	int K, i;
	scanf("%d", &K);
	for(i = 0; i < K; i++)
	{
		memset(Visit, 0, sizeof(int) * 10000);
		curTop = minTop = -1;
		minLength = minTransfers = INF;

		scanf("%d %d", &S, &D);
		dfs(S, 0, 1);

		int v1 = 0, v2 = 1;
		printf("%d\n", minLength);
		while(v2 <= minTop)
		{
			int line;
			line = Map[minPath[v1]][minPath[v2]];
			while(++v2 <= minTop)
			{
				int nowLine = Map[minPath[v2 - 1]][minPath[v2]];
				if(nowLine != line)
					break;
			}
			printf("Take Line#%d from %04d to %04d.\n", line, minPath[v1], minPath[v2 - 1]);
			v1 = v2 - 1;
		}
	}
	return 0;
}