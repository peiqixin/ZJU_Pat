#include <stdio.h>
#include <stdlib.h>
#define N_Inf -10000
typedef struct Node* NNode;
struct Node{
	int left;
	int right;
	int sum;
};

NNode Find_Max_Crossing_Subarray(int A[], int low, int mid, int high);
NNode Find_Maximum_Subarray(int A[], int low, int high);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[N], i;
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	NNode PtrToNode = Find_Maximum_Subarray(A, 0, N-1);
	printf("left->%d, right->%d, sum->%d\n", PtrToNode->left, PtrToNode->right, PtrToNode->sum);
	return 0;
}

NNode Find_Max_Crossing_Subarray(int A[], int low, int mid, int high)
{	
	NNode N = (NNode)malloc(sizeof(struct Node));
	int left_Sum, sum, right_Sum;
	int i, max_Left, max_Right;
	left_Sum = right_Sum = N_Inf;
	sum = 0;
	for(i = mid; i > low; i--){
		sum += A[i];
		if(left_Sum < sum){
			left_Sum = sum;
			max_Left = i;
		}
	}
	sum = 0;
	for(i = mid + 1; i < high; i++){
		sum += A[i];
		if(right_Sum < sum){
			right_Sum = sum;
			max_Right = i;
		}
	}
	N->left = max_Left;
	N->right = max_Right;
	N->sum = left_Sum + right_Sum;
	return N;
}	

NNode Find_Maximum_Subarray(int A[], int low, int high)
{
	if(high == low){
		NNode N = (NNode)malloc(sizeof(struct Node));
		N->left = low;
		N->right = high;
		N->sum = A[low];
		return N;
	}
	else{
		int mid;
		mid = (low + high) / 2;
		NNode Left_Num, Right_Num, Crossing_Num;
		Left_Num = Find_Maximum_Subarray(A, low, mid);
		Right_Num = Find_Maximum_Subarray(A, mid + 1, high);
		Crossing_Num = Find_Max_Crossing_Subarray(A, low, mid, high);
		if(Left_Num->sum >= Right_Num->sum && Left_Num->sum >= Crossing_Num->sum){
			return Left_Num;
		}
		else if(Right_Num->sum > Left_Num->sum && Right_Num->sum > Crossing_Num->sum){
			return Right_Num;
		}
		else{
			return Crossing_Num;
		}
	}
}