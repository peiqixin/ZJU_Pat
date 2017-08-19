#include <stdio.h>
#include <memory.h>
#define INF -1
#define MAX(a,b) ((a)>=(b)?a:b)

int MemrizedCutRodAux(int p[], int n, int r[])
{
	int q, i;
	if(r[n] >= 0)
		return r[n];
	if(n == 0)
		q = 0;
	else{
		q = INF;
		for(i = 0; i < n; i++)
			q = MAX(q, p[i] + MemrizedCutRodAux(p, n - i - 1, r));
	}
	r[n] = q;
	return q;
}

int BottomUpCutRod(int p[], int n, int r[])
{
	r[0] = 0;
	int i, j, q;
	for(j = 0; j < n; j++){
		q = INF;
		for(i = 0; i < j ; i++){
			q = MAX(q, p[i] + r[j-i-1]);
		}
		r[j] = q;
	}
	return r[n];
}

int ExtendBottomUpCutRod(int p[], int n, int r[], int s[])
{
	r[0] = 0;
	int i, j, q;
	for(j = 0; j < n; j++){
		
	}
}

int main(int argc, char const *argv[])
{
	int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int r[11];
	memset(r, INF, sizeof(r));
	int s[11];
	memset(r, INF, sizeof(s));
	int i;
	for(i = 0; i < 10; i++)
		printf("%d\n", r[i]);
	printf("best cut price is %d\n", MemrizedCutRodAux(p, 10, r));
	printf("best cut price is %d\n", BottomUpCutRod(p, 1, r));
	return 0;
}