#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[100], B[100], N;
void InsertionSort(int num[], int i)
{
	int Tmp = num[i];
	for(; i > 0 && num[i - 1] > Tmp; i--)
		num[i] = num[i - 1];
	num[i] = Tmp;
}

int IsSame(int num[])
{
	int i;
	for(i = 0; i < N; i++)
		if(num[i] != B[i])
			return 0;
	return 1;
}

void Print(int num[])
{
	int i;
	for(i = 0; i < N; i++){
		printf("%d", num[i]);
		if(i != N - 1)
			printf(" ");
		else
			printf("\n");
	}
}

void PercDown(int num[], int p, int n)
{
	int parent, child, Tmp;
	Tmp = num[p];
	for(parent = p; (parent * 2 + 1) < n; parent = child){
		child = parent * 2 + 1;
		if(child < n - 1 && (num[child] < num[child + 1]))
			child++;
		if(Tmp >= num[child])
			break;
		else
			num[parent] = num[child];
	}
	num[parent] = Tmp;
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

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Solve()
{
	int insertion[N], i;
	memcpy(insertion, A, sizeof(int) * N);
	for(i = 1; i < N; i++){
		InsertionSort(insertion, i);
		if(IsSame(insertion)){
			InsertionSort(insertion, i + 1);
			printf("Insertion Sort\n");
			Print(insertion);
			return;
		}
	}
	
	for(i = N / 2 - 1; i >= 0; i--)
		PercDown(A, i, N);
	for(i = N - 1; i > 0; i--){
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
		if(IsSame(A)){
			Swap(&A[0], &A[i - 1]);
			PercDown(A, 0, i - 1);
			printf("Heap Sort\n");
			Print(A);
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