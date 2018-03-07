#include <stdio.h>
#include <string.h>

typedef char Data[11];
int N, Root;

Data data[20];
int Left[20], Right[20], NotRoot[20];

void BuildTree()
{
	scanf("%d", &N);
	memset(Left, -1, sizeof(int) * N);
	memset(Right, -1, sizeof(int) * N);
	memset(NotRoot, 0, sizeof(int) * N);
	int i;
	for(i = 0; i < N; i++)
	{
		int l, r;
		scanf("%s %d %d", data[i], &l, &r);
		if(l != -1)
		{
			l--;
			NotRoot[l] = 1;
			Left[i] = l;
		}
		if(r != -1)
		{
			r--;
			NotRoot[r] = 1;
			Right[i] = r;
		}
	}
	for(i = 0; i < N; i++)
		if(!NotRoot[i])
		{
			Root = i;
			break;
		}
}

void Tranverse(int r)
{
	if(r == -1)
		return;
	int bracketFlag = 0;
	if(r != Root && (Left[r] != -1 || Right[r] != -1))
		bracketFlag = 1;
	if(bracketFlag)
		printf("(");

	Tranverse(Left[r]);
	printf("%s", data[r]);
	Tranverse(Right[r]);

	if(bracketFlag)
		printf(")");
}

int main(int argc, char const *argv[])
{
	BuildTree();
	Tranverse(Root);
	printf("\n");
	return 0;
}