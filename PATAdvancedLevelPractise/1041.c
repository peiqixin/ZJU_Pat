#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, num[N];
	for(i = 0; i < N; i++)
		scanf("%d", &num[i]);
	int count[10001];
	memset(count, 0, sizeof(count));

	for(i = 0; i < N; i++)
		count[num[i]]++;
	for(i = 0; i < N; i++)
		if(count[num[i]] == 1){
			printf("%d\n", num[i]);
			break;
		}
	if(i == N)
		if(count[num[N - 1]] > 1)
			printf("None\n");
	return 0;
}