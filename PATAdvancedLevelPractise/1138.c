#include <stdio.h>
int pre[50000], in[50000], N;

int solveFlag = 0;
void Init()
{
	scanf("%d", &N);
	int i;
	for(i = 0; i < N; i++)
		scanf("%d", &pre[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &in[i]);
}

void Solve(int preL, int inL, int postL, int n)
{
	if(solveFlag) return;
	if(postL == 0)
	{
		printf("%d\n", pre[preL]);
		solveFlag = 1;
		return;
	}
	if(n == 1)
		return;
	
	int i, root = pre[preL];
	for(i = 0; i < n; i++)
		if(in[i + inL] == root)
			break;
	int leftLength = i;
	int rightLength = n - leftLength - 1;
	if(leftLength > 0)
		Solve(preL + 1, inL, postL - rightLength - 1, leftLength);
	if(rightLength > 0)
		Solve(preL + leftLength + 1, inL + leftLength + 1, postL - 1, rightLength);
}

int main(int argc, char const *argv[])
{
	Init();
	Solve(0, 0, N - 1, N);
	return 0;
}