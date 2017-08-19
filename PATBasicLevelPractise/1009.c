#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char s1[80],s2[80];
	gets(s1);
	int i;

	int len = 0;
	int top = -1;
	for(i = strlen(s1) - 1; i >= 0; i--){
		if(s1[i] != ' ' && i > 0)
			len++;
		else if(i > 0){
			int m;
			m = i + 1;
			int count = 0;
			while(count < len){
				s2[++top] = s1[m];
				m++;
				count++;
			}
			s2[++top] = ' ';
			len = 0;
		}else{
			len++;
			int m;
			m = i;
			int count = 0;
			while(count < len){
				s2[++top] = s1[m];
				m++;
				count++;
			}
		}
	}
	for(i = 0 ; i < strlen(s1); i++)
		printf("%c", s2[i]);
	printf("\n");
	return 0;
}