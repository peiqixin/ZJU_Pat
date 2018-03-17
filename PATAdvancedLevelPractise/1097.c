#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100000
int N;
struct Node
{
	int data, next;
} List[MAX];
int hash[10001];

int a[MAX], b[MAX];

int main(int argc, char const *argv[])
{
	int N, head;
	scanf("%d %d", &head, &N);
	for(int i = 0; i < N; i++)
	{
		int addr;
		scanf("%d", &addr);
		scanf("%d %d", &List[addr].data, &List[addr].next);
	}
	memset(hash, 0, sizeof(int) * 10000);
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;	
	for(int i = head; i != -1; i = List[i].next)
	{
		if(hash[abs(List[i].data)] == 0)
		{
			hash[abs(List[i].data)] = 1;
			a[cnt1++] = i;
		}
		else
			b[cnt2++] = i;
	}
	
	if(cnt1 > 0)
	{
		for(int i = 0; i < cnt1 - 1; i++)
			printf("%05d %d %05d\n", a[i], List[a[i]].data, a[i + 1]);
		printf("%05d %d -1\n", a[cnt1 - 1], List[a[cnt1 - 1]].data);
	}
	if(cnt2 > 0)
	{
		for(int i = 0; i < cnt2 - 1; i++)
			printf("%05d %d %05d\n", b[i], List[b[i]].data, b[i + 1]);
		printf("%05d %d -1\n", b[cnt2 - 1], List[b[cnt2 - 1]].data);
	}
	return 0;
}
