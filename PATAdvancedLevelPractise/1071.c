#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// 第四个测试点没通过
typedef struct WordNode *PtrToWord;
typedef PtrToWord WordList;
typedef PtrToWord Word;
struct WordNode
{
	char word[20];
	int count;
	Word next;
	Word pre;
};

WordList Insert(WordList list, char word[])
{
	if(!list){
		list = (WordList)malloc(sizeof(struct WordNode));
		list->count = 1;
		strcpy(list->word, word);
		list->next = NULL;
		list->pre = NULL;
		return list;
	}
	Word ptr = list;
	while(ptr){
		if(strcmp(ptr->word, word) == 0){
			ptr->count++;
			while(ptr->pre && ptr->count > ptr->pre->count){
				Word pre = ptr->pre;
				ptr->pre->next = ptr->next;
				if(ptr->next)
					ptr->next->pre = ptr->pre;
				ptr->pre = ptr->pre->pre;
				if(ptr->pre)
					ptr->pre->next = ptr;
				else{
					list = ptr;
					ptr->next = pre;
				}
			}
			break;
		}else{
			if(ptr->next == NULL){
				Word newWord = (Word)malloc(sizeof(struct WordNode));
				newWord->count = 1;
				strcpy(newWord->word, word);
				newWord->next = NULL;
				newWord->pre = ptr;
				ptr->next = newWord;
				break;
			}else
				ptr = ptr->next;
		}
	}
	return list;
}

Word FindMax(WordList list[])
{
	Word maxWord = NULL;
	int Maxcount = 0;
	int i;
	for(i = 0; i < 26; i++)
	{
		if(list[i] && list[i]->count > Maxcount){
			maxWord = list[i];
			Maxcount = maxWord->count;
		}
	}
	return maxWord;
}

int main(int argc, char const *argv[])
{
	char str[1048578];
	gets(str);
	int length = strlen(str);
	int i;
	for(i = 0; i < length; i++){
		if(!isalnum(str[i]))
			str[i] = ' ';
		else if(isalpha(str[i]))
			str[i] = tolower(str[i]);
	}
	WordList list[26];
	for(i = 0; i < 26; i++)
		list[i] = NULL;
	for(i = 0; i < length; i++)
	{
		char word[20];
		int count = 0;
		if(str[i] == ' ')
			continue;
		while(str[i] != ' ' && i < length)
			word[count++] = str[i++];
		word[count] = '\0';
		if(isalpha(word[0]) && count > 0){
			list[word[0] - 'a'] = Insert(list[word[0] - 'a'], word);
		}
	}
	WordList MaxWord = FindMax(list);
	printf("%s %d\n", MaxWord->word, MaxWord->count);
	return 0;
}