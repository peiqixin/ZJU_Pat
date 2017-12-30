#include <stdio.h>
#define INF 0x7fff
int N, M, S, Des;

int Distance[500][500];
int Cost[500][500];
int Visit[500];

void Init()
{
	scanf("%d %d %d %d", &N, &M, &S, &Des);
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			Distance[i][j] = INF;
	for(i = 0; i < M; i++)
	{
		int v1, v2, d, c;
		scanf("%d %d %d %d", &v1, &v2, &d, &c);
		Distance[v1][v2] = Distance[v2][v1] = d;
		Cost[v1][v2] = Cost[v2][v1] = c;
	}
}

int FindMin(int D[])
{
	int Min, MinWeight, i;
	MinWeight = INF;
	for(i = 0; i < N; i++)
		if(!Visit[i] && D[i] < MinWeight)
		{
				Min = i;
				MinWeight = D[i];
		}
	if(MinWeight < INF)
		return Min;
	else
		return -1;
}

void Dijstra()
{
	int Path[N], D[N], C[N];
	int i;
	for(i = 0; i < N; i++)
	{
		Visit[i] = 0;
		D[i] = Distance[S][i];
		if(Distance[S][i] < INF)
		{
			Path[i] = S;
			C[i] = Cost[S][i];
		}
		else
		{
			Path[i] = -1;
			C[i] = INF;
		}
	}
	Visit[S] = 1;
	Path[S] = -1;
	D[S] = 0;
	C[S] = 0;
	while(1)
	{
		int v = FindMin(D);
		if(v == -1) break;
		Visit[v] = 1;
		int w;
		for(w = 0; w < N; w++)
		{
			if(!Visit[w] && Distance[v][w] < INF)
			{
				if(D[w] > D[v] + Distance[v][w])
				{
					D[w] = D[v] + Distance[v][w];
					Path[w] = v;
					C[w] = C[v] + Cost[v][w];
				}
				else if(D[w] == D[v] + Distance[v][w] && C[w] > C[v] + Cost[v][w])
				{
					Path[w] = v;
					C[w] = C[v] + Cost[v][w];
				}
			}
		}
	}
	int stack[N], top = -1;
	int des = Des;
	while(Des != -1)
	{
		stack[++top] = Des;
		Des = Path[Des];
	}
	for(i = top; i >= 0; i--)
		printf("%d ", stack[i]);
	printf("%d %d\n", D[des], C[des]);
}

int main(int argc, char const *argv[])
{
	Init();
	Dijstra();
	return 0;
}