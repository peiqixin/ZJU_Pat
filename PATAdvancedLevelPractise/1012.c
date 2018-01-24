#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ID[6];
struct Student
{
	ID id;
	int c, m, e, a;
};

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	struct Student Stus[N];
	int i;
	for(i = 0; i < N; i++){
		scanf("%s %d %d %d", Stus[i].id, &Stus[i].c, &Stus[i].m, &Stus[i].e);
		Stus[i].a = (Stus[i].c + Stus[i].m + Stus[i].e) / 3;
	}
	char *s[M];

	for(i = 0; i < M; i++){
		s[i] = (char *)malloc(sizeof(char) * 6);
		scanf("%s", s[i]);
	}
	int Average[N], Clanguage[N], Math[N], English[N];

	int count, j;
	for(i = 0; i < N; i++){
		count = 0;
		for(j = 0; j < N; j++){
			if(i != j){
				if(Stus[i].a < Stus[j].a)
					count ++;
			}
		}
		Average[i] = count + 1;
		count = 0;
	}
	for(i = 0; i < N; i++){
		count = 0;
		for(j = 0; j < N; j++){
			if(i != j){
				if(Stus[i].c < Stus[j].c)
					count ++;
			}
		}
		Clanguage[i] = count + 1;
		count = 0;
	}
	for(i = 0; i < N; i++){
		count = 0;
		for(j = 0; j < N; j++){
			if(i != j){
				if(Stus[i].m < Stus[j].m)
					count ++;
			}
		}
		Math[i] = count + 1;
		count = 0;
	}
	for(i = 0; i < N; i++){
		count = 0;
		for(j = 0; j < N; j++){
			if(i != j){
				if(Stus[i].e < Stus[j].e)
					count ++;
			}
		}
		English[i] = count + 1;
		count = 0;
	}

	for(i = 0; i < M; i++){
		// 判断该学生是否存在
		int j;
		for(j = 0; j < N; j++){
			if(strcmp(s[i], Stus[j].id) == 0)
				break;
		}
		if(j == N){
			printf("N/A\n");
			continue;
		}
		int rank[4];
		rank[0] = Average[j];
		rank[1] = Clanguage[j];
		rank[2] = Math[j];
		rank[3] = English[j];
		int MinIndex = 0, k;
		for(k = 1; k < 4; k++){
			if(rank[MinIndex] > rank[k])
				MinIndex = k;
		}
		//printf("MinIndex = %d\n", MinIndex);
		switch(MinIndex){
			case 0:
				printf("%d A\n", Average[j]);
				break;
			case 1:
				printf("%d C\n", Clanguage[j]);
				break;
			case 2:
				printf("%d M\n", Math[j]);
				break;
			case 3:
				printf("%d E\n", English[j]);
				break;
			default:
				break;
		}
	}
	return 0;
}
