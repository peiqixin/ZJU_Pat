#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE_NUM 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2
typedef struct adj_node* ptr_adj_node;
struct adj_node
{
	int adj_v;
	ptr_adj_node next;
};
typedef struct vertex_node* ptr_vertex_node;
struct vertex_node
{
	ptr_adj_node first_edge;
	int color;
};
typedef struct graph_node* ptr_graph_node;
typedef ptr_graph_node graph;
struct graph_node
{
	ptr_vertex_node G[MAX_NODE_NUM];
	int vertex_num;
	int edge_num;
};

void dfs(graph _graph, int v);

void insert(graph _graph, int v1, int v2)
{
	ptr_adj_node new_node;
	new_node = (ptr_adj_node)malloc(sizeof(struct adj_node));
	new_node->next = _graph->G[v1]->first_edge;
	new_node->adj_v = v2;
	_graph->G[v1]->first_edge = new_node;

	new_node = (ptr_adj_node)malloc(sizeof(struct adj_node));
	new_node->next = _graph->G[v2]->first_edge;
	new_node->adj_v = v1;
	_graph->G[v2]->first_edge = new_node;
}
graph create_graph(void)
{
	int N;
	scanf("%d", &N);
	graph _graph = (ptr_graph_node)malloc(sizeof(struct graph_node));
	_graph->vertex_num = N;
	int i = 0;
	for(i = 0; i < _graph->vertex_num; i++){
		_graph->G[i] = (ptr_vertex_node)malloc(sizeof(struct vertex_node));
		_graph->G[i]->first_edge = NULL;
	}
	for(i = 0; i < _graph->vertex_num - 1; i++){
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		insert(_graph, v1 - 1, v2 - 1);
	}
	return _graph;
}
void initialize_single_source(graph _graph)
{
	int i;
	for(i = 0; i < _graph->vertex_num; i++)
		_graph->G[i]->color = WHITE;
}
int find_component_num(graph _graph)
{
	int i;
	int component_num = 0;
	initialize_single_source(_graph);
	for(i = 0; i < _graph->vertex_num; i++){
		if(_graph->G[i]->color == WHITE){
			dfs(_graph, i);
			component_num++;
		}
	}
	return component_num;
}
void dfs(graph _graph, int v)
{
	_graph->G[v]->color = GRAY;
	ptr_adj_node adj = _graph->G[v]->first_edge;
	while(adj){
		if(_graph->G[adj->adj_v]->color == WHITE)
			dfs(_graph, adj->adj_v);
		adj = adj->next;
	}
}
void dfs_find_max_depth(graph _graph,int v, int depth, int* max_depth, int stack[], int* top, int cur_root)
{
	_graph->G[v]->color = GRAY;
	if(depth > *max_depth){
		*max_depth = depth;
		*top = 0;
		stack[*top] = cur_root;
	}else if(depth == *max_depth){
		int flag = 0;
		if(stack[*top] == cur_root) flag = 1;
		if(!flag){
			*top = *top + 1;
			stack[*top] = cur_root;
		}
	}
	ptr_vertex_node ptr_vertex = _graph->G[v];
	ptr_adj_node ptr_adj = ptr_vertex->first_edge;
	while(ptr_adj){
		if(_graph->G[ptr_adj->adj_v]->color == WHITE)
			dfs_find_max_depth(_graph, ptr_adj->adj_v, depth + 1, max_depth, stack, top, cur_root);
		ptr_adj = ptr_adj->next;
	}
}
int main(int argc, char const *argv[])
{
	graph _graph = create_graph();
	int component_num = find_component_num(_graph);
	if(component_num > 1){
		printf("Error: %d components\n", component_num);
	}else{
		int stack[_graph->vertex_num];
		int i;
		int top = -1;
		int max_depth = 1;
		for(i = 0; i < _graph->vertex_num; i++){
			initialize_single_source(_graph);
			int cur_root = i + 1;
			dfs_find_max_depth(_graph, i, 1, &max_depth, stack, &top, cur_root);
		}
		for(i = 0; i <= top; i++)
			printf("%d\n", stack[i]);
	}
	return 0;
}