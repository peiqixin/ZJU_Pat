#include <stdio.h>
#include <string.h>
#define INF 0x7f7f7f7f

int N, M, S, destination;
int Distance[500][500];
int Time[500][500];

void Init()
{
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			Distance[i][j] = INF;
			Time[i][j] = INF;
		}
	for(int i = 0; i < M; i++)
	{
		int v1, v2, one, len, time;
		scanf("%d %d %d %d %d", &v1, &v2, &one, &len, &time);
		Distance[v1][v2] = len;
		Time[v1][v2] = time;
		if(one != 1)
		{
			Distance[v2][v1] = len;
			Time[v2][v1] = time;
		}
	}
	scanf("%d %d", &S, &destination);
}

int FindMin(int D[], int Visit[])
{
	int Min, MinWeight = INF;
	for(int i = 0; i < N; i++)
		if(!Visit[i] && MinWeight > D[i])
		{
			MinWeight = D[i];
			Min = i;
		}
	if(MinWeight < INF)
		return Min;
	else
		return -1;
}

int Dijkstra_Length(int Path[])
{
	int i, Auxiliary[N], Visit[N], Weight[N];
	for(i = 0; i < N; i++)
	{
		Visit[i] = 0;
		Weight[i] = INF;
		Auxiliary[i] = 0;
	}
	Path[S] = -1;
	Weight[S] = 0;
	while(1)
	{
		int v = FindMin(Weight, Visit);
		if(v == -1) break;
		Visit[v] = 1;
		
		for(int w = 0; w < N; w++)
		{
			if(!Visit[w])
			{
				if(Weight[w] > Weight[v] + Distance[v][w] || 
				(Weight[w] == Weight[v] + Distance[v][w] && Auxiliary[w] > Auxiliary[v] + Time[v][w]))
				{
					Weight[w] = Weight[v] + Distance[v][w];
					Auxiliary[w] = Auxiliary[v] + Time[v][w];
					Path[w] = v;
				}
			}
		}
	}
	return Weight[destination];
}

int Dijkstra_Time(int Path[])
{
	int i, Auxiliary[N], Visit[N], Weight[N];
	for(i = 0; i < N; i++)
	{
		Visit[i] = 0;
		Weight[i] = INF;
		Auxiliary[i] = 0;
	}
	Path[S] = -1;
	Weight[S] = 0;
	while(1)
	{
		int v = FindMin(Weight, Visit);
		if(v == -1) break;
		Visit[v] = 1;
		
		for(int w = 0; w < N; w++)
		{
			if(!Visit[w])
			{
				if(Weight[w] > Weight[v] + Time[v][w] || 
				(Weight[w] == Weight[v] + Time[v][w] && Auxiliary[w] > Auxiliary[v] + 1))
				{
					Weight[w] = Weight[v] + Time[v][w];
					Auxiliary[w] = Auxiliary[v] + 1;
					Path[w] = v;
				}
			}
		}
	}
	return Weight[destination];
}

int IsSame(int A[], int B[], int n)
{
	for(int i = 0; i < n; i++)
		if(A[i] != B[i])
			return 0;
	return 1;
}

void Print(int num[], int n)
{
	for(int i = n; i >= 0; i--)
		printf(" -> %d", num[i]);
	printf("\n");
}

void Solve()
{
	int Path[N], Path_Time[N];
	int Dis = Dijkstra_Length(Path); // update length
	int Tim = Dijkstra_Time(Path_Time); // update time

	int Dis_S[N], Time_S[N], top1, top2;
	top1 = top2 = -1;
	int Des = destination;
	while(Path[Des] != -1)
	{
		Dis_S[++top1] = Des;
		Des = Path[Des];
	}
	Des = destination;
	while(Path_Time[Des] != -1)
	{
		Time_S[++top2] = Des;
		Des = Path_Time[Des];
	}
	if(IsSame(Dis_S, Time_S, top1))
	{
		printf("Distance = %d; Time = %d: %d", Dis, Tim, S);
		Print(Dis_S, top1);
	}
	else
	{
		printf("Distance = %d: %d", Dis, S);
		Print(Dis_S, top1);
		printf("Time = %d: %d", Tim, S);
		Print(Time_S, top2);
	}
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}
