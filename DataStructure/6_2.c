// 06-图2 Saving James Bond - Easy Version
#include <stdio.h>
#include <math.h>
#define YES 1
#define NO 0
typedef struct TNode Coord;
struct TNode
{
	int x;
	int y;
};

void Init(int num[], int N);
double Distance(int x1,int y1, int x2, int y2);
int IsSafe(int x, int y, int d);

int main(int argc, char const *argv[])
{
	int N, D;
	scanf("%d %d", &N, &D);
	int i = 0;
	Coord Coords[N];
	for(; i < N; i++)
		scanf("%d %d", &Coords[i].x, &Coords[i].y);
	int visit[N];
	Init(visit, N);
	int stack[N];
	Init(stack, N);
	int top = -1;
	int x, y;
	x = y = 0;
	int flag = NO;

	int index;
	for(index = 0; index < N && visit[index] != 1; index++){
		i = index;
		while(top > -1 || (x ==0 && y == 0)){
			while(i < N){
				if(IsSafe(x, y, D)){
					flag = YES;
					break;
				}
				if(visit[i] != 1){
					if((x !=0 && y != 0) && (Distance(x, y, Coords[i].x, Coords[i].y) <= D)){
						stack[++top] = i;
						visit[i] = 1;
						x = Coords[i].x;
						y = Coords[i].y;
					}
					else if(x ==0 && y == 0 && (Distance(x, y, Coords[i].x, Coords[i].y) <= D + 15)){
						stack[++top] = i;
						visit[i] = 1;
						x = Coords[i].x;
						y = Coords[i].y;
					}
				}
				i++;
			}
			if(flag == YES)
				break;
			else{
				if(top > -1){
					i = stack[top--];
					x = Coords[i].x;
					y = Coords[i].y;
				}else{
					x = 0;
					y = 0;
					break;
				}
			}
		}
		if(flag == YES)
			break;
	}
	if(flag == YES)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

void Init(int num[], int N)
{
	int i;
	for(i = 0; i < N; i++)
		num[i] = 0;
}

double Distance(int x1,int y1, int x2, int y2)
{
	return (double)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int IsSafe(int x, int y, int d)
{
	if((50 - abs(x)) <= d || (50 - abs(y)) <= d )
		return YES;
	else
		return NO;
}