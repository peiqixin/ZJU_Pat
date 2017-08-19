#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3};
	printf("%p\n", a);
	printf("%d\n", *a);
	printf("%p\n", a+1);
	printf("%p\n", &a+1);
	printf("%p\n", *a+1);
	printf("%d\n", sizeof(int));
	return 0;
}