#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int Numbers[N];
	int i;
	for(i = 0; i < N; i++){
		scanf("%d", &Numbers[i]);
	}
	
	int Stack[99];
	int top = -1;

	int Flag[101];
	for(i = 0; i < 101; i++)
		Flag[i] = 0;
	int tmp;
	for(i = 0; i < N; i++){
		tmp = Numbers[i];
		if(Flag[tmp] == 1)
			continue;
		while(tmp > 1){
			if(tmp % 2){
				tmp = (3 * tmp + 1) / 2;
			}else{
				tmp = tmp / 2;
			}
			Flag[tmp] = 1;
		}
	}

	for(i = 0; i < N; i++){
		if(Flag[Numbers[i]] == 0){
			Stack[++top] = Numbers[i];
		}
	}

	int j;
	for(i = 0; i < top; i++){
		for(j = i + 1; j <= top; j++){
			if(Stack[i] > Stack[j]){
				tmp = Stack[i];
				Stack[i] = Stack[j];
				Stack[j] = tmp;
			}
		}
	}
	if(top >= 0){
		for(i = 0; i < top; i++){
			printf("%d ", Stack[i]);
		}
		printf("%d\n", Stack[top]);
	}
	return 0;
}