// 快速排序 每次排序至少有一个元素位置被确定
int Partition(int A[], int p, int r);

void QuickSort(int A[], int p, int r)
{
	if(p < r){
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}	

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i, j;
	i = p - 1;
	for(j = p; j < r; j++){
		if(A[j] <= x){
			i = i + 1;
			Swap(&A[i], &A[j]);
		}
	}
	Swap(&A[i + 1], &A[r]);
	return i + 1;
}

