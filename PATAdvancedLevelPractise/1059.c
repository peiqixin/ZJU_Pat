#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node *PtrToNode;
struct Node
{
	int p, k;
	PtrToNode next;
};
int isPrime(int n)
{
	int i;
	for(i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}
int NextPrime(int n)
{
	n++;
	while(1)
	{
		if(isPrime(n)) return n;
		n++;
	}
}
PtrToNode NewNode(int prime)
{
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
	newNode->p = prime;
	newNode->k = 1;
	newNode->next = NULL;
	return newNode;
}
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	if(N == 1){
		printf("1=1\n");
		return 0;
	} else if(isPrime(N)){
		printf("%d=%d\n", N, N);
		return 0;
	}
	int origin = N;
	int prime = NextPrime(1);
	PtrToNode pkList = NULL;
	PtrToNode ptr, newNode;
	while(N != 1){
		if(N % prime == 0){
			if(!pkList)
			{
				pkList = NewNode(prime);
				ptr = pkList;
			}
			else
			{
				if(ptr->p == prime)
					ptr->k++;
				else
				{
					newNode = NewNode(prime);
					ptr->next = newNode;
					ptr = newNode;
				}
			}
			N = N / prime;
		}else{
			prime = NextPrime(prime);
		}
	}
	printf("%d=", origin);
	ptr = pkList;
	if(ptr->k == 1)
		printf("%d", ptr->p);
	else
		printf("%d^%d", ptr->p, ptr->k);
	ptr = ptr->next;
	while(ptr){
		if(ptr->k == 1)
			printf("*%d", ptr->p);
		else
			printf("*%d^%d", ptr->p, ptr->k);
		ptr = ptr->next;
	}
	printf("\n");
	return 0;
}