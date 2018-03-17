#include <stdio.h>
#define MAX 10001
// 最后一个测试点未通过
typedef struct SetNode
{
	int elements[MAX];
	int size;
} Set;
// InsertionSort
void Insert(Set *s, int ele)
{
	int i = s->size;
	if(s->elements[i] < ele)
	{
		s->elements[i + 1] = ele;
		s->size++;
	}
	else if(s->elements[i] == ele) // 如果相同则直接返回
		return;
	else
	{
		for(i = i + 1; i > 0; i--)
		{
			if(s->elements[i - 1] > ele)
				s->elements[i] = s->elements[i - 1];
			else if(s->elements[i - 1] == ele)
				return;
			else 
				break;
		}
		s->elements[i] = ele;
		s->size++;
	}
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d", &N);
	Set S[N];
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &M);
		S[i].size = 0;
		S[i].elements[0] = -1; // shao bing
		for(j = 0; j < M; j++)
		{
			int ele;
			scanf("%d", &ele);
			Insert(&S[i], ele);
		}
	}
	int K;
	scanf("%d", &K);
	for(i = 0; i < K; i++)
	{
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		s1--;
		s2--;
		j = k = 1;
		int sameCount = 0;
		while(j <= S[s1].size && k <= S[s2].size)
		{
			if(S[s1].elements[j] < S[s2].elements[k])
				j++;
			else if(S[s1].elements[j] > S[s2].elements[k])
				k++;
			else
			{
				j++;
				k++;
				sameCount++;
			}
		}
		printf("%0.1f%%\n", (float)sameCount / (S[s1].size + S[s2].size - sameCount) * 100);
	}
	return 0;
}