#include <stdio.h>
#include <string.h>

int isPalindromicNumber(int num[], int length)
{
	int flag = 1;
	int i, j;
	for(i = 0, j = length - 1; i < j; i++, j--)
		if(num[i] != num[j]){
			flag = 0;
			break;
		}
	return flag;
}

void convert(int num[], int convert_num[], int length)
{
	int i;
	for(i = 0; i < length; i++)
		convert_num[length - 1 - i] = num[i];
}

void add(int num[], int convert_num[], int* length)
{
	int i, j;
	int overflow = 0;
	int stack[*length];
	int top = -1;
	for(i = *length - 1; i >= 0; i--){
		int tmp = num[i] + convert_num[i] + overflow;
		if(tmp > 9){
			overflow = 1;
			tmp = tmp % 10;
		}else{
			overflow = 0;
		}
		++top;
		stack[top] = tmp;
	}
	i = 0;
	if(overflow){
		num[0] = 1;
		i = 1;
		*length = *length + 1;
	}
	for(j = top; j >= 0; j--){
		num[i] = stack[j];
		i++;
	}
}
int main(int argc, char const *argv[])
{
	int num[60], step, length, i;
	length = 0;
	char c;
	for(i = 0; i < 100; i++){
		if((c = getchar()) == ' ') break;
		num[i] = c - '0';
		length++;
	}
	scanf("%d", &step);
	int convert_num[60];
	int count;
	for(count = 0; count < step; count++){
		if(isPalindromicNumber(num, length))
			break;
		else{
			convert(num, convert_num, length);
			add(num, convert_num, &length);
		}
	}
	for(i = 0; i < length; i++)
		printf("%d", num[i]);
	printf("\n%d\n", count);
	return 0;
}
