#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
// 四种排序规则， sages: 两个成绩都高于H nobleman：
//             virtue： 高于H， 但talent低于H
//             fool man： 两个成绩都低于H，但是virtue不低于talent
//             after fool man ： 两个成绩都高于L， 但不满足上述条件

typedef struct
{
	char name[9];
	int virtue, talent;
} StuNode;

int cmp(const void *a, const void *b)
{
	StuNode *sta = (StuNode *)a;
	StuNode *stb = (StuNode *)b;
	if((sta->virtue + sta->talent) != (stb->virtue + stb->talent))
		return  ((stb->virtue + stb->talent) > (sta->virtue + sta->talent)); // desc
	else if(sta->virtue != stb->virtue)
		return (stb->virtue > sta->virtue);  // desc
	else if(sta->talent != stb->talent)
		return (stb->talent > sta->talent);
	else
		return strcmp(sta->name, stb->name); // asc
}

void Print(StuNode list[], int count)
{
	int i;
	for(i = 0; i < count; i++)
		printf("%s %d %d\n", list[i].name, list[i].virtue, list[i].talent);
}

int main(int argc, char const *argv[])
{
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);

	StuNode stuList1[N], stuList2[N], stuList3[N], stuList4[N];
	int count1, count2, count3, count4;
	count1 = count2 = count3 = count4 = 0;
	int i, count = 0;
	int virtue, talent;
	for(i = 0; i < N; i++){
		StuNode newStu;
		scanf("%s %d %d", newStu.name, &virtue, &talent);
		if(virtue < L || talent < L){
			continue;
		}else{
			count++;
			newStu.virtue = virtue;
			newStu.talent = talent;
			if(virtue >= H && talent >= H)
				stuList1[count1++] = newStu;
			else if(virtue >= H && talent < H)
				stuList2[count2++] = newStu;
			else if(virtue >= talent)
				stuList3[count3++] = newStu;
			else
				stuList4[count4++] = newStu;
		}
	}

	qsort(stuList1, count1, sizeof(StuNode), cmp);
	qsort(stuList2, count2, sizeof(StuNode), cmp);
	qsort(stuList3, count3, sizeof(StuNode), cmp);
	qsort(stuList4, count4, sizeof(StuNode), cmp);
	printf("%d\n", count);
	Print(stuList1, count1);
	Print(stuList2, count2);
	Print(stuList3, count3);
	Print(stuList4, count4);

	return 0;
}