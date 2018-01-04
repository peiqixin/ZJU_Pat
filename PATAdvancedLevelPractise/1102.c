#include <stdio.h>
int N, Left[10], Right[10], RootFlg[10], root;
int flg = 1;
void Init()
{
	scanf("%d\n", &N);
	int i;
	for(i = 0; i < N; i++)
	{
		char c1, c2;
		scanf("%c %c\n", &c1, &c2);
		if(c1 != '-')
		{
			Left[i] = c1 - '0';
			RootFlg[Left[i]] = 1;
		}
		else
			Left[i] = -1;
		if(c2 != '-')
		{
			Right[i] = c2 - '0';
			RootFlg[Right[i]] = 1;
		}
		else
			Right[i] = -1;
	}
	for(i = 0; i < N; i++)
		if(RootFlg[i] != 1)
		{
			root = i;
			break;
		}
}

void LevelTranverse()
{
	int Queue[N];
	int top, rear, rootFlg;
	top = rear = -1;
	Queue[++top] = root;
	rootFlg = 1;
	while(rear < top)
	{
		int r = Queue[++rear];
		if(rootFlg)
		{
			printf("%d", r);
			rootFlg = 0;
		}
		else
			printf(" %d", r);
		if(Right[r] != -1)
			Queue[++top] = Right[r];
		if(Left[r] != -1)
			Queue[++top] = Left[r];
	}
	printf("\n");
}

void InOrderTranverse(int r)
{
	if(Right[r] != -1)
		InOrderTranverse(Right[r]);
	if(flg)
	{
		printf("%d", r);
		flg = 0;
	}
	else
		printf(" %d", r);
	if(Left[r] != -1)
		InOrderTranverse(Left[r]);
}

int main(int argc, char const *argv[])
{
	Init();
	LevelTranverse();
	InOrderTranverse(root);
	printf("\n");
	return 0;
}