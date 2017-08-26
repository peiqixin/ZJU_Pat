#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_node
{
	char name[11];
	char gender;
	char id[10];
	int grade;
};

int cmp(const void* a, const void* b)
{
	return (((struct stu_node*)a)->grade < ((struct stu_node*)b)->grade);
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	struct stu_node male_stu_list[N];
	struct stu_node female_stu_list[N];
	int male_len, female_len;
	male_len = female_len = 0;
	char name[11];
	char gender;
	char id[10];
	int grade;
	int i;
	for(i = 0; i < N; i++){
		scanf("%s %c %s %d", name, &gender, id, &grade);
		if(gender == 'M'){
			strcpy(male_stu_list[male_len].name, name);
			male_stu_list[male_len].gender = gender;
			strcpy(male_stu_list[male_len].id, id);
			male_stu_list[male_len].grade = grade;
			male_len++;
		}else{
			strcpy(female_stu_list[female_len].name, name);
			female_stu_list[female_len].gender = gender;
			strcpy(female_stu_list[female_len].id, id);
			female_stu_list[female_len].grade = grade;
			female_len++;
		}
	}
	if(male_len)
		qsort(male_stu_list, male_len, sizeof(struct stu_node), cmp);
	if(female_len)
		qsort(female_stu_list, female_len, sizeof(struct stu_node), cmp);
	if(female_len)
		printf("%s %s\n", female_stu_list[0].name, female_stu_list[0].id);
	else
		printf("Absent\n");
	if(male_len)
		printf("%s %s\n", male_stu_list[male_len - 1].name, male_stu_list[male_len - 1].id);
	else
		printf("Absent\n");
	if(male_len && female_len)
		printf("%d\n", female_stu_list[0].grade - male_stu_list[male_len - 1].grade);
	else
		printf("NA\n");
	return 0;
}