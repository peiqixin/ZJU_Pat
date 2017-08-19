// 06-图3 六度空间
/*
	“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。
	这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，
	也就是说，最多通过五个人你就能够认识任何一个陌生人。”
	六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。
	然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，
	能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。

	假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

	输入格式:

	输入第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤10^4，表示人数）、边数M（<= N*33，表示社交关系数）。
	随后的MM行对应MM条边，
	每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到NN编号）。

	输出格式:

	对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。
	每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

	输入样例:

	10 9
	1 2
	2 3
	3 4
	4 5
	5 6
	6 7
	7 8
	8 9
	9 10
	输出样例:

	1: 70.00%
	2: 80.00%
	3: 90.00%
	4: 100.00%
	5: 100.00%
	6: 100.00%
	7: 100.00%
	8: 90.00%
	9: 80.00%
	10: 70.00%
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
	int AdjV;
	PtrToAdjVNode Next;
};

/* 顶点表头结点的定义 */
typedef struct VNode *PtrToVNode;
struct VNode
{
	PtrToAdjVNode FirstEdge;
};

typedef struct GNode *PtrToGNode;
struct GNode
{
	PtrToVNode *List;
	int Nv;
	int Ne;
};
typedef PtrToGNode LGrapgh;

LGrapgh CreateGraph(int Nv);
LGrapgh BuildGraph(int Nv, int Ne);
void InsertEdge(LGrapgh Graph, Edge E);
int SDS(LGrapgh Graph, int i);
void Init(int num[], int N);

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	LGrapgh Graph = BuildGraph(N, M);

	int i = 0;
	// PtrToAdjVNode Adj;
	// while(i < Graph->Nv){
	// 	printf("%d:", i);
	// 	Adj = Graph->List[i]->FirstEdge;
	// 	while(Adj){
	// 		printf("%d ", Adj->AdjV);
	// 		Adj = Adj->Next;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	while(i < Graph->Nv){
		int count = SDS(Graph, i);
		printf("%d: %.2f%%\n", i+1, ((double)(count)) / Graph->Nv * 100);
		i++;
	}
	// i = 9;
	// int count = SDS(Graph, i);
	// printf("%d: %.2f%%\n", i+1, ((double)(count)) / Graph->Nv * 100);
	return 0;
}

LGrapgh BuildGraph(int Nv, int Ne)
{
	LGrapgh Graph;
	Edge E;
	int i;
	Graph = CreateGraph(Nv);
	Graph->Ne = Ne;
	if(Graph->Ne != 0){
		E = malloc(sizeof(struct ENode));
		for(i = 0; i < Graph->Ne; i++){
			scanf("%d %d", &E->V1, &E->V2);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

LGrapgh CreateGraph(int Nv)
{
	LGrapgh Graph;
	Graph = malloc(sizeof(struct GNode));
	Graph->List = malloc(sizeof(struct VNode) * Nv);
	Graph->Nv = Nv;
	Graph->Ne = 0;
	int i = 0;
	while(i < Graph->Nv){
		PtrToVNode NewNode = malloc(sizeof(struct VNode));
		NewNode->FirstEdge = NULL;
		Graph->List[i] = NewNode;
		i++;
	}
	return Graph;
}

void InsertEdge(LGrapgh Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* 插入边 <V1, V2> */
	/* 为V2建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2 - 1;
	NewNode->Next = Graph->List[E->V1 - 1]->FirstEdge;
	Graph->List[E->V1 - 1]->FirstEdge = NewNode;

	/* 若是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1 - 1;
	NewNode->Next = Graph->List[E->V2 - 1]->FirstEdge;
	Graph->List[E->V2 - 1]->FirstEdge = NewNode;
}

int SDS(LGrapgh Graph, int index)
{
	int visit[Graph->Nv];
	Init(visit, Graph->Nv);

	int Queue[Graph->Nv];
	int top = -1;
	Queue[++top] = index;
	visit[index] = 1;

	int Stack[Graph->Nv];

	int rear;
	int x, level, count;
	level = 0;
	count = 1;
	PtrToAdjVNode Adj;
	while(top > -1){
		rear = 0;
		int STop = -1;
		while(rear <= top){
			x = Queue[rear];
			//printf("x=%d\n", x);
			Adj = Graph->List[x]->FirstEdge;
			while(Adj){
				// 被坑之处
				if(visit[Adj->AdjV] != 1){
					count++;
					STop++;
					Stack[STop] = Adj->AdjV;
					//printf(" %d ", Adj->AdjV);
					visit[Adj->AdjV] = 1;
				}
				Adj = Adj->Next;
			}
			rear++;
		}
		level++;
		//printf("level=%d\n", level);
		if(level == 6)
			break;
		top = -1;
		while(STop > -1 && top < STop){
			top++;
			Queue[top] = Stack[top];
			//printf("top=%d\n", top);
		}

	}
	return count;
}

void Init(int num[], int N)
{
	int i = 0;
	while(i < N){
		num[i] = 0;
		i++;
	}
}
