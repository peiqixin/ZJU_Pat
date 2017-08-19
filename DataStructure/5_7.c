// 05-树7 堆中的路径
/*****
	将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

	输入格式:

	每组测试第1行包含2个正整数NN和MM(\le 1000≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的NN个要被插入一个初始为空的小顶堆的整数。最后一行给出MM个下标。

	输出格式:

	对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

	输入样例:

	5 3
	46 23 26 24 10
	5 4 3
	输出样例:

	24 23 10
	46 23 10
	26 10
*****/
#include <stdio.h>
#include <stdlib.h>
typedef struct HeapNode* MinHeap;
typedef int ElementType;
struct HeapNode{
	ElementType *Elements;
	int size;
	int capacity;
};
void Insert(MinHeap H, ElementType X);
int IsFull(MinHeap H);
void PrintRootPath(MinHeap H, int N);
MinHeap BuildMinHeap(MinHeap H, int N);
int main(int argc, char const *argv[])
{
	int N,L;
	scanf("%d %d\n", &N, &L);
	MinHeap H = NULL;
	H = BuildMinHeap(H, N);
	ElementType X;
	int i = 0;
	while(i < N){
		scanf("%d", &X);
		Insert(H, X);
		i++;
	}
	i = 0;
	int num[L];
	while(i < L){
		scanf("%d", &num[i]);
		i++;
	}
	i = 0;
	while(i < L){
		PrintRootPath(H, num[i]);
		i++;
	}
	return 0;
}

MinHeap BuildMinHeap(MinHeap H, int N)
{
	if(!H){
		H = malloc(sizeof(struct HeapNode));
		H->Elements = malloc(sizeof(ElementType) * (N + 1));
		H->size = 0;
		H->capacity = N;
		H->Elements[0] = -10001;
	}
	return H;
}

void Insert(MinHeap H, ElementType X)
{
	if(IsFull(H))
		return;
	else{
		int i = ++H->size;
		int Parent,Child;
		for(Child = i; Child / 2 > 0; Child=Parent){
			Parent = Child / 2;
			if(X < H->Elements[Parent])
				H->Elements[Child] = H->Elements[Parent];
			else 
				break;
		}
		H->Elements[Child] = X;
		H->capacity--;
	}
}

int IsFull(MinHeap H)
{
	if(H->capacity >= 0)
		return 0;
	else
		return 1;
}

void PrintRootPath(MinHeap H, int N)
{
	if(!H || N < 1)
		return;

	int i = N;
	while(i > 1){
		printf("%d ", H->Elements[i]);
		i = i/2;
	}
	printf("%d\n", H->Elements[1]);
}