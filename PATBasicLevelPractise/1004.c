#include <stdio.h>

typedef char Name[11];
typedef char SNumber[11];

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);

	Name Names[N];
	SNumber SNumbers[N];
	int Score[N];
	int i;
	for(i = 0; i < N; i++){
		scanf("%s %s %d", Names[i], SNumbers[i], &Score[i]);
	}

	int Max, Min;
	int MaxScore, MinSocre;
	MaxScore = 0;
	MinSocre = 100;
	
	for(i = 0; i < N; i++){
		if(Score[i] > MaxScore){
			MaxScore = Score[i];
			Max = i;
		}
		if(Score[i] < MinSocre){
			MinSocre = Score[i];
			Min = i;
		}
	}
	printf("%s %s\n", Names[Max], SNumbers[Max]);
	printf("%s %s\n", Names[Min], SNumbers[Min]);
	return 0;
}