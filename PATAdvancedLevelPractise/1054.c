#include <stdio.h>
int main(int argc, char const *argv[])
{
	int M, N;
	scanf("%d %d", &M, &N);
	int i;
	int color, count, pre;
	scanf("%d", &pre);
	count = 1;
	for(i = 1; i < N * M; ++i){
		scanf("%d", &color);
		if(color == pre)
			count++;
		else{
			count--;
			if(count < 0){
				pre = color;
				count = 1;
			}
		}
		pre = color;
	}
	printf("%d\n", pre);
	return 0;
}