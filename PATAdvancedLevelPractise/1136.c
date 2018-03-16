#include <stdio.h>
#include <string.h>

char str[1002];
int IsPalindrome()
{
	int i;
	int len = strlen(str);
	for(i = 0; i < len / 2; i++)
		if(str[i] != str[len - 1 - i])
			return 0;
	return 1;
}

void GetReverseStr(char reverseStr[])
{
	int i;
	int len = strlen(str);
	for(i = 0; i < len; i++)
		reverseStr[len - 1 - i] = str[i];
	reverseStr[len] = '\0';
}

void Add(char reverseStr[])
{
	int i, overflow = 0;
	char temp[1002];
	for(i = strlen(str) - 1; i >= 0 ; i--)
	{
		int sum = (str[i] - '0') + (reverseStr[i] - '0') + overflow;
		temp[i] = sum % 10 + '0';
		overflow = sum / 10;
	}
	if(overflow)
	{
		str[0] = '0' + overflow;
		strncpy(str + 1, temp, strlen(str));
	}
	else
		strncpy(str, temp, strlen(str));
}

int main(int argc, char const *argv[])
{
	scanf("%s", str);
	char reverseStr[1002];
	int i = 0;
	while(!IsPalindrome(str) && i < 10)
	{
		GetReverseStr(reverseStr);
		printf("%s + %s = ", str, reverseStr);
		Add(reverseStr);
		printf("%s\n", str);
		i++;
	}
	if(i < 10)
		printf("%s is a palindromic number.\n", str);
	else
		printf("Not found in 10 iterations.\n");
	return 0;
}