#include <stdio.h>
#define END -1
#define MAX 100000
struct word_node
{
	int next;
	char data;
};
int list_length(struct word_node word_list[], int start, int length)
{
	int len = 0;
	while(start != END){
		start = word_list[start].next;
		len++;
	}
	return len;
}
int main(int argc, char const *argv[])
{
	int start1, start2, N;
	scanf("%d %d %d",&start1, &start2, &N);
	int i, index;
	struct word_node word_list[MAX];
	for(i = 0; i < N; i++){
		scanf("%d", &index);
		scanf(" %c %d", &word_list[index].data, &word_list[index].next);
	}
	// 字符串1的长度
	int len1 = list_length(word_list, start1, N);
	// 字符串2的长度
	int len2 = list_length(word_list, start2, N);
	// 字符串1大于字符串2的长度时，将start1向后移动len1-len2个长度
	if(len1 > len2){
		int n = len1 - len2;
		for(i = 0; i < n && start1 != END; i++)
			start1 = word_list[start1].next;
	}else if(len2 > len1){
		int n = len2 - len1;
		for(i = 0; i < n && start2 != END; i++)
			start2 = word_list[start2].next;
	}
	int common_address = -1;
	while(start1 != END && start2 != END){
		if(start1 == start2){
			common_address = start1;
			break;
		}
		start1 = word_list[start1].next;
		start2 = word_list[start2].next;
	}
	if(common_address != END){
		printf("%05d\n", common_address);
	}else{
		printf("%d\n", common_address);
	}
	return 0;
}