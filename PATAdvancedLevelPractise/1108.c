#include <stdio.h>
#include <string.h>
#include <math.h>

// count == 1 , The average of 1 number is.. 不仔细看题
int Format(char str[], double *number)
{
	int len = strlen(str);
	int i, pointPos = -1;
	double num = 0;
	for(i = 0; i < len; i++)
	{
		if(str[i] == '.')
		{
			if(pointPos == -1)
				pointPos = i;
			else // 则说明不止一个小数点
				return -1;
		}
		else if(str[i] < '0' || str[i] > '9')
			return -1;
	}
	if(pointPos == -1)
	{
		for(i = 0; i < len; i++)
		{
			num += pow(10, len - i - 1) * (str[i] - '0');
			if(num > 1000)
				return -1;
		}
	}
	else
	{
		if(len - 1 - pointPos > 2) // 不止两位小数
			return -1;
		for(i = 0; i < pointPos; i++)
		{
			num += pow(10, pointPos - i - 1) * (str[i] - '0');
			if(num > 1000)
				return -1;
		}
		for(i++; i < len; i++)
			num += pow(10, -(i - pointPos)) * (str[i] - '0');
	}
	if(num > 1000)
		return -1;
	*number = num;
	return 1;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	char String[100];
	int i, count = 0;
	double total = 0;
	for(i = 0; i < N; i++)
	{
		scanf("%s", String);
		double number;
		int flag;
		if(String[0] == '-')
			flag = Format(String + 1, &number);
		else
			flag = Format(String, &number);
		if(flag == 1)
		{
			if(String[0] == '-')
				total -= number;
			else
				total += number;
			count++;
		}
		else
			printf("ERROR: %s is not a legal number\n", String);
	}
	if(count == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if(count == 1)
		printf("The average of 1 number is %.2lf\n", total);
	else
		printf("The average of %d numbers is %.2lf\n", count, total / count);
	return 0;
}