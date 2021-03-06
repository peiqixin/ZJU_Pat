#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct str_node* ptr_str_node;
struct str_node
{
	char string[9];
};

void trim(char str[])
{
	int len = strlen(str);
	int o_count = 0;
	int i = 0;
	while(str[i] == '0'){
		o_count++;
		i++;
	}
	if(o_count == 0) return;
	for(i = 0; i < len - o_count; i++)
		str[i] = str[i + o_count];
	str[i] = '\0';
}

int cmp(const void* sta, const void* stb)
{
	int la = strlen(((ptr_str_node)sta)->string);
	int lb = strlen(((ptr_str_node)stb)->string);
	int i, j;
	for(i = 0, j = 0; i < la && j < lb; i++, j++)
		if(((ptr_str_node)sta)->string[i] != ((ptr_str_node)stb)->string[j])
			return ((ptr_str_node)sta)->string[i] - ((ptr_str_node)stb)->string[j];
	
	if(j < lb)  // a是b的前缀
	{
		i = 0;
		while(j < lb)
		{
			if(((ptr_str_node)stb)->string[i] != ((ptr_str_node)stb)->string[j])
				return ((ptr_str_node)stb)->string[i] - ((ptr_str_node)stb)->string[j];
			i++;
			j++;
		}
	}
	if(i < la)  // b是a的前缀
	{
		j = 0;
		while(i < la)
		{
			if(((ptr_str_node)sta)->string[i] != ((ptr_str_node)sta)->string[j])
				return ((ptr_str_node)sta)->string[i] - ((ptr_str_node)sta)->string[j];
			i++;
			j++;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	struct str_node str_list[N];
	int i;
	for(i = 0; i < N; i++){
		scanf("%s", str_list[i].string);
	}
	qsort(str_list, N, sizeof(struct str_node), cmp);
	int trim_flag = 1;
	for(i = 0; i < N; i++){
		if(trim_flag) trim(str_list[i].string);
		if(str_list[i].string[0] != '\0'){
			printf("%s", str_list[i].string);
			trim_flag = 0;
		}else if(i == N - 1 && str_list[i].string[0] == '\0'){
			printf("0");
		}else{
			trim_flag = 1;
		}
	}
	printf("\n");
	return 0;
}