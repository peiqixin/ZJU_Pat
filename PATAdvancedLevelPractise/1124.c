#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int M, N, S;
	scanf("%d %d %d", &M, &N, &S);
	char Forwards[M][21];
	int i;
	for(i  = 0; i < M; i++)
		scanf("%s", Forwards[i]);
	int Stack[N], Top = -1;
	S--;
	while(S < M)
	{
		int j, flag = 1;
		for(j = 0; j <= Top; j++)
			if(strcmp(Forwards[Stack[j]], Forwards[S]) == 0)
			{
				flag = 0;
				break;
			}
		if(flag)
		{
			Stack[++Top] = S;
			S += N;
		}
		else
			S++;
	}
	if(Top >= 0)
		for(i = 0; i <= Top; i++)
			printf("%s\n", Forwards[Stack[i]]);
	else
		printf("Keep going...\n");
	return 0;
}