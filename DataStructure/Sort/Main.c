#include <stdio.h>
#include "MaxHeapSort.h"
#include "MergeSort.h"
#include "Print.h"
#include "MinHeapSort.h"
#include "QuickSort.h"

/*
10
4 3 2 1 0 9 8 7 6 5
*/
/*
用于进行算法的测试
*/
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i;
	int A[N];
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	MergeSort(A, 0, N-1);
	Print(A, N);
	BuilMaxHeap(A, N);
	Print(A, N);
	// BuilMinHeap(A, N);
	// Print(A, N);
	QuickSort(A, 0, N-1);
	Print(A, N);
	return 0;
}