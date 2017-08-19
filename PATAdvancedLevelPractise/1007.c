#include <stdio.h>
#include <string.h>

#define NIF -65536

void find_max_crossing_subarray(int num[], int low, int mid, int high, int max_list[])
{
	int left, right, left_sum_max, right_sum_max, left_sum, right_sum;
	int i;
	left_sum_max = right_sum_max = NIF;
	left_sum = right_sum = 0;
	for(i = mid; i >= low ; i--){
		left_sum += num[i];
		if(left_sum_max < left_sum){
			left_sum_max = left_sum;
			left = i;
		}
	}
	for(i = mid + 1; i <= high; i++){
		right_sum += num[i];
		if(right_sum_max < right_sum){
			right_sum_max = right_sum;
			right = i;
		}
	}
	max_list[0] = left;
	max_list[1] = right;
	max_list[2] = right_sum_max + left_sum_max;
}

void find_maximum_subarray(int num[], int low, int high, int max_list[])
{
	if(low == high){
		max_list[0] = low;
		max_list[1] = high;
		max_list[2] = num[low];
	}else{
		int left_max_list[3], right_max_list[3], crossing_max_list[3];
		int mid = (high + low) / 2;
		find_maximum_subarray(num, low, mid, left_max_list);
		find_maximum_subarray(num, mid + 1, high, right_max_list);
		find_max_crossing_subarray(num, low, mid, high, crossing_max_list);
		if(left_max_list[2] >= right_max_list[2] && left_max_list[2] >= crossing_max_list[2])
			memcpy(max_list, left_max_list, sizeof(int) * 3);
		else if(crossing_max_list[2] >= right_max_list[2])
			memcpy(max_list, crossing_max_list, sizeof(int) * 3);
		else
			memcpy(max_list, right_max_list, sizeof(int) * 3);
	}
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, num[N];
	for(i = 0; i < N; i++)
		scanf("%d", &num[i]);
	int max_list[3];
	find_maximum_subarray(num, 0, N - 1, max_list);
	if(max_list[2] >=0 )
		printf("%d %d %d\n", max_list[2], num[max_list[0]], num[max_list[1]]);
	else
		printf("%d %d %d\n", 0, num[0], num[N-1]);
	return 0;
}