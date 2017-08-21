#include <stdio.h>
#include <string.h>
char str[20];
void double_str(char str[], int* overflow_flag, char new_str[])
{
	int length = strlen(str);
	int i;
	for(i = length - 1; i >= 0; i--){
		int res = (str[i] - 48) * 2;
		if(res >= 10){
			new_str[i] = (char)(res % 10 + 48);
			if(*overflow_flag)
				new_str[i] += 1;
			*overflow_flag = 1;
		}else{
			new_str[i] = (char)(res + 48);
			if(*overflow_flag)
				new_str[i] += 1;
			*overflow_flag = 0;
		}
	}
}
int consists(char str[], char str_double[], int overflow_flag)
{
	int length = strlen(str);
	int i;
	int visit[10];
	memset(visit, 0, sizeof(visit));
	for(i = 0; i < length; i++){
		int index = (int)str[i] - 48;
		if(visit[index] == 0)
			visit[index] = 1;
	}
	for(i = 0; i < length; i++){
		int index = (int)str_double[i] - 48;
		visit[index] = visit[index] + 1;
	}
	if(overflow_flag)
		visit[1]++;
	for(i = 0; i < 10; i++)
		if(visit[i] == 1)
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	scanf("%s", str);
	char str_double[20];
	int overflow_flag = 0;
	double_str(str, &overflow_flag, str_double);
	if(consists(str, str_double, overflow_flag))
		printf("Yes\n");
	else
		printf("No\n");
	if(overflow_flag)
		printf("1");
	int length = strlen(str);
	int i;
	for(i = 0; i < length; i++)
		printf("%c", str_double[i]);
	printf("\n");
	return 0;
}