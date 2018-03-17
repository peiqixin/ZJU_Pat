#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef char String[61];
int main(int argc, char const *argv[])
{
	char Day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	String string[4];
	int i;
	for(i = 0; i < 4; i++)
		scanf("%s",string[i]);
	int length = strlen(string[0]);
	int secondFlag = 0;
	for(i = 0; i < length; i++)
	{

		if(isalnum(string[0][i]) && string[0][i] == string[1][i])
		{
			if('A' <= string[0][i] && string[0][i] <= 'G' && !secondFlag)
			{
				int weekIndex = (int)(string[0][i] - 'A');
				printf("%s ", Day[weekIndex]);
				secondFlag = 1;
				continue;
			}
			if(secondFlag)
			{
				if(string[0][i] >= 'A' && string[0][i] <= 'N'){
					printf("%d:", (int)(string[0][i] - 'A' + 10));
					break;
				}else if(string[0][i] >= '0' && string[0][i] <= '9'){
					printf("%02d:", (int)(string[0][i] - '0'));
					break;
				}
			}
		}
	}

	length = strlen(string[2]);
	for(i = 0; i < length; i++)
	{
		if(isalpha(string[2][i]) && string[2][i] == string[3][i]){
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}