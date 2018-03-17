#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
	int childNum;
	int* child;
	double amount;
}chain[100000];

int n;
double p, r, sum = 0;

void dfs(int root, int lvl)
{
	if(chain[root].childNum == 0)
		sum += pow(1.0 + r * 0.01, lvl) * chain[root].amount;
	for(int i = 0; i < chain[root].childNum; i++)
		dfs(chain[root].child[i], lvl + 1);
}

int main(int argc, char const *argv[])
{
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		if(m)
		{
			chain[i].childNum = m;
			chain[i].child = (int*)malloc(sizeof(int) * m);
			for(int j = 0; j < m; j++)
			{
				int c;
				scanf("%d", &c);
				chain[i].child[j] = c;
			}
		}
		else
		{
			chain[i].childNum = 0;
			scanf("%lf", &chain[i].amount);
		}
	}
	dfs(0, 0);
	printf("%.1lf\n", sum * p);
	return 0;
}