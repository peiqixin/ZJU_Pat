#include <stdio.h>
#include <math.h>
int N;
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int MaxCount = 0, i, First;

	int Number = N;
	for(i = 2; i <= sqrt(N); i++){
		int start = i;
		Number = N;
		while(Number % start == 0){
			Number /= start;
			start++;
		}
		if(start - i > MaxCount){
			MaxCount = start - i;
			First = i;
		}
	}
	if(MaxCount == 0){
		printf("1\n");
		printf("%d\n", N);
	}else{
		printf("%d\n", MaxCount);
		for(i = 0; i < MaxCount; i++)
			if(i != MaxCount - 1)
				printf("%d*", First++);
			else
				printf("%d\n", First++);
	}
	return 0;
}