#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu_info *stu;
struct stu_info
{
	char name[5];
	stu next;
};

struct course_node
{
	stu stu_list;
};

int main(int argc, char const *argv[])
{
	int N, K;
	scanf("%d %d", &N, &K);
	int i, j, course_index, stu_num;

	struct course_node course_list[K + 1];
	
	stu student;
	for(i = 0; i < K; i++){
		scanf("%d %d", &course_index, &stu_num);
		if(stu_num == 0){
			course_list[course_index].stu_list = NULL;
		}
		for(j = 0; j < stu_num; j++){
			student = malloc(sizeof(struct stu_info));
			scanf("%s", student->name);
			if(j == 0){
				course_list[course_index].stu_list = student;
				student->next = NULL;
			}else{
				student->next = course_list[course_index].stu_list;
				course_list[course_index].stu_list = student;
			}
		}
	}
	struct stu_info query_list[N];
	int query_len = 0;
	char ch;
	while(1){
		scanf("%s", query_list[query_len++].name);
		if((ch = getchar()) == '\n')
			break;
	}

	int course_num;
	int stack[K];
	int top;
	
	for(i = 0; i < query_len; i++){
		// init
		course_num = 0;
		top = -1;
		// query
		for(j = 1; j <= K; j++){
			student = course_list[j].stu_list;
			while(student){
				if(strcmp(query_list[i].name, student->name) == 0){
					course_num++;
					stack[++top] = j;
					break;
				}
				student = student->next;
			}
		}
		// print
		int index;
		printf("%s %d", query_list[i].name, course_num);
		for(index = 0; index <= top; index++)
			printf(" %d", stack[index]);
		printf("\n");
	}
	return 0;
}