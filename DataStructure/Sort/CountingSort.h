// 计数排序 A[]是原始数组 B[]是排序好的数组，n是A的长度，k是所有数的范围
void CountingSort(int A[],int B[], int n, int k)
{
	int i, C[k];
	for(i = 0; i < k; i++)
		C[i] = 0;
	// 确定每个元素的个数
	for(i = 0; i < k; i++)
		C[A[i]] = C[A[i]] + 1;
	// 确定每个元素之前的元素个数
	for(i = 0; i < k; i++)
		C[i] = C[i] + C[i-1];
	for(i = n - 1; i >= 0; i--){
		// 找每个元素的位置
		B[C[A[i]]] = A[i]；
		C[A[i]] = C[A[i]] - 1;
	}
}