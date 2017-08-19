// 09-排序1 排序 
/*
	09-排序1 排序   (25分)
	给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

	本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：

	数据1：只有1个元素；
	数据2：11个不相同的整数，测试基本正确性；
	数据3：103个随机整数；
	数据4：104个随机整数；
	数据5：105个随机整数；
	数据6：105个顺序整数；
	数据7：105个逆序整数；
	数据8：105个基本有序的整数；
	数据9：105个随机正整数，每个数字不超过1000。
	输入格式:

	输入第一行给出正整数NN（\le 10^5≤10
	​5
	​​ ），随后一行给出NN个（长整型范围内的）整数，其间以空格分隔。

	输出格式:

	在一行中输出从小到大排序后的结果，数字间以1个空格分隔，行末不得有多余空格。

	输入样例:

	11
	4 981 10 -17 0 -20 29 50 8 43 -5
	输出样例:

	-20 -17 -5 0 4 8 10 29 43 50 981
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Print(ElementType A[], int N);

/* 插入排序 */
void InsertionSort(ElementType A[], int N);

/* 希尔排序 */
void ShellSort(ElementType A[], int N);

/* 堆排序 */
void Swap(ElementType *a, ElementType *b);
void HeapSort(ElementType A[], int N);
void PercDown( ElementType A[], int p, int N );

/* 归并排序 - 递归实现 */
void MergeSort(ElementType A[], int N);
void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd );
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd );

/* 归并排序 - 循环实现 */
void Merge_Sort(ElementType A[], int N);
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length );

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, num[N];
	int x;
	for(i = 0; i < N; i++){
		if(i != N-1)
			scanf("%d ", &x);
		else
			scanf("%d", &x);
		num[i] = x;
	}
	Merge_Sort(num, N);
	Print(num, N);
	return 0;
}


void InsertionSort(ElementType A[], int N)
{
	int P, i;
	ElementType tmp;
	for(P = 1; P < N; P++){
		tmp = A[P];	/* 取出未排序序列中的第一个元素*/
		for(i = P; i > 0 && tmp < A[i-1]; i--)
			A[i] = A[i-1];	/*依次与已排序序列中元素比较并右移*/
		A[i] = tmp;	/* 放进合适的位置 */
	}
}

void Print(ElementType A[], int N)
{
	int i;
	for(i = 0; i < N; i++){
		if(i != 0)
			printf(" %d", A[i]);
		else
			printf("%d", A[i]);
	}
	printf("\n");
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

void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}

void HeapSort(ElementType A[], int N)
{
	int i;
	for(i = N/2 - 1; i >= 0; i--)
		PercDown(A, i, N);
	for(i = N-1; i > 0; i--){
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

void PercDown( ElementType A[], int p, int N )
{
	int Parent, Child;
	ElementType X;

	X = A[p];
	for(Parent = p; (Parent * 2 + 1 ) < N; Parent = Child){
		Child = Parent * 2 + 1;
		if(Child != N-1 && A[Child] < A[Child+1])
			Child++;
		if(X > A[Child]) break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void MergeSort(ElementType A[], int N)
{
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(sizeof(ElementType) * N);
	if(TmpA != NULL){
		Msort(A, TmpA, 0, N-1);
		free(TmpA);
	}
}


void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{
	int Center;
	if(L < RightEnd){
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);
		Msort(A, TmpA, Center + 1, RightEnd);
		Merge(A, TmpA, L, Center + 1, RightEnd);
	}
}
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{
	int LeftEnd, NumElements, Tmp;
	int i;
	LeftEnd = R - 1;
	Tmp = L;
	NumElements = RightEnd - L + 1;
	while(L <= LeftEnd && R <= RightEnd){
		if(A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while(R <= RightEnd)
		TmpA[Tmp++] = A[R++];

	/* 将有序的TmpA[]复制回A[] */ 
	for(i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}

void Merge_Sort(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;
	
	length = 1;
	TmpA = (ElementType *)malloc(sizeof(int) * N);
	if(TmpA != NULL){
		while(length < N){
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
	}
}

void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{
	int i, j;

	for(i = 0; i < N - length * 2; i += length * 2)
		Merge(A, TmpA, i, i + length, i + 2 * length -1);
	if(i + length < N)
		Merge(A, TmpA, i, i + length, N - 1);
	else
		for(j = i; j < N; j++) TmpA[j] = A[j];
}