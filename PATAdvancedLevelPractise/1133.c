#include <stdio.h>

int start, N, K;
struct Node
{
	int data, next;
};
struct Node List[100000];
int NegativeStack[100000], GtKStack[100000], LtKStack[100000];
int nTop, gTop, lTop;

void Init()
{
	scanf("%d %d %d",&start, &N , &K);
	nTop = gTop = lTop = -1;
	int i;
	for(i = 0; i < N; i++)
	{
		int addr, data, next;
		scanf("%d %d %d", &addr, &data, &next);
		List[addr].data = data;
		List[addr].next = next;
	}
}

void InitStack()
{
	int addr = start;
	while(addr != -1)
	{
		if(List[addr].data < 0)
			NegativeStack[++nTop] = addr;
		else if(List[addr].data > K)
			GtKStack[++gTop] = addr;
		else
			LtKStack[++lTop] = addr;
		addr = List[addr].next;
	}
}

void Rearrange()
{
	int i;
	if(nTop >= 0)
		start = NegativeStack[0];
	else if(lTop >= 0)
		start = LtKStack[0];
	else
		start = GtKStack[0];

	for(i = 0; i <= nTop; i++)
		if(i != nTop)
			List[NegativeStack[i]].next = NegativeStack[i + 1];
		else if(lTop >= 0)
			List[NegativeStack[i]].next = LtKStack[0];
		else if(gTop >= 0)
			List[NegativeStack[i]].next = GtKStack[0];
		else
			List[NegativeStack[i]].next = -1;
	for(i = 0; i <= lTop; i++)
		if(i != lTop)
			List[LtKStack[i]].next = LtKStack[i + 1];
		else if(gTop >= 0)
			List[LtKStack[i]].next = GtKStack[0];
		else
			List[LtKStack[i]].next = -1;
	for(i = 0; i <= gTop; i++)
		if(i != gTop)
			List[GtKStack[i]].next = GtKStack[i + 1];
		else
			List[GtKStack[i]].next = -1;
}

void Print()
{
	int addr = start;
	while(List[addr].next != -1)
	{
		printf("%05d %d %05d\n", addr, List[addr].data, List[addr].next);
		addr = List[addr].next;
	}
	printf("%05d %d -1\n", addr, List[addr].data);
}

int main(int argc, char const *argv[])
{
	Init();
	InitStack();
	Rearrange();
	Print();
	return 0;
}