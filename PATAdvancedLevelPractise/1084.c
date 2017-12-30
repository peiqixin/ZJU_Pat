#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char origin[81], typeOut[81];
int wornOutTable[128];

void Init()
{
	gets(origin);
	gets(typeOut);
	memset(wornOutTable, 0, sizeof(int) * 128);
}

void Solve()
{
	int i, j;
	for(i = 0; i < strlen(origin); i++)
		if(isalpha(origin[i]))
			origin[i] = toupper(origin[i]);
	for(j = 0; j <strlen(typeOut); j++)
		if(isalpha(typeOut[j]))
			typeOut[j] = toupper(typeOut[j]);
	for(i = 0, j = 0; i < strlen(typeOut); i++, j++){
		while(typeOut[i] != origin[j]){
			if(wornOutTable[(int)origin[j]] != 1){
				wornOutTable[(int)origin[j]] = 1;
				printf("%c", origin[j]);
			}
			j++;
		}
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}