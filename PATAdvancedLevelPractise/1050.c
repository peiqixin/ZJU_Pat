#include <stdio.h>
#include <string.h>

#define MAX 10001
int main(int argc, char const *argv[])
{
	char s1[MAX];
	char c;
	int i = 0;
	int hash_s2[129];

	memset(hash_s2, 0, sizeof(int) * 129);
	while((c = getchar()) != '\n')
		s1[i++] = c;

	s1[i] = '\0';

	while((c = getchar()) != '\n')
		hash_s2[(int)c]++;
	int length = strlen(s1);
	for(i = 0; i < length; i++){
		if(hash_s2[(int)s1[i]] == 0)
			printf("%c", s1[i]);
	}
	printf("\n");
	return 0;
}