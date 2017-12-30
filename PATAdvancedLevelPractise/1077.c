#include <stdio.h>
#include <string.h>

int N;
char Strings[100][257];

void Init()
{
	scanf("%d\n", &N);
	int i;
	for(i = 0; i < N; i++)
		gets(Strings[i]);
}

void Solve()
{
	int i, commonLength = 0;
	int endFlag = 0;
	int length = strlen(Strings[0]);
	while(1)
	{
		if(commonLength == length) break;
		char c = Strings[0][length - 1 - commonLength];
		for(i = 1; i < N; i++)
		{
			if(c != Strings[i][strlen(Strings[i]) - commonLength - 1])
			{
				endFlag = 1;
				break;
			}
		}
		if(endFlag) break;
		commonLength++;
	}
	if(commonLength == 0)
		printf("nai\n");
	else
		printf("%s\n", Strings[0] + (strlen(Strings[0]) - commonLength));
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}