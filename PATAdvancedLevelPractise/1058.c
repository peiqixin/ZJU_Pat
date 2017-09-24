#include <stdio.h>
int main(int argc, char const *argv[])
{
	int A[3], B[3];
	scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
	scanf("%d.%d.%d", &B[0], &B[1], &B[2]);
	int k, s, g;
	k = A[2] + B[2];
	s = A[1] + B[1];
	g = A[0] + B[0];
	int ovflag = 0;
	if(k >= 29){
		k = k % 29;
		ovflag = 1;
	}
	if(ovflag){
		s = s + ovflag;
		ovflag = 0;
	}
	if(s >= 17){
		ovflag =  s / 17;
		s = s % 17;
	}
	if(ovflag)
		g = g + ovflag;
	printf("%d.%d.%d\n", g, s, k);
	return 0;
}