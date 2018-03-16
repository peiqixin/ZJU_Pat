#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define BOY 1
#define GIRL 0
int N, M;
typedef struct ArcNode * Arc;
struct ArcNode
{
	int adjv;
	Arc nextArc;
};
typedef struct
{
	Arc firstArc;
	int gender;
} GList[10000];
typedef struct GraphNode * Graph;
struct GraphNode
{
	int vexnum;
	int arcnum;
	GList G;
};
Graph graph = NULL;

struct ResNode
{
	int first, second;
};

struct ResNode resList[10000];
int count;

void Insert(int v1, int v2)
{
	Arc newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->adjv = v2;
	newArc->nextArc = graph->G[v1].firstArc;
	graph->G[v1].firstArc = newArc;

	newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->adjv = v1;
	newArc->nextArc = graph->G[v2].firstArc;
	graph->G[v2].firstArc = newArc;
}

void Init()
{
	scanf("%d %d", &N, &M);
	graph = (Graph)malloc(sizeof(struct GraphNode));
	for(int i = 0; i < 10000; i++)
	{
		graph->G[i].firstArc = NULL;
		graph->G[i].gender = BOY;
	}
	for(int i = 0; i < M; i++)
	{
		int p1, p2;
		char v1[6], v2[6];
		scanf("%s %s", v1, v2);
		if(v1[0] == '-')
			graph->G[abs(atoi(v1))].gender = GIRL;
		if(v2[0] == '-')
			graph->G[abs(atoi(v2))].gender = GIRL;
		p1 = atoi(v1);
		p2 = atoi(v2);
		Insert(abs(p1), abs(p2));
	}
}

int cmp(const void *a, const void *b)
{
	struct ResNode *ra = (struct ResNode *)a;
	struct ResNode *rb = (struct ResNode *)b;
	if(ra->first != rb->first)
		return ra->first - rb->first;
	else
		return ra->second - rb->second;
}

void Query(int p1, int p2)
{
	count = 0;
	Arc arc1 = graph->G[p1].firstArc;
	while(arc1)
	{
		if(arc1->adjv == p2) goto next1;
		if(graph->G[p1].gender == graph->G[arc1->adjv].gender)
		{
			Arc arc2 = graph->G[arc1->adjv].firstArc;
			resList[count].first = arc1->adjv;
			while(arc2)
			{
				// 
				if(arc2->adjv == p2 || arc2->adjv == p1) goto next2;
				if(graph->G[p2].gender == graph->G[arc2->adjv].gender)
				{
					resList[count].second = arc2->adjv;
					Arc arc3 = graph->G[arc2->adjv].firstArc;
					while(arc3)
					{
						if(arc3->adjv == p2)
						{
							count++;
							resList[count].first = resList[count - 1].first;
							break;
						}
						arc3 = arc3->nextArc;
					}
				}
				next2:
					arc2 = arc2->nextArc;
			}
		}
		next1:
			arc1 = arc1->nextArc;
	}
	qsort(resList, count, sizeof(struct ResNode), cmp);
	printf("%d\n", count);
	for(int i = 0; i < count; i++)
		printf("%04d %04d\n", resList[i].first, resList[i].second);
}

int main(int argc, char const *argv[])
{
	Init();
	int K;
	scanf("%d", &K);

	for(int i = 0; i < K; i++)
	{
		int p1, p2;
		char v1[6], v2[6];
		scanf("%s %s", v1, v2);
		p1 = abs(atoi(v1));
		p2 = abs(atoi(v2));
		Query(p1, p2);
	}
	return 0;
}
