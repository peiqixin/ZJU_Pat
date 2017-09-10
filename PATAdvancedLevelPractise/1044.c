#include <stdio.h>
#include <stdlib.h>

typedef struct PNode *PtrToPNode;
struct PNode
{
	int start;
	int end;
	int sum;
	PtrToPNode next;
};
typedef struct ListNode *PtrToList;
struct ListNode
{
	int flag;
	PtrToPNode head;
	PtrToPNode tail;
};

int N, M;

void clear(PtrToList list)
{
	PtrToPNode ptr = list->head;
	PtrToPNode pre = ptr;
	while(ptr){
		ptr = pre->next;
		free(pre);
	}
	list->head = list->tail = NULL;
}

PtrToList solve(int diamonds[])
{
	PtrToList list = (PtrToList)malloc(sizeof(struct ListNode));
	list->head = list->tail = NULL;
	list->flag = 0;
	int start, end, sum;

	PtrToPNode new_node;
	for(start = 0; start < N; start++){
		sum = 0;
		for(end = start; end < N; end++){
			sum += diamonds[end];
			if(sum == M){
				new_node = (PtrToPNode)malloc(sizeof(struct PNode));
				new_node->start = start;
				new_node->end = end;
				new_node->sum = M;
				new_node->next = NULL;
				if(list->flag == 1){
					list->tail->next = new_node;
					list->tail = new_node;
					continue;
				}else{
					list->flag = 1;
					clear(list);
					list->head = list->tail = new_node;
					continue;
				}
			}else if(sum > M){
				if(list->flag == 0){
					new_node = (PtrToPNode)malloc(sizeof(struct PNode));
					new_node->start = start;
					new_node->end = end;
					new_node->sum = sum;
					new_node->next = NULL;
					if(list->head == NULL){
						list->head = list->tail = new_node;
						continue;
					}else{
						if(list->head->sum > new_node->sum){
							clear(list);
							list->head = list->tail = new_node;
							continue;
						}else if(list->head->sum == new_node->sum){
							list->tail->next = new_node;
							list->tail = new_node;
							continue;
						}
					}
				}
			}
		}
	}
	return list;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	int i, diamonds[N];
	for(i = 0; i < N; i++)
		scanf("%d", &diamonds[i]);
	PtrToList list = solve(diamonds);
	PtrToPNode ptr = list->head;
	while(ptr){
		printf("%d-%d\n", ptr->start + 1, ptr->end + 1);
		ptr = ptr->next;
	}
	return 0;
}