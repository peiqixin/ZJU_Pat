#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pat_node* ptr_pat_node;
struct pat_node
{
	char registration_number[14];
	int location_number;
	int score;
	int local_rank;
	// 用来保存localrank
	ptr_pat_node local_next;
	// 用于总排名
	ptr_pat_node final_next;
};

typedef struct adj_pat_node* ptr_adj_pat_node;
struct adj_pat_node
{
	ptr_pat_node first_pat_node;
};

typedef struct bucket_node* bucket_rank;
struct bucket_node
{
	ptr_adj_pat_node final_rank[101];
	ptr_adj_pat_node local_rank[101];
};

void insert(bucket_rank bucket, ptr_pat_node new_node)
{
	// insert into local rank bucket
	ptr_pat_node ptr = bucket->local_rank[new_node->location_number - 1]->first_pat_node;
	ptr_pat_node pre = NULL;
	int count_rank = 1;
	while(ptr && ptr->score >= new_node->score){
		pre = ptr;
		ptr = ptr->local_next;
		count_rank++;
	}
	// 如果前结点为空，两种情况
	// 1.链表头为空，则本地插入结束
	if(pre == NULL){
		bucket->local_rank[new_node->location_number - 1]->first_pat_node = new_node;
		new_node->local_rank = 1;
	}else{
		// 2.新插入的结点成绩大于头结点的成绩
		pre->local_next = new_node;
	}
	// 如果链表头不为空，new_node本地排名更新
	if(pre != NULL){
		if(new_node->score == pre->score){
			new_node->local_rank = pre->local_rank;
		}else{
			new_node->local_rank = count_rank;
		}	
	}
	// printf("%s local rank is : %d\n", new_node->registration_number, new_node->local_rank);
	// 更新new_node 后面所有结点的本地排名，直接加1
	new_node->local_next = ptr;
	while(ptr){
		ptr->local_rank = ptr->local_rank + 1;
		ptr = ptr->local_next;
	}
	
	// insert into final rank bucket
	// 用分数作为hash函数，映射到桶中，直接插在分数槽的最后一个位置
	ptr = bucket->final_rank[new_node->score]->first_pat_node;
	pre = NULL;
	while(ptr && (strcmp(ptr->registration_number, new_node->registration_number) <= 0)){
		pre = ptr;
		ptr = ptr->final_next;
	}
	if(pre == NULL){
		bucket->final_rank[new_node->score]->first_pat_node = new_node;
	}else{
		pre->final_next = new_node;
	}
	new_node->final_next = ptr;
}
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, j;
	bucket_rank bucket = (struct bucket_node*)malloc(sizeof(struct bucket_node));
	for(i = 0; i < 101; i++){
		bucket->final_rank[i] = (ptr_adj_pat_node)malloc(sizeof(struct adj_pat_node));
		bucket->final_rank[i]->first_pat_node = NULL;
		bucket->local_rank[i] = (ptr_adj_pat_node)malloc(sizeof(struct adj_pat_node));
		bucket->local_rank[i]->first_pat_node = NULL;
	}
	ptr_pat_node new_node;
	int stu_count = 0;
	for(i = 0; i < N; i++){
		int K;
		scanf("%d", &K);
		stu_count += K;
		for(j = 0; j < K; j++){
			new_node = (ptr_pat_node)malloc(sizeof(struct pat_node));
			new_node->location_number = i + 1;
			scanf("%s %d", new_node->registration_number, &new_node->score);
			insert(bucket, new_node);
		}
	}
	ptr_pat_node ptr;
	int rank = 1;
	int count;
	printf("%d\n", stu_count);
	for(i = 100; i >= 0; i--){
		ptr = bucket->final_rank[i]->first_pat_node;
		if(ptr){
			count = 0;
			while(ptr){
				printf("%s %d %d %d\n", ptr->registration_number, rank, ptr->location_number, ptr->local_rank);
				count++;
				ptr = ptr->final_next;
			}
			rank = rank + count;
		}
	}
	return 0;
}