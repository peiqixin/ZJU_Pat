#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu_node* ptr_stu;
struct stu_node
{
	char id[7];
	char name[10];
	int score;
	ptr_stu next;
};
// insertion sort
void insert(ptr_stu stu_list, ptr_stu new_stu, int kind)
{
	ptr_stu pre = stu_list;
	ptr_stu ptr = pre->next;
	if(kind == 1){
		while(ptr && strcmp(ptr->id, new_stu->id) <= 0){
			pre = ptr;
			ptr = ptr->next;
		}
	}else if(kind == 2){
		while(ptr && strcmp(ptr->name, new_stu->name) < 0){
			pre = ptr;
			ptr = ptr->next;
		}
		while(ptr && strcmp(ptr->name, new_stu->name) == 0 && strcmp(ptr->id, new_stu->id) < 0){
			pre = ptr;
			ptr = ptr->next;
		}
	}else{
		while(ptr && ptr->score < new_stu->score){
			pre = ptr;
			ptr = ptr->next;
		}
		while(ptr && ptr->score == new_stu->score && strcmp(ptr->id, new_stu->id) < 0){
			pre = ptr;
			ptr = ptr->next;
		}
	}
	pre->next = new_stu;
	new_stu->next = ptr;
}

int main(int argc, char const *argv[])
{
	int N, kind;
	scanf("%d %d", &N, &kind);
	ptr_stu stu_list = (ptr_stu)malloc(sizeof(struct stu_node));
	stu_list->next = NULL;
	int i;
	ptr_stu new_stu;
	for (i = 0; i < N; ++i)
	{
		new_stu = (ptr_stu)malloc(sizeof(struct stu_node));
		scanf("%s %s %d", new_stu->id, new_stu->name, &new_stu->score);
		insert(stu_list, new_stu, kind);
	}
	ptr_stu ptr = stu_list->next;
	while(ptr){
		printf("%s %s %d\n", ptr->id, ptr->name, ptr->score);
		ptr = ptr->next;
	}
	return 0;
}