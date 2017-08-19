#include <stdio.h>
int main(int argc, char const *argv[])
{
	char* s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	char c;
	int num = 0;
	while((c = getchar()) != '\n'){
		num += ((int)c - 48);
	}
	if(num < 10)
		printf("%s\n", s[num]);
	else{
		if(num > 99){
			int a = num / 100;
			int b = (num - a * 100) / 10;
			int c = num % 10;
			printf("%s %s %s\n", s[a], s[b], s[c]);
		}else{
			int a = num / 10;
			int b = num % 10;
			printf("%s %s\n", s[a], s[b]);
		}
	}
	return 0;
}