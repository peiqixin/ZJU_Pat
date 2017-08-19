// 04-树6 Complete Binary Search Tree
/*********
	A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
	Both the left and right subtrees must also be binary search trees.
	A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

	Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

	Input Specification:

	Each input file contains one test case. For each case, the first line contains a positive integer NN (\le 1000≤1000). Then NN distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

	Output Specification:

	For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

	Sample Input:

	10
	1 2 3 4 5 6 7 8 9 0
	Sample Output:

	6 3 8 1 5 7 9 0 2 4
*********/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b);
void Init(int num[], int N);
int GetLeftLength(int n);
void Solve(int ALeft, int ARight, int TRoot, int T[], int A[]);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i = 0;
	int A[N];
	while(i < N){
		scanf("%d", &A[i]);
		i++;
	}
	qsort(A, N, sizeof(int), compare);

	int T[N];
	Init(T, N);

	Solve(0, N-1, 0, T, A);

	i = 0;
	while(i < N){
		if(i > 0)
			printf(" %d", T[i]);
		else
			printf("%d", T[i]);
		i++;
	}
	printf("\n");
	return 0;
}

int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void Init(int num[], int N)
{
	int i = 0;
	while(i < N){
		num[i] = 0;
		i++;
	}
}

void Solve(int ALeft, int ARight, int TRoot, int T[], int A[])
{
	int n, L;
	n = ARight - ALeft + 1;
	if(n == 0) return;
	L = GetLeftLength(n);
	T[TRoot] = A[ALeft + L];
	int LeftRoot = TRoot * 2 + 1;
	int RightRoot = LeftRoot + 1;
	Solve(ALeft, ALeft + L -1, LeftRoot, T, A);
	Solve(ALeft + L + 1, ARight, RightRoot, T, A);
}

int GetLeftLength(int length)
{
	int n = 0;
	int l = length;
	while(length > 1){
		length /= 2;
		n++;
	}
	int x = l - pow(2, n) + 1;
	if(x > pow(2, n-1))
		l = pow(2, n-1);
	else
		l = x;
	l = l + pow(2, n-1) - 1;
	return l;
}