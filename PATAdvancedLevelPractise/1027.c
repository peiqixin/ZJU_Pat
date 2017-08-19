#include <stdio.h>
int main(int argc, char const *argv[])
{
	int dc[3], i;
	for(i = 0; i < 3; i++)
		scanf("%d", &dc[i]);
	printf("#");
	for(i = 0; i < 3; i++){
		int r = dc[i] / 13;
		if(r < 10){
			printf("%d", r);
		}else if(r == 10){
			printf("A");
		}else if(r == 11){
			printf("B");
		}else{
			printf("C");
		}
		r = dc[i] % 13;
		if(r < 10){
			printf("%d", r);
		}else if(r == 10){
			printf("A");
		}else if(r == 11){
			printf("B");
		}else{
			printf("C");
		}
	}
	printf("\n");
	return 0;
}