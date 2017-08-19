#include <stdio.h>

void Print(int Numbers[], int N);
void SolveProblem(int Numbers[], int N, int M);

int main(int argc, char const *argv[])
{
	int N, M, i;
	scanf("%d %d", &N, &M);
	int Numbers[N];
	for(i = 0; i < N; i++){
		scanf("%d", &Numbers[i]);
	}
	SolveProblem(Numbers, N, M);
	Print(Numbers, N);
	return 0;
}

void Print(int Numbers[], int N)
{
	int i;
	for(i = 0; i < N - 1; i++)
		printf("%d ", Numbers[i]);
	printf("%d\n", Numbers[N-1]);
}

void SolveProblem(int Numbers[], int N, int M)
{
	if(M % N == 0)
		return;
	if(M > N)
		M = M % N;
	int tmp, i, j, tmpPre;
	for(j = 0, i = N -1; j < M; i--,j++){
		
	}
}