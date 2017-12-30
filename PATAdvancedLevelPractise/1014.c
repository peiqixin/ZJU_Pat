#include <stdio.h>
int N, M, K, Q, Process[1001], Query[1001], LeaveTime[1001];

struct QueueNode
{
  int queue[10]; // 存放客户序号
  int top, rear;
  int ServeTime; // 存放下一个客户到达时的服务时间，初始化为8点
} Windows[20];

void Init()
{
  scanf("%d %d %d %d", &N, &M, &K, &Q);
  int i;
  for(i = 1; i <= K; i++)
    scanf("%d", &Process[i]);
  for(i = 0; i < Q; i++)
    scanf("%d", &Query[i]);
  for(i = 0; i < N; i++)
  {
    Windows[i].top = Windows[i].rear = -1;
    Windows[i].ServeTime = 480; //代表早上8点
  }
}

int FindSuitableWindow()
{
  int i, minWindow, mostFirstLeaveCustom;
  mostFirstLeaveCustom = Windows[0].queue[(Windows[0].rear + 1) % M];
  minWindow = 0;
  for(i = 1; i < N; i++)
  {
    int custom = Windows[i].queue[(Windows[i].rear + 1) % M];
    // 查找当前所有窗口中最先离开的客户及窗口
    if(LeaveTime[custom] < LeaveTime[mostFirstLeaveCustom])
    {
      mostFirstLeaveCustom = custom;
      minWindow = i;
    }
  }
  return minWindow;
}

void Solve()
{
  int i;
  for(i = 1; i <= K && i <= N * M; i++)
  {
    int window = (i - 1) % N;
    Windows[window].queue[++Windows[window].top] = i;
    LeaveTime[i] = Process[i] + Windows[window].ServeTime;
    Windows[window].ServeTime = LeaveTime[i];
  }

  for(; i <= K; i++)
  {
    // 查询最适合的窗口
    int suitableW = FindSuitableWindow();
    // 该窗口的第一个客户离开队列
    Windows[suitableW].rear++;
    Windows[suitableW].rear = Windows[suitableW].rear % M;
    // 该客户进入队列
    Windows[suitableW].top++;
    Windows[suitableW].top = Windows[suitableW].top % M;
    Windows[suitableW].queue[Windows[suitableW].top] = i;
    // 更新当前客户离开时间
    LeaveTime[i] = Process[i] + Windows[suitableW].ServeTime;
    // 更新当前窗口时间为该客户离开时间
    Windows[suitableW].ServeTime = LeaveTime[i];
  }

  for(i = 0; i < Q; i++)
    if(LeaveTime[Query[i]] - Process[Query[i]] < 17 * 60)
      printf("%02d:%02d\n", LeaveTime[Query[i]] / 60, LeaveTime[Query[i]] % 60);
    else
      printf("Sorry\n");
}

int main(int argc, char const *argv[])
{
  Init();
  Solve();
  return 0;
}