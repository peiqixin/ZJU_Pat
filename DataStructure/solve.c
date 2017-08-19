/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
#include <stdio.h>
void solve(int preL, int inL, int postL, int n, int pre[], int in[], int post[]);
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int post[N], in[N];
	int i;
	for(i = 0; i < N; i++)
		scanf("%d", &post[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &in[i]);

	int pre[N];

	solve(0, 0, N - 1, N, pre, in, post);

	printf("Preorder:");
	for (i = 0; i < N; ++i){
		printf(" %d", pre[i]);
	}
	printf("\n");
	return 1;

	return 0;
}

void solve(int preL, int inL, int postL, int n, int pre[], int in[], int post[])
{
	if(n == 0) return;
	if(n == 1){
		pre[preL] = post[postL];
		printf("root=%d\n", post[postL]);
		return;
	}

	int root;
	root = post[postL];

	pre[preL] = root;
	printf("root=%d\n", root);

	int i;
	for(i = 0; i < n; i++){
		if(in[inL + i] == root)
			break;
	}
	int L = i;
	int R = n - L - 1;
	solve(preL + 1, preL, postL - R - 1, L, pre, in, post);
	solve(preL + L + 1, inL + L + 1, postL - 1, R, pre, in, post);
}