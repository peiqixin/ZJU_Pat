/*
	10-排序6 Sort with Swap(0, i) 
	Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

	Swap(0, 1) => {4, 1, 2, 0, 3}
	Swap(0, 3) => {4, 1, 2, 3, 0}
	Swap(0, 4) => {0, 1, 2, 3, 4}
	Now you are asked to find the minimum number of swaps need to sort the given permutation of the first NN nonnegative integers.

	Input Specification:

	Each input file contains one test case, which gives a positive N<=10000 followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

	Output Specification:

	For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

	Sample Input:

	10
	3 5 7 2 6 4 9 0 8 1
	Sample Output:

	9
*/
#include <stdio.h>

int FindIndex(int A[], int X, int N);
int Solve(int A[], int B[], int N);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[N], B[N], i;
	for(i = 0; i < N; i++)
		scanf("%d",&A[i]);
	// for(i = 0; i < N; i++)
	// 	B[i] = FindIndex(A, A[i], N);
	for(i = 0; i < N; i++)
		B[A[i]] = i;
	printf("%d\n", Solve(A, B, N));
	return 0;
}

int FindIndex(int A[], int X, int N)
{
	int i;
	for(i = 0; i < N; i++){
		if(X == A[i])
			break;
	}
	return i;
}

int Solve(int A[], int B[], int N)
{
	int i, count, tmp;
	int countTotal = 0;
	for(i = 0; i < N; i++){
		int flag = 0;
		int EnterFlag = 0;
		count = 0;
		while(B[i] != i){
			EnterFlag = 1;
			if(A[i] == 0)
				flag = 1;
			A[i] = i;
			tmp = B[i];
			B[i] = i;
			i = tmp;
			count++;
		}
		if(EnterFlag){
			if(flag == 1)
				count--;
			else
				count++;
		}
		countTotal += count;
	}
	return countTotal;
}