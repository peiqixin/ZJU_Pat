#include <stdio.h>
#include <string.h>
struct stu_node
{
	char id[11];
	char passwd[11];
};
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	struct stu_node stu_list[N];
	int i;
	for(i = 0; i < N; i++){
		scanf("%s %s", stu_list[i].id, stu_list[i].passwd);
	}
	int mdf_num = 0;
	int len, mdf_flg;
	int stack[N];
	int top = -1;
	for(i = 0; i < N; i++){
		len = strlen(stu_list[i].passwd);
		mdf_flg = 0;
		int j;
		for(j = 0; j < len; j++){
			char ch =  stu_list[i].passwd[j];
			if(ch == '1'){
				stu_list[i].passwd[j] = '@';
				mdf_flg = 1;
			}else if(ch == '0'){
				stu_list[i].passwd[j] = '%';
				mdf_flg = 1;
			}else if(ch == 'l'){
				stu_list[i].passwd[j] = 'L';
				mdf_flg = 1;
			}else if(ch == 'O'){
				stu_list[i].passwd[j] = 'o';
				mdf_flg = 1;
			}
		}
		if(mdf_flg){
			mdf_num++;
			stack[++top] = i;
		}
	}
	if(mdf_num == 0){
		if(N != 1)
			printf("There are %d accounts and no account is modified\n", N);
		else
			printf("There is 1 account and no account is modified\n");
	}else{
		printf("%d\n", top + 1);
		for(i = 0; i <= top; i++)
			printf("%s %s\n", stu_list[stack[i]].id, stu_list[stack[i]].passwd);
	}
	return 0;
}