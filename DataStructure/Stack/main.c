#include "stack.h"
int main(int argc, char const *argv[])
{
	Stack s = CreateStack();
	Push(s,10);
	printf("%d\n", Pop(s));
	return 0;
}
