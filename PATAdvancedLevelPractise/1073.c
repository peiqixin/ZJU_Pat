#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// +号不能输出，看了别人的注释才发现。。。看题不仔细
int main(int argc, char const *argv[])
{
	char c1, c2, s[10001], str[10024];
	int d1, exp;
	gets(str);
	c1 = str[0];
	d1 = str[1] - '0';
	int i, inx = 0;
	for(i = 3; i < strlen(str); i++)
		if(str[i] == 'E')
			break;
		else
			s[inx++] = str[i];
	inx = 0;
	c2 = str[i + 1];
	char expo[10000];
	for(i = i + 2; i < strlen(str); i++)
		expo[inx++] = str[i];
	exp = atoi(expo);
	if(c1 != '+')
		printf("%c", c1);
	if(exp == 0){
		printf("%d.%s\n", d1, s);
		return 0;
	}
	if(c2 == '+'){
		int length = strlen(s);
		if(exp >= length){
			printf("%d%s", d1, s);
			int i;
			for(i = 0; i < exp - length; i++)
				printf("0");
		}else{
			int dotPos = exp;
			int i;
			for(i = length; i > dotPos; i--)
				s[i] = s[i - 1];
			s[dotPos] = '.';
			printf("%d%s", d1, s);
		}
		printf("\n");
	}else if(c2 == '-'){
		char s2[10001];
		int i;
		s2[0] = '0';
		s2[1] = '.';
		for(i = exp; i > 1; i--)
			s2[i] = '0';
		s2[exp + 1] = '0' + d1;
		s2[exp + 2] = '\0';
		printf("%s%s\n", s2, s);
	}
	return 0;
}