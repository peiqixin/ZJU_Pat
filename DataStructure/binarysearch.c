//二分查找
#include <stdio.h>
#define MAX_SIZE 100
typedef struct TreeNode TNode;
struct TreeNode
{
	int data[MAX_SIZE];
	int top;
};
int SequentialSearch(TNode node, int e);
int main(int argc, char const *argv[])
{
	TNode list;
	list.top = 0;
	printf("please input a number(<=100):");
	int number;
	scanf("%d", &number);
	printf("please input data:");
	int i;
	for(i = 1; i <= number; i++){
		scanf("%d",&(list.data[i]));
		list.top++;
	}
	printf("input a number you want to find:");
	int findNumber;
	scanf("%d", &findNumber);
	int left = 1;
	int right = list.top;
	int mid;
	while(left <= right){
		mid = (int)(left + right) * 0.618;
		if(list.data[mid] > findNumber)
			right = mid - 1;
		else if(list.data[mid] < findNumber)
			left = mid + 1;
		else
			break;
	}
	printf("find %d's index is %d\n",list.data[mid],mid);
	return 0;
}
int SequentialSearch(TNode node, int e)
{
	node.data[0] = e;
	int i;
	for (i = node.top; node.data[i]!=e; i--);
	return i;
}