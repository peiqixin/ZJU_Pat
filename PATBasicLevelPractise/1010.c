#include <stdio.h>

typedef struct PolyNode *PtrToNode;
struct PolyNode{
	int exp;
	int coef;
	PtrToNode Next;
};
int main(int argc, char const *argv[])
{
	int a, b;
	while(getchar() != '\n'){
		scanf("%d %d", &a, &b);
		printf("%d %d", a, b);
	}
	return 0;
}