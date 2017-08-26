#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N1, N2, i;
	scanf("%d", &N1);
	long int num1[N1];
	for(i = 0; i < N1; i++)
		scanf("%ld", &num1[i]);
	scanf("%d", &N2);
	long int num2[N2];
	for(i = 0; i < N2; i++)
		scanf("%ld", &num2[i]);
	if(N1 == 0 && N2 ==0)
		return 0;
	if(N1 == 0){
		printf("%ld\n", num2[N2 / 2]);
		return 0;
	}
	if(N2 == 0){
		printf("%ld\n", num1[N1 / 2]);
		return 0;
	}

	int j;
	// median代表中位数前所需收入新数组的个数
	int median;
	if((N1 + N2) % 2){
		median = (N1 + N2) / 2;
	}else{
		median = (N1 + N2) / 2 - 1;
	}
	if(median == 0){
		if(num1[0] <= num2[0]){
			printf("%ld\n", num1[0]);
		}else{
			printf("%ld\n", num2[0]);
		}
		return 0;
	}
	int a_finished;
	a_finished = 0;
	i = j = 0;
	while((i + j) < median){
		if(num1[i] <= num2[j]){
			i++;
			// 如果i等于N1，则i将数组1的所有数据全部输入数组中，则此时中位数必定位于数组2中。
			if(i == N1){
				a_finished = 1;
				break;
			}
		}
		else{
			j++;
			if(j == N2)
				break;
		}
	}
	while((i + j) < median){
		if(a_finished) j++;
		else i++;
	}
	if(i < N1 && num1[i] <= num2[j])
		printf("%ld\n", num1[i]);
	else
		printf("%ld\n", num2[j]);
	return 0;
}