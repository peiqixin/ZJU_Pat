// 09-排序2 Insert or Merge
/*
	09-排序2 Insert or Merge   (25分)
	According to Wikipedia:

	Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

	Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

	Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

	Input Specification:

	Each input file contains one test case. For each case, the first line gives a positive integer NN (\le 100≤100). Then in the next line, NN integers are given as the initial sequence. The last line contains the partially sorted sequence of the NN numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

	Output Specification:

	For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

	Sample Input 1:

	10
	3 1 2 8 7 5 9 4 6 0
	1 2 3 7 8 5 9 4 6 0
	Sample Output 1:

	Insertion Sort
	1 2 3 5 7 8 9 4 6 0
	Sample Input 2:

	10
	3 1 2 8 7 5 9 4 0 6
	1 3 2 8 5 7 4 9 0 6
	Sample Output 2:

	Merge Sort
	1 2 3 8 4 5 7 9 0 6
*/
#include <stdio.h>
typedef int ElementType;
int IsEqual(int A[], int B[], int N);
int InsertionSort(int A[], int B[], int N);
void Print(int A[], int N);
int MergeSort(int A[], int B[], int N);
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length );
void Merge(int A[], int tmp[], int L, int R, int RightEnd);

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
	int InsertionFlag, MergeFlag;

	InsertionFlag = InsertionSort(A, B, N);
	if(InsertionFlag){
		printf("Insertion Sort\n");
		Print(A, N);
	}
	MergeFlag = MergeSort(A2, B, N);
	if(MergeFlag){
		printf("Merge Sort\n");
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

int MergeSort(int A[], int B[], int N)
{
	int tmp[N];
	int length = 1;
	int flag = 0;
	while(length < N){
		Merge_pass(A, tmp, N, length);
		length *= 2;
		if(IsEqual(A, B, N)){
			flag = 1;
			Merge_pass(A, tmp, N, length);
			break;
		}
	}
	return flag;
}

void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{
	int i, j;
	for(i = 0; i < N - length * 2; i += length*2)
		Merge(A, TmpA, i, i + length,i + length*2 - 1);
	if(i + length < N){
		Merge(A, TmpA, i , i + length, N-1);
	}else{
		for(j = i; j < N; j++) TmpA[j] = A[j];
	}
}

void Merge(int A[], int tmp[], int L, int R, int RightEnd)
{
	int LeftEnd, NumElements, Tmp;
	LeftEnd = R - 1;
	NumElements = RightEnd - L + 1;
	Tmp = L;
	while(L <= LeftEnd && R <= RightEnd){
		if(A[L] <= A[R])
			tmp[Tmp++] = A[L++];
		else
			tmp[Tmp++] = A[R++];
	}
	while(L <= LeftEnd)
		tmp[Tmp++] = A[L++];
	while(R <= RightEnd)
		tmp[Tmp++] = A[R++];
	int i;
	for(i = 0; i < NumElements; i++,RightEnd--)
		A[RightEnd] = tmp[RightEnd];
}