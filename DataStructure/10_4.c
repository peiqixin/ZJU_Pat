// 10-排序4 统计工龄
/*
	给定公司NN名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

	输入格式:

	输入首先给出正整数NN（\le 10^5≤10
	​5
	​​ ），即员工总人数；随后给出NN个整数，即每个员工的工龄，范围在[0, 50]。

	输出格式:

	按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

	输入样例:

	8
	10 2 0 5 7 2 5 2
	输出样例:

	0:1
	2:3
	5:2
	7:1
	10:1
*/
#include <stdio.h>
typedef int ElementType;

void ShellSort(ElementType A[], int N);
void Print(ElementType A[], int N);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[N];
	int i;
	for(i = 0; i < N; i++){
		if(i != N-1)
			scanf("%d ", &A[i]);
		else
			scanf("%d", &A[i]);
	}
	ShellSort(A, N);
	Print(A, N);
	return 0;
}

void ShellSort(ElementType A[], int N)	/* 希尔排序 - 用Sedgewick增量序列 */
{
	int Si, D, P, i;
	ElementType tmp;
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
	for(Si = 0; Sedgewick[Si] >= N; Si++)
		;
	for(D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for(P = D; P < N; P++){
			tmp = A[P];
			for(i = P; i >= D && A[i-D] > tmp; i -= D)
				A[i] = A[i-D];
			A[i] = tmp;
		}
}

void Print(ElementType A[], int N)
{
	int count = 0, i;
	ElementType Pre = A[0];
	for(i = 0; i < N; i++){
		if(A[i] == Pre){
			count++;
		}else{
			printf("%d:%d\n", Pre, count);
			count = 1;
			Pre = A[i];
		}
	}
	printf("%d:%d\n", Pre, count);
}