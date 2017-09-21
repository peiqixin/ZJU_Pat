#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct person_node person;
struct person_node
{
	char name[9];
	int age;
	int net_worth;
};

int cmp(const void *a, const void *b)
{
	if(((person *)a)->net_worth != ((person *)b)->net_worth)
		return -(((person *)a)->net_worth - ((person *)b)->net_worth);
	else if(((person *)a)->age != ((person *)b)->age)
		return (((person*)a)->age - ((person *)b)->age);
	else
		return strcmp(((person *)a)->name, ((person *)b)->name);
}
int main(int argc, char const *argv[])
{
	int N, K;
	scanf("%d %d", &N, &K);
	int i;
	person person_list[N];
	for(i = 0; i < N; ++i)
		scanf("%s %d %d", person_list[i].name, &person_list[i].age, &person_list[i].net_worth);

	qsort(person_list, N, sizeof(struct person_node), cmp);
	int rank_num, minage, maxage;
	
	for(i = 0; i < K; ++i){
		scanf("%d %d %d", &rank_num, &minage, &maxage);
		int j;
		printf("Case #%d:\n", i + 1);
		int cur_rank = 0;
		for(j = 0; j < N; ++j){
			if(person_list[j].age >= minage && person_list[j].age <= maxage){
				printf("%s %d %d\n", person_list[j].name, person_list[j].age, person_list[j].net_worth);
				cur_rank++;
			}
			if(cur_rank == rank_num)
				break;
		}
		if(cur_rank == 0)
			printf("None\n");
	}
	return 0;
}