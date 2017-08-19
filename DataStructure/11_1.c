// 11-散列1 电话聊天狂人
/*
	给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

	输入格式:

	输入首先给出正整数NN（\le 10^5≤10
	​5
	​​ ），为通话记录条数。随后NN行，每行给出一条通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

	输出格式:

	在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

	输入样例:

	4
	13005711862 13588625832
	13505711862 13088625832
	13588625832 18087925832
	15005713862 13588625832
	输出样例:

	13588625832 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define KEYLENGTH 11
#define MAXD 5
#define MAXTABLESIZE 1000000

typedef char ElementType[KEYLENGTH + 1];
typedef int Index;
typedef struct LNode * PtrToLNode;

struct LNode
{
	ElementType Data;
	PtrToLNode Next;
	int Count;
};
typedef PtrToLNode List;
typedef PtrToLNode Position;

typedef struct TblNode *HashTable;
struct TblNode
{
	int TableSize;
	List Heads;
};

int NextPrime(int N);
HashTable CreateTable( int TableSize );
Position Find( HashTable H, ElementType Key );
void DestroyTable( HashTable H );
bool Insert( HashTable H, ElementType Key );
Index Hash(int Key, int P);
void ScanAndOutput(HashTable H);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	HashTable H;
	H = CreateTable(N * 2);
	int i;
	ElementType Key;
	for(i = 0; i < N; i++){
		scanf("%s", Key);
		Insert(H, Key);
		scanf("%s", Key);
		Insert(H, Key);
	}
	// Position P;
	// for(i = 0; i < H->TableSize; i++){
	// 	P = H->Heads[i].Next;
	// 	while(P){
	// 		printf("%d ", P->Count);
	// 		P = P->Next;
	// 	}
	// 	printf("\n");
	// }
	ScanAndOutput(H);
	DestroyTable(H);
	return 0;
}

/* 返回大于N且不超过MAXTABLESIZE的最小素数 */
int NextPrime(int N)
{
	int i, p = (N % 2)?(N + 2): (N + 1);
	while(p < MAXTABLESIZE){
		for(i = (int)sqrt(p); i > 2; i--){
			if(!(p % i)) break; 
		}
		if(i == 2) break;
		else p += 2;
	}
	return p;
}

HashTable CreateTable( int TableSize )
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (PtrToLNode)malloc(sizeof(struct LNode) * H->TableSize);
	for(i = 0; i < H->TableSize; i++){
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
		H->Heads[i].Count = 0;
	}

	return H;
}

Position Find( HashTable H, ElementType Key )
{
	Position P;
	Index Pos;
	Pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);
	P = H->Heads[Pos].Next;
	while(P && strcmp(P->Data, Key))
		P = P->Next;
	return P;
}

void DestroyTable( HashTable H )
{
	Index Pos;
	Position P, Tmp;
	for(Pos = 0; Pos < H->TableSize; Pos ++){
		P = H->Heads[Pos].Next;
		while(P){
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads);
	free(H);
}

bool Insert( HashTable H, ElementType Key )
{
	Position p, NewCell;
	Index pos;
	p = Find(H, Key);
	if(!p){
		NewCell = (PtrToLNode)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		NewCell->Count = 1;
		pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);
		NewCell->Next = H->Heads[pos].Next;
		H->Heads[pos].Next = NewCell;
		return true;
	}else{
		p->Count++;
		return false;
	}
}

Index Hash(int Key, int P)
{
	return Key%P;
}

void ScanAndOutput(HashTable H)
{
	int MaxCount, PCount;
	Index Pos;
	Position P;
	MaxCount = PCount = 0;
	ElementType MinPhone;
	for(Pos = 0; Pos < H->TableSize; Pos++){
		P = H->Heads[Pos].Next;
		while(P){
			if(P->Count > MaxCount){
				MaxCount = P->Count;
				PCount = 1;
				strcpy(MinPhone, P->Data);
			}else if(P->Count == MaxCount){
				PCount++;
				if(strcmp(MinPhone, P->Data) > 0)
					strcpy(MinPhone, P->Data);
			}
			P = P->Next;
		}
	}
	printf("%s %d", MinPhone, MaxCount);
	if(PCount > 1) printf(" %d", PCount);
	printf("\n");
}