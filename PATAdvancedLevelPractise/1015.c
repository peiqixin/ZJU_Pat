#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct prime_node* PtrToPrimeNode;
struct prime_node
{
	int prime;
	int radix;
	PtrToPrimeNode next;
};
bool is_prime(int n);
int calculate_with_radix(int num, int radix);
bool is_reversible_prime(PtrToPrimeNode prime)
{
	if(!is_prime(prime->prime))
		return false;
	if(is_prime(calculate_with_radix(prime->prime, prime->radix)))
		return true;
	else
		return false;
}

int calculate_with_radix(int num, int radix)
{
	int stack[18];
	int top = -1;
	int consult = num;
	int remainder;
	while(consult > 0){
		remainder = consult % radix;
		consult = consult / radix;
		top++;
		stack[top] = remainder;
	}
	int i;
	int number = 0;
	int expo = top;
	for(i = 0; i <= top; i++){
		number = number + pow(radix, expo) * stack[i];
		expo--;
	}
	return number;
}

bool is_prime(int n)
{
	if(n == 1)
		return false;
	int i, j;
	j = (int)sqrt(n);
	bool flag = true;
	for(i = 2; i <= j ; i++){
		if(n % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}
int main(int argc, char const *argv[])
{
	int prime, radix;
	PtrToPrimeNode head = (PtrToPrimeNode)malloc(sizeof(struct prime_node));
	PtrToPrimeNode ptr = head;
	while(1){
		scanf("%d", &prime);
		if(prime < 0) break;
		scanf("%d", &radix);
		PtrToPrimeNode new_node = (PtrToPrimeNode)malloc(sizeof(struct prime_node));
		new_node->prime = prime;
		new_node->radix = radix;
		new_node->next = NULL;
		ptr->next = new_node;
		ptr = ptr->next;
	}
	ptr = head->next;
	while(ptr){
		if(is_reversible_prime(ptr))
			printf("Yes\n");
		else
			printf("No\n");
		ptr = ptr->next;
	}
	return 0;
}