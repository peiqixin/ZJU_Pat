// 希尔排序，使用Sedgewick增量
void ShellSort(int A[], int N)
{
	int Si, D, P, i;
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
	for(Si = 0; Sedgewick[Si] >= N; Si++)
		;
	int tmp;
	for(D = Sedgewick[i]; D >= 0; D = Sedgewick[++Si])
		for(P = D; P < N; P++){
			tmp = A[P];
			// InsertionSort
			for(i = P; i => D && A[i-D] > tmp; i-=D)
				A[i] = A[i-D];
			A[i] = tmp;
		}
}