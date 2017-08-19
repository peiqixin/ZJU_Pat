#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool IsPrime(int N);
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, count, pre;
	pre = 2;
	count = 0;
	for(i = 2; i <= N; i++){
		if(IsPrime(i)){
			if((i - pre) == 2){
				count++;
			}
			pre = i;
		}
	}
	printf("%d\n", count);
	return 0;
}

bool IsPrime(int N)
{
	int i;
	bool flag = true;
	for(i = sqrt(N); i > 1; i--){
		if(N % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}