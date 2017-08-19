#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int leaves[MAX];
int visit[MAX];
typedef struct child_node* PtrToChildNode;
typedef PtrToChildNode child;
struct child_node
{
	int child_id;
	child next_brother;
};
typedef struct parent_node* parent;
typedef struct parent_node{
	child first_child;
}* Parent[MAX];
typedef struct family_tree_node* family;
struct family_tree_node
{
	Parent _parent;
	int member_num;
	int non_child_member_num;
};

child create_child();
void dfs_visit(int parent_id, PtrToChildNode _parent, int level);

family create_family()
{
	family fmy = (family)malloc(sizeof(struct family_tree_node));
	scanf("%d %d", &(fmy->member_num), &(fmy->non_child_member_num));
	int i;
	for(i = 0; i < fmy->non_child_member_num; i++){
		int id, child_num;
		scanf("%d %d", &id, &child_num);
		int j;
		for(j = 0; j < child_num; j++){
			if(j == 0){
				fmy->_parent[id] = (parent)malloc(sizeof(struct parent_node));
				fmy->_parent[id]->first_child = NULL;
			}
			child _child = create_child();
			_child->next_brother = fmy->_parent[id]->first_child;
			fmy->_parent[id]->first_child = _child;
		}
	}
	return fmy;
}

child create_child()
{
	int id;
	scanf("%d", &id);
	child _child = (PtrToChildNode)malloc(sizeof(struct child_node));
	_child->child_id = id;
	return _child;
}

void dfs(family fmy)
{
	memset(visit, 0, sizeof(visit));
	int i;
	for(i = 0; i < fmy->member_num; i++)
		if(visit[i] != 1){
			dfs_visit(i, fmy->_parent[i]->first_child, 1);
		}
}

void dfs_visit(int parent_id, PtrToChildNode _parent, int level)
{
	visit[parent_id] = 1;
	if(_parent == NULL){
		printf("%d\n", __LINE__);
		leaves[level]++;
	}else{
		PtrToChildNode _child = _parent->first_child;
		printf("%d\n", __LINE__);
		dfs_visit(_child->child_id, _child, level+1);
	}
}

int main(int argc, char const *argv[])
{
	family fmy = create_family();
	memset(leaves, 0, sizeof(leaves));
	dfs(fmy);
	int i;
	printf("%d\n", leaves[0]);
	for(i = 1; i < fmy->member_num - fmy->non_child_member_num; i++)
		printf(" %d\n", leaves[i]);
	return 0;
}