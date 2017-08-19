#include <stdio.h>
#include <string.h>

#define MAX_VERTEXT_NUM 1000
int city[MAX_VERTEXT_NUM][MAX_VERTEXT_NUM];
int visit[MAX_VERTEXT_NUM];
int city_num, highway_num, checked_num;
void dfs_visit(int i);
int dfs()
{
	int i;
	int num = 0;
	for(i = 0; i < city_num; i++){
		if(visit[i] != 1){
			visit[i] = 1;
			dfs_visit(i);
			num++;
		}
	}
	return num;
}

void dfs_visit(int i)
{
	int j;
	for(j = 0; j < city_num; j++){
		if(visit[j] == 0 && city[i][j] == 1){
			visit[j] = 1;
			dfs_visit(j);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &city_num, &highway_num, &checked_num);
	memset(city, 0, sizeof(city));
	int i, c1, c2;
	for(i = 0; i < highway_num; i++){
		scanf("%d %d", &c1, &c2);
		city[c1 - 1][c2 - 1] = 1;
		city[c2 - 1][c1 - 1] = 1;
	}
	for(i = 0; i < checked_num; i++){
		// 将visit 数组清零
		memset(visit, 0, sizeof(visit));
		// 将i城市隔断
		int occupied;
		scanf("%d", &occupied);
		visit[occupied - 1] = 1;
		printf("%d\n", dfs(city) - 1);
	}
	return 0;
}