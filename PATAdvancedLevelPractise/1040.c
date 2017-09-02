#include <stdio.h>
#include <string.h>

void reverse(char str[], char reversed_str[])
{
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++)
		reversed_str[len - i - 1] = str[i];
}
int find_longest_symmetric_str(char str[], char reversed_str[])
{
	int len = strlen(str);
	int longest_str = 0;
	int i, j, k;
	for(i = 0; i < len; i++){
		int now_len = 0;
		int k = i;
		for(j = 0; j < len; j++){
			if(str[k] == reversed_str[j]){
				k++;
				now_len++;
				if(now_len > longest_str)
					longest_str = now_len;
			}else
				now_len = 0;
		}
	}
	return longest_str;
}

int main(int argc, char const *argv[])
{
	char str[1001];
	int index = 0;
	while(1){
		char ch = getchar();
		if(ch != '\n')
			str[index++] = ch;
		else
			break;
	}
	char reversed_str[1001];
	reverse(str, reversed_str);
	printf("%d\n", find_longest_symmetric_str(str, reversed_str));
	return 0;
}