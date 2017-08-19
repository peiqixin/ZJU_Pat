void MinHeapfy(int A[],int i, int HeapSize)
{
	int R = (i + 1) * 2;
	int L = R - 1;
	int minist;
	if(L < HeapSize && A[L] < A[i])
		minist = L;
	else
		minist = i;
	if(R < HeapSize && A[R] < A[minist])
		minist = R;
	if(minist != i){
		//
		int tmp = A[i];
		A[i] = A[minist];
		A[minist] = tmp;
		// 
		MinHeapfy(A, minist, HeapSize);
	}
}

void BuilMinHeap(int A[], int Size)
{
	int i;
	for(i = (Size - 1) / 2; i >= 0; i--)
		MinHeapfy(A, i, Size);
}