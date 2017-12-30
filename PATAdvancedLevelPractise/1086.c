#include <stdio.h>

int N;
int pre[30], in[30], post[30];

void Print(int num[], int N)
{
	int i;
	for(i = 0; i < N; i++){
		printf("%d", num[i]);
		if(i != N - 1)
			printf(" ");
	}
	printf("\n");
}

void Init()
{
	scanf("%d", &N);
	int i, stack[N];
	char str[5];
	int preT, inT, top;
	preT = inT = top = -1;
	for(i = 0; i < 2 * N; i++){
		scanf("%s", str);
		if(str[1] == 'u'){
			scanf("%d", &pre[++preT]);
			stack[++top] = pre[preT];
		}else if(str[1] == 'o'){
			in[++inT] = stack[top--];
		}
	}
}

void SolveProblem(int preL, int inL, int postL, int pre[], int in[], int post[], int n)
{
	if(n == 1){
		post[postL] = pre[preL];
		return;
	}
	int root = pre[preL];
	post[postL] = root;
	int i;
	for(i = 0; i < N; i++)
		if(in[inL + i] == root)
			break;
	int leftLen = i;
	int rightLen = n - leftLen - 1;
	if(leftLen > 0)
		SolveProblem(preL + 1, inL, postL - rightLen - 1, pre, in, post, leftLen);
	if(rightLen > 0)
		SolveProblem(preL + leftLen + 1, inL + leftLen + 1, postL - 1, pre, in, post, rightLen);
}

void Solve()
{
	SolveProblem(0, 0, N - 1, pre, in, post, N);
	Print(post, N);
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}