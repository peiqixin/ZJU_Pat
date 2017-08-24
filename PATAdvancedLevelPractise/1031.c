#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str[80];
	scanf("%s", str);
	int length = strlen(str);
	int length1 = (length + 2) / 3;
	int length2 = length - length1 * 2;
	int start, end;
	for(start = 0, end = length - 1; start < length1 - 1; start++, end--){
		printf("%c", str[start]);
		int i;
		for(i = 0; i < length2; i++)
			printf(" ");
		printf("%c\n", str[end]);
	}
	for(;start <= end; start++)
		printf("%c", str[start]);
	printf("\n");
	return 0;
}