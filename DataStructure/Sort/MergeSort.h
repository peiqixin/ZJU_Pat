#define MAX 214748347
// void Merge(int A[], int p, int q, int r);
// void MergeSort(int A[], int p, int q);

// 归并排序
void Merge(int A[], int p, int q, int r)
{
	int lengthA = q - p + 1;
	int lengthB = r - q;
	int i;
	int L[lengthA + 1];
	int R[lengthB + 1];
	L[lengthA] = MAX;
	R[lengthB] = MAX;
	for(i = 0; i < lengthA; i++)
		L[i] = A[i + p];
	for(i = 0; i < lengthB; i++) 
		R[i] = A[i + q + 1];
	i = 0;
	int j = 0, k;
	for(k = p; k <= r; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int A[], int p, int r)
{
	if(p < r){
		int q = (p + r)/2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}