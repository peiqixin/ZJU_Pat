#include <stdio.h>

#include <string.h>

#define MAX 100
int A[MAX], B[MAX];
int N;
int IsSame(int NA[], int NB[])
{
	int i;
	for(i = 0; i < N; i++)
		if(NA[i] != NB[i])
			return 0;
	return 1;
}

void InsertionSort(int A[], int i)
{
	int Tmp = A[i];
	for(; i > 0 && A[i - 1] > Tmp; i--)
		A[i] = A[i - 1];
	A[i] = Tmp;
}

void Init()
{
	scanf("%d", &N);
	int i;
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &B[i]);
}

void Print(int num[])
{
	int i;
	for(i = 0; i < N; i++){
		printf("%d", num[i]);
		if(i != N - 1) printf(" ");
	}
	printf("\n");
}

void Merge(int A[], int TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, ElementNum, Tmp, i;
	LeftEnd = R - 1;
	ElementNum = RightEnd - L + 1;
	Tmp =  L;
	while(L <= LeftEnd && R <= RightEnd){
		if(A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while(R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for(i = 0; i < ElementNum; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}

void MergeSort(int A[], int TmpA[], int length)
{
	int i;
	for(i = 0; i < N - length * 2; i += length * 2)
		Merge(A, TmpA, i, i + length, i + length * 2 - 1);
	if(i + length < N)
		Merge(A, TmpA, i, i + length, N - 1);
	else
		for(; i < N; i++)
			TmpA[i] = A[i];
}

void Solve()
{
	int merge[N], insertion[N];
	memcpy(insertion, A, sizeof(int) * N);
	int TmpA[N], i;
	for(i = 1; i < N; i++){
		InsertionSort(insertion, i);
		if(IsSame(B, insertion)){
			printf("Insertion Sort\n");
			i++;
			InsertionSort(insertion, i);
			Print(insertion);
			return;
		}
	}
	
	memcpy(merge, A, sizeof(int) * N);
	int length = 1;
	while(length < N){
		MergeSort(merge, TmpA, length);
		length *= 2;
		if(IsSame(merge, B)){
			MergeSort(merge, TmpA, length);
			Print(merge);
			return;
		}
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}