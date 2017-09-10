#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N1, N2, i, j;
	scanf("%d", &N1);
	long int num1[N1];
	for(i = 0; i < N1; i++)
		scanf("%ld", &num1[i]);

	scanf("%d", &N2);
	long int num2[N2];
	for(i = 0; i < N2; i++)
		scanf("%ld", &num2[i]);

	int median;
	if((N1 + N2) % 2){
		median = (N1 + N2) / 2;
	}else{
		median = (N1 + N2) / 2 - 1;
	}

	i = j = 0;
	while(i + j < median && i < N1 && j < N2){
		if(num1[i] <= num2[j])
			i++;
		else
			j++;
	}

	while(i + j < median){
		if(j == N2)
			i++;
		else
			j++;
	}

	if(j == N2 || (i != N1 && num1[i] <= num2[j]))
		printf("%ld\n", num1[i]);
	else
		printf("%ld\n", num2[j]);
	return 0;
}