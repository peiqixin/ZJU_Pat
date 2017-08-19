// 09-排序3 Insertion or Heap Sort
/*
	According to Wikipedia:

	Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

	Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

	Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

	Input Specification:

	Each input file contains one test case. For each case, the first line gives a positive integer NN (\le 100≤100). Then in the next line, NN integers are given as the initial sequence. The last line contains the partially sorted sequence of the NN numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

	Output Specification:

	For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

	Sample Input 1:

	10
	3 1 2 8 7 5 9 4 6 0
	1 2 3 7 8 5 9 4 6 0
	Sample Output 1:

	Insertion Sort
	1 2 3 5 7 8 9 4 6 0
	Sample Input 2:

	10
	3 1 2 8 7 5 9 4 6 0
	6 4 5 1 0 3 2 7 8 9
	Sample Output 2:

	Heap Sort
	5 4 3 1 0 2 6 7 8 9
*/
#include <stdio.h>

typedef int ElementType;

int IsEqual(int A[], int B[], int N);
int InsertionSort(int A[], int B[], int N);
void Print(int A[], int N);
int HeapSort(int A[], int B[], int N);
void PercDown(int A[], int p, int N);
void Swap(ElementType *a, ElementType *b);


int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[N], B[N], A2[N];
	int i;
	for(i = 0; i < N; i++){
		if(i != N-1)
			scanf("%d ", &A[i]);
		else
			scanf("%d", &A[i]);
		A2[i] = A[i];
	}
	for(i = 0; i < N; i++){
		if(i != N-1)
			scanf("%d ", &B[i]);
		else
			scanf("%d", &B[i]);
	}

	int InsertionFlag, HeapFlag;
	InsertionFlag = InsertionSort(A, B, N);
	if(InsertionFlag){
		printf("Insertion Sort\n");
		Print(A, N);
	}

	HeapFlag = HeapSort(A2, B, N);
	if(HeapFlag){
		printf("Heap Sort\n");
		Print(A2, N);
	}
	return 0;
}

int IsEqual(int A[], int B[], int N)
{
	int i;
	int flag = 1;
	for(i = 0; i < N; i++)
		if(A[i] != B[i])
			flag = 0;
	return flag;
}

int InsertionSort(int A[], int B[], int N)
{
	int i, tmp, p;
	for(i = 1; i < N; i++){
		tmp = A[i];
		for(p = i ; p > 0 && tmp < A[p-1]; p--)
			A[p] = A[p-1];
		A[p] = tmp;
		if(IsEqual(A, B, N)){
			i++;
			tmp = A[i];
			for(p = i; p > 0 && tmp < A[p-1]; p--)
				A[p] = A[p-1];
			A[p] = tmp;
			return 1;
		}
	}
	return 0;
}

void Print(int A[], int N)
{
	int i;
	for(i = 0; i < N-1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[N-1]);
}

int HeapSort(int A[], int B[], int N)
{
	int i;
	int flag = 0;
	for(i = N / 2 - 1; i >= 0; i--)
		PercDown(A, i, N);
	for(i = N - 1; i > 0; i--){
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
		if(IsEqual(A, B, N)){
			i--;
			Swap(&A[0], &A[i]);
			PercDown(A, 0, i);
			flag = 1;
			break;
		}
	}
	return flag;
}

void PercDown(int A[], int p, int N)
{
	int Parent, Child;
	ElementType X;
	X = A[p];
	for(Parent = p; (Parent * 2 + 1) < N; Parent = Child){
		Child = Parent * 2 + 1;
		if(Child != N - 1 && A[Child] < A[Child + 1]){
			Child++;
		}
		if(X < A[Child])
			A[Parent] = A[Child];
		else
			break;
	}
	A[Parent] = X;
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}
