#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
	return ((*(int*)a) < (*(int*)b));
}
int main(int argc, char const *argv[])
{
	int NC, NP;
	scanf("%d", &NC);
	int i;
	int coupon[NC];
	for(i = 0; i < NC; i++)
		scanf("%d", &coupon[i]);

	scanf("%d", &NP);
	int product[NP];	
	for(i = 0; i < NP; i++)
		scanf("%d", &product[i]);

	qsort(coupon, NC, sizeof(int), cmp);
	qsort(product, NP, sizeof(int), cmp);

	int max  = 0;
	int top, rear;
	top = 0;
	rear = NP - 1;

	for(i = 0; i < NC && coupon[i] > 0; i++){
		if(product[top] < 0)
			break;
		max += coupon[i] * product[top];
		top++;
	}
	for(i = NC - 1; i >= 0 && coupon[i] < 0; i--){
		if(product[rear] > 0)
			break;
		max += coupon[i] * product[rear];
		rear--;
	}

	printf("%d\n", max);
	return 0;
}

/*
6
4 2 1 0 -1 -2
4
7 6 -2 -3
*/