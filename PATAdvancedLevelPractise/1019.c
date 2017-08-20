#include <stdio.h>
int stack[30];
int top = -1;
void convert_radix(int N, int b, int *length)
{
	int remainder, consult;
	if(N == 0){
		stack[++top] = 0;
		*length = 1;
	}else{
		consult = N;
		while(consult > 0){
			remainder = consult % b;
			stack[++top] = remainder;
			consult = consult / b;
			*length = *length + 1;
		}
	}
}

int is_palindromic()
{
	int i,j;
	for(i = 0, j = top; i < top; i++, j--){
		if(stack[i] != stack[j])
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int N, b;
	scanf("%d %d", &N, &b);
	int length = 0;
	convert_radix(N, b, &length);
	int i;
	if(is_palindromic()){
		printf("Yes\n");
		printf("%d", stack[0]);
		for(i = 1; i < length; i++)
			printf(" %d", stack[i]);
	}else{
		printf("No\n");
		printf("%d", stack[length - 1]);
		for(i = length - 2; i >= 0; i--)
			printf(" %d", stack[i]);
	}
	printf("\n");
	return 0;
}