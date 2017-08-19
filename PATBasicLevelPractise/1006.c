#include <stdio.h>
int main(int argc, char const *argv[])
{
	int Number;
	scanf("%d", &Number);
	int tmp = Number;
	int bn = tmp / 100;
	tmp = tmp - bn * 100;
	while(bn > 0){
		printf("B");
		bn--;
	}
	int sn = tmp / 10;
	tmp = tmp - sn * 10;
	while(sn > 0){
		printf("S");
		sn--;
	}
	int gn = tmp % 10;
	
	int i;
	for(i = 0; i < gn; i++){
		printf("%d", i + 1);
	}
	return 0;
}