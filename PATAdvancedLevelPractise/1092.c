#include <stdio.h>
#include <string.h>

char shop[1001], eva[1001];
int count_shop[128], count_eva[128], visit[128];

void Init()
{
	gets(shop);
	gets(eva);
	memset(count_shop, 0, sizeof(int) * 128);
	memset(count_eva, 0, sizeof(int) * 128);
	memset(visit, 0, sizeof(int) * 128);
}

void Solve()
{
	int i;
	for(i = 0; i < strlen(shop); i++)
		count_shop[(int)shop[i]]++;
	for(i = 0; i < strlen(eva); i++)
		count_eva[(int)eva[i]]++;
	int flag = 1, count = 0, index;
	for(i = 0; i < strlen(eva); i++){
		index = (int)eva[i];
		if(visit[index]) continue;
		if(count_eva[index] > count_shop[index]){
			flag = 0;
			count += (count_eva[index]  - count_shop[index]);
		}
		visit[index] = 1;
	}
	if(flag)
		printf("Yes %d\n", strlen(shop) - strlen(eva));
	else
		printf("No %d\n", count);
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}