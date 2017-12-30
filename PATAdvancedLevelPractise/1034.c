#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, K, count;
typedef struct ArcNode *Arc;

int member, totalTime, head, maxTime;

struct ArcNode
{
	Arc nextArc;
	int ajdV;
	int weight;
};

typedef struct Vertex
{
	Arc FirstArc;
	char name[4];
} GList[2000];

typedef struct GraphNode *Graph;
struct GraphNode
{
	GList G;
	int arcnum;
	int vexnum;
};

int FindIndex(Graph graph, char str[])
{
	int i;
	for(i = 0; i < graph->vexnum; i++)
	{
		if(strcmp(graph->G[i].name, str) == 0)
			return i;
	}
	strcpy(graph->G[count++].name, str);
	return count - 1;
}

void Insert(Graph graph, int v1, int v2, int time)
{
	Arc newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->nextArc = graph->G[v1].FirstArc;
	newArc->weight = time;
	newArc->ajdV = v2;
	graph->G[v1].FirstArc = newArc;

	newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->nextArc = graph->G[v2].FirstArc;
	newArc->weight = time;
	newArc->ajdV = v1;
	graph->G[v2].FirstArc = newArc;
}

Graph Init()
{
	scanf("%d %d", &N, &K);
	Graph graph = (Graph)malloc(sizeof(struct GraphNode));
	count = 0;
	graph->vexnum = 1000;
	int i;
	for(i = 0; i < 1000; i++)
		graph->G[i].FirstArc = NULL;
	for(i = 0; i < N; i++)
	{
		char str1[4], str2[4];
		int time;
		scanf("%s %s %d", str1, str2, &time);
		int v1 = FindIndex(graph, str1);
		int v2 = FindIndex(graph, str2);
		Insert(graph, v1, v2, time);
	}
	graph->vexnum = count;
	return graph;
}

void DFS(Graph graph, int s, int visit[])
{
	visit[s] = 1;
	member++; // 成员数量加1
	int time = 0; // 改成员通话时间
	Arc arc = graph->G[s].FirstArc;
	while(arc)
	{
		time += arc->weight;
		if(!visit[arc->ajdV])
			DFS(graph, arc->ajdV, visit);
		totalTime += arc->weight;
		arc = arc->nextArc;
	}
	if(time > maxTime){
		maxTime = time;
		head = s;
	}
}

int main(int argc, char const *argv[])
{
	Graph graph = Init();
	int i, visit[graph->vexnum];
	memset(visit, 0, sizeof(int) * graph->vexnum);
	int Stack[1000], Count[1000], count = 0;
	for(i = 0; i < graph->vexnum; i++)
	{
		member = totalTime = head = maxTime = 0;
		if(!visit[i]) DFS(graph, i, visit);
		if(member > 2 && totalTime > 2 * K)
		{
			Count[count] = member;
			Stack[count++] = head;
		}
	}

	int tmp1, tmp2, p;
	for(p = 1; p < count; p++)
	{
		tmp1 = Stack[p];
		tmp2 = Count[p];
		for(i = p; i > 0 && strcmp(graph->G[tmp1].name, graph->G[Stack[i - 1]].name) <= 0; i--)
		{
			Stack[i] = Stack[i - 1];
			Count[i] = Count[i - 1];
		}
		Stack[i] = tmp1;
		Count[i] = tmp2;
	}
	printf("%d\n", count);
	for(i = 0; i < count; i++)
	{
		printf("%s %d\n", graph->G[Stack[i]].name, Count[i]);
	}
	return 0;
}
