
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXTABLESIZE 100000

typedef int ElementType;

typedef enum{
	Legitimate, 
	Empty
} EntryType;
typedef struct HashEntry Cell;
struct HashEntry
{
	ElementType Element;
	EntryType Info;
};

typedef struct TblNode * HashTable;
struct TblNode
{
	int TableSize;
	Cell *Cells;
};

int NextPrime(int N);
HashTable CreateTable(int TableSize);
int Hash(int Key, HashTable H);
int Insert(HashTable H, int Key);

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	int i;
	HashTable H = CreateTable(N);
	int Position[M];
	int Key;
	for(i = 0; i < M; i++){
		scanf("%d", &Key);
		Position[i] = Insert(H, Key);
	}
	for(i = 0; i < M; i++){
		if(i != 0){
			if(Position[i] > -1){
				printf(" %d", Position[i]);
			}else
				printf(" -");
		}else{
			if(Position[i] != -1){
				printf("%d", Position[i]);
			}else
				printf("-");
		}
	}
	printf("\n");
	return 0;
}

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

HashTable CreateTable(int TableSize)
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Cells = malloc(sizeof(Cell) * H->TableSize);
	int i;
	for(i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;
	return H;
}

int Hash(int Key, HashTable H)
{
	return Key % H->TableSize;
}

int Insert(HashTable H, int Key)
{
	int pos = Hash(Key, H);
	if(H->Cells[pos].Info == Empty){
		H->Cells[pos].Element = Key;
		H->Cells[pos].Info = Legitimate;
		return pos;
	}else{
		int CNum = 0;
		int NewPos = pos;
		int visit[H->TableSize];
		int i;
		for(i = 0; i < H->TableSize; i++)
			visit[i] = 0;
		while(H->Cells[NewPos].Info != Empty){
			if(++CNum % 2){
				NewPos = pos + (CNum + 1)*(CNum + 1)/4;
				if(NewPos >= H->TableSize)
					NewPos = NewPos % H->TableSize;
			}else{
				NewPos = pos - CNum * CNum / 4;
				while(NewPos < 0)
					NewPos = NewPos + H->TableSize;
			}
			// if(H->Cells[NewPos].Info == Empty)
			// 	break;

			// if(visit[NewPos] == 0 && H->Cells[NewPos].Info != Empty){
			// 	visit[NewPos] = 1;
			// }else{ //改值被访问过 || H->Cells[NewPos].Info==Empty
			// 	NewPos = -1;
			// 	break;
			// }
			if(H->Cells[NewPos].Info != Empty){
				if(visit[NewPos] == 0)
					visit[NewPos] = 1;
				else{
					NewPos = -1;
					break;
				}
			}

		}
		if(NewPos > -1){
			H->Cells[NewPos].Element = Key;
			H->Cells[NewPos].Info = Legitimate;
			return NewPos;
		}else{
			return -1;
		}
	}
}