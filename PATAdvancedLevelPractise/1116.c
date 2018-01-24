#include <stdio.h>
#include <math.h>

struct Node
{
	int awardType;
	int checkFlg;
} List[10000];

int isPrime(int num)
{
	if(num == 1)
		return 0;
	int i;
	for(i = 2; i <= sqrt(num); i++)
		if(num % i == 0)
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, id;
	for(i = 1; i < 10000; i++)
	{
		List[i].awardType = -1;
		List[i].checkFlg = 0;
	}
	for(i = 0; i < N; i++)
	{
		scanf("%d", &id);
		if(i == 0)
			List[id].awardType = 0;
		else if(isPrime(i + 1))
			List[id].awardType = 1;
		else
			List[id].awardType = 2;
	}
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &id);
		if(List[id].awardType == -1)
			printf("%04d: Are you kidding?\n", id);
		else if(List[id].checkFlg == 1)
			printf("%04d: Checked\n", id);
		else if(List[id].awardType == 0)
			printf("%04d: Mystery Award\n", id);
		else if(List[id].awardType == 1)
			printf("%04d: Minion\n", id);
		else
			printf("%04d: Chocolate\n", id);
		List[id].checkFlg = 1;
	}
	return 0;
}