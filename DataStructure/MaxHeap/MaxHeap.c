#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef strcut HeapStruct* MaxHeap;
typedef int ElementType;
struct HeapStruct
{
	ElementType *Elements;
	int size;
	int Capacity;
};

MaxHeap Create(int MaxSize);
void Insert(MaxHeap H, ElementType item);
bool IsFull(MaxHeap H);
ElementType DeleteMax(MaxHeap H);
void PercDown(MaxHeap H, int p);
void BuilHeap(MaxHeap H);

int main(int argc, char const *argv[])
{
	
	return 0;
}

MaxHeap Create(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *)malloc(sizeof(ElementType) * (MaxSize+1));
	H->size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = 10000;
	return H;
}

void Insert(MaxHeap H, ElementType item)
{
	int i;
	if(IsFull(H)){
		printf("MaxHeap is Full!\n");
		return;
	}
	i = ++H->size;
	for(; item > H->Elements[i/2]; i/=2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = item;
}

bool IsFull(MaxHeap H)
{
	if(H->Capacity==0 && H->size==MaxSize)
		return true;
	else
		return false;
}

ElementType DeleteMax(MaxHeap H)
{
	int Parent, Child;
	ElementType MaxItem, temp;
	if(IsEmpty(H)){
		printf("MaxHeap is empty!\n");
		return;
	}
	// 取出最大值
	MaxItem = H->Elements[1];
	// 
	temp = H->Elements[H->size--];
	
	for(Parent = 1; Parent*2 < H->size; Parent = Child){
		Child = Parent * 2;
		if((Child != H->size) && H->Elements[Child] < H->Elements[Child+1])
			Child++;
		if(temp < H->Elements[Child]){
			H->Elements[Parent] = H->Elements[Child];
		}else{
			break;
		}
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

/*  Build Max Heap */
void PercDown(MaxHeap H, int p)
{
	int Parent, Child;
	ElementType X;
	X = H->Elements[p];
	for(Parent = p; Parent*2 <= H->size; Parent=Child){
		Child = Parent*2;
		if((Child < H->size) && (H->Elements[Child] < H->Elements[Child+1]))
			Child++;
		if(X < H->Elements[Child])
			H->Elements[Parent] = H->Elements[Child];
		else
			break;
	}
	H->Elements[Parent] = X;
}
void BuilHeap(MaxHeap H)
{
	int i;
	for(i = H->size / 2; i>=1; --i){
		PercDown(H, i);
	}
}