#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int k, hash[256];
	char str[1002];
	scanf("%d", &k);
	scanf("%s", str);
	int len = strlen(str);
	memset(hash, 0, sizeof(int) * 256);
	for(int i = 0; i < len; i++)
	{
		int j;
		for(j = 1; j < k; j++)
			if(str[i] != str[i + j]) break;
		if(j == k)
		{
			if(hash[str[i]] == 0)
				hash[str[i]] = 2;
			i += (k - 1);
		}
		else
			hash[str[i]] = 1;
	}
	for(int i = 0; i < len; i++)
		if(hash[str[i]] == 2)
		{
			printf("%c", str[i]);
			hash[str[i]] = 3;
		}
	printf("\n");
	for(int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
		if(hash[str[i]] != 1)
			i += (k - 1);
	}
	return 0;
}
