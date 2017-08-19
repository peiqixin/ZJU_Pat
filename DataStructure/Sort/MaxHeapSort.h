// 最大堆排序
void MaxHeapfy(int A[], int i, int HeapSize)
{
	int R = (i + 1) * 2;
	int L = R - 1;
	int largest;
	// 找出i 和 左右孩子中最大的一个
	if(L < HeapSize && A[L] > A[i])
		largest = L;
	else
		largest = i;
	if(R < HeapSize && A[R] > A[largest])
		largest = R;
	// 如果最大的不是i（即最大的为左右孩子），则进行交换，并递归进行调整
	if(largest != i){
		// 互换
		int tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		// 递归调整
		MaxHeapfy(A, largest, HeapSize);
	}
}

void BuilMaxHeap(int A[], int Size)
{
	int i;
	for(i = (Size - 1) / 2; i >= 0; i--)
		MaxHeapfy(A, i, Size);
}