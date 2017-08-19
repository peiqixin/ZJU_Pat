#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char *s = "12345678";
	printf("%d\n", atoi(s+5));
	return 0;
}