//1001. A+B Format (20)
// Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

// Input

// Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

// Output

// For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

// Sample Input
// -1000000 9
// Sample Output
// -999,991
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	if(sum > 999 || sum <-999){
		int flag = 0;
		int consult = sum / 1000000;
		if(consult != 0){
			printf("%d,", consult);
			flag = 1;
			if(sum < 0)
				sum = -sum;
		}
		int remainder = sum % 1000000;
		if(remainder == 0)
		{
			printf("000,000");
		}else{
			consult = remainder / 1000;
			if(consult != 0){
				if(flag){
					printf("%03d,", consult);
				}else{
					printf("%d,", consult);
				}
				if(sum < 0)
					sum = -sum;
			}
			remainder = sum % 1000;
			if (remainder == 0)
			{
				printf(",000");
			}else{
				printf("%03d", remainder);
			}
		}
		printf("\n");
	}else{
		printf("%d\n", sum);
	}
	return 0;
}