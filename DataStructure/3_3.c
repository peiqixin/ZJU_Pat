#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30
#define ElementType int
#define Tree int
#define Null -1
struct TreeNode{
	int Left;
	int Right;
	ElementType Element;
}T[MAXSIZE];

Tree BuildTree(struct TreeNode T[], int N);
void solve(int preL, int inL, int postL, int n, int pre[], int in[], int post[]);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	BuildTree(T, N);
	return 0;
}

Tree BuildTree(struct TreeNode T[], int N)
{
	int i = 0;
	int x;
	char str[4]; 
	int Stack[N];
	int top = -1;
	int pre[N];
	int preTop = -1;
	int in[N];
	int inTop = -1;
	while(i < 2*N){
		scanf("%s", str);
		if(str[3] == 'h'){
			scanf("%d", &x);
			Stack[++top] = x;
			pre[++preTop] = x;
		}
		else{
			if(top>=0){
				in[++inTop] = Stack[top--];
			}
		}
		i++;
	}
	int post[N];
	for (i = 0; i < N; ++i)
		post[i] = 0;

	solve(0, 0, 0, N, pre, in, post);

	for (i = 0; i < N; ++i){
		if(i < N-1){
			printf("%d ", post[i]);
		}else{
			printf("%d\n", post[i]);
		}
	}
	return 1;
}

void solve(int preL, int inL, int postL, int n, int pre[], int in[], int post[])
{
	if(n == 0) return;
	if(n == 1){
		post[postL] = pre[preL];
		return;
	}
	int root;
	root = pre[preL];
	post[postL + n -1] = root;
	int i;
	for(i = 0; i < n; i++){
		if(in[inL + i] == root)
			break;
	}
	int L = i;
	int R = n - L - 1;
	solve(preL + 1, preL, postL, L, pre, in, post);
	solve(preL + L + 1, inL + L + 1, postL + L, R, pre, in, post);
}