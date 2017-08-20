#include <stdio.h>
int main(int argc, char const *argv[])
{
	int length;
	scanf("%d" ,&length);
	int elevator[length];
	int i = 0;
	for(i = 0; i < length; i++)
		scanf("%d", &elevator[i]);
	int sum = length * 5;
	int pre = 0;
	for(i = 0; i < length; i++){
		if(elevator[i] - pre > 0)
			sum += (elevator[i] - pre) * 6;
		else
			sum += (pre - elevator[i]) * 4;
		pre = elevator[i];
	}
	printf("%d\n", sum);
	return 0;
}