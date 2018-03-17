#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[N];
	int i;
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	int T[N];
	for(i = 0; i < N; i++)
		T[A[i]] = i;
	int count = 0;
	for(i = 0; i < N; i++)
	{
		if(A[i] == i) continue;
		int tmp = A[i];
		int tmpIndex = i;
		int zeroFlag = 0;
		int number = 1;
		if(i == 0) zeroFlag = 1;
		while(A[i] != i && i != tmp)
		{
			if(!A[i]) zeroFlag = 1;
			A[i] = A[T[i]];
			i = T[i];
			number++;
		}
		A[i] = tmp;
		if(zeroFlag) number--;
		else number++;
		count += number;
		i = tmpIndex;
	}
	printf("%d\n", count);
	return 0;
}