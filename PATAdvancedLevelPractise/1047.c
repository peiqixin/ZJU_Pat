#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CourseNode
{
	int stu_num;
	int stu_list[400];
};

char stus[40000][5];

int cmp(const void *a, const void *b)
{
	int x1 = *(int *)a;
	int x2 = *(int *)b;
	return strcmp(stus[x1], stus[x2]);
}

int main(int argc, char const *argv[])
{
	int N, K, C, course_index;
	scanf("%d %d", &N, &K);
	int i, j;
	struct CourseNode course_list[K];
	for(i = 0; i < K; i++)
		course_list[i].stu_num = 0;
	for(i = 0; i < N; i++){
		scanf("%s %d", stus[i], &C);
		for(j = 0; j < C; j++){
			scanf("%d", &course_index);
			course_index--;
			course_list[course_index].stu_list[course_list[course_index].stu_num] = i;
			course_list[course_index].stu_num++;
		}
	}
	
	for(i = 0; i < K; i++){
		printf("%d %d\n", i + 1, course_list[i].stu_num);
		qsort(course_list[i].stu_list, course_list[i].stu_num, sizeof(int), cmp);
		for(j = 0; j < course_list[i].stu_num; j++)
			printf("%s\n", stus[course_list[i].stu_list[j]]);
	}
	return 0;
}