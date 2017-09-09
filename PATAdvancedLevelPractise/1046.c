#include <stdio.h>
int N, M;
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int distance[N], i, total, sum[N];
	total = 0;
	for(i = 0; i < N; i++){
		sum[i] = total;
		scanf("%d", &distance[i]);
		total += distance[i];
	}
	scanf("%d", &M);
	int pair[M][2];
	for(i = 0; i < M; i++)
		scanf("%d %d", &pair[i][0], &pair[i][1]);
	int shortest[M];
	for(i = 0; i < M; i++){
		int start, end;
		start = pair[i][0]<pair[i][1] ? pair[i][0] : pair[i][1];
		end = pair[i][0]>=pair[i][1] ? pair[i][0] : pair[i][1];
		int d1 = sum[end - 1] - sum[start - 1];
		int d2 = total - d1;
		shortest[i] = d1 <= d2 ? d1 : d2;
	}
	for(i = 0; i < M; i++)
		printf("%d\n", shortest[i]);
	return 0;
}