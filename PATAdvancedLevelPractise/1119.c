#include <stdio.h>
#include <string.h>

int Post[30], Pre[30], In[30];
int Left[30], Right[30], Parent[30];  // 模拟线索二叉树
int N, Another = 0;
int Index = 0;

void Init()
{
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &Pre[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &Post[i]);
	memset(Left, -1, sizeof(int) * 30);
	memset(Right, -1, sizeof(int) * 30);
	memset(Parent, -1, sizeof(int) * 30);
}

void Print()
{
	if(Another == 0)
		printf("Yes\n");
	else
		printf("No\n");
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d", In[i]);
		if(i != N - 1)
			printf(" ");
	}
	printf("\n");
}

int FindIndex(int X)
{
	int i;
	for(i = 0; i < N; i++)
		if(Post[i] == X)
			break;
	return i;
}

void Tranverse(int r)
{

	if(Left[r] != -1)
		Tranverse(Left[r]);
	In[Index++] = Pre[r];
	if(Right[r] != -1)
		Tranverse(Right[r]);
}

void Solve()
{
	int i, R;
	for(i = 1; i < N; i++)
	{
		R = i - 1;
		int index1 = FindIndex(Pre[R]); // 当前root
		int index2 = FindIndex(Pre[i]);
		if(index1 == index2 + 1 && R + 1 == i)
			Another = 1;
		while(index1 < index2)
		{
			R = Parent[R];
			index1 = FindIndex(Pre[R]);
		}
		if(Left[R] == -1)
		{
			Left[R] = i;
			Parent[i] = R;
		}
		else
		{
			Right[R] = i;
			Parent[i] = R;
		}
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	Tranverse(0);
	Print();
	return 0;
}