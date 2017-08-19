/* 图的邻接表表示法 */
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};

/* 顶点表头结点的定义 */
typedef struct VNode{
	PtrToAdjVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum]; /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	

}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);

	scanf("%d", &Graph->Ne);
	if(Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0; i < Graph->Ne; i++){
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	for(V = 0; V < Graph->Nv; V++)
		scanf("%c", &(Graph->G[V].Data));
	return Graph;
}

