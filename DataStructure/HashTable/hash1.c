// 开放地址法
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXTABLESIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;
typedef enum{
	Legitimate,
	Empty,
	Deleted
} EntryType;

typedef struct HashEntry Cell;
struct HashEntry
{
	ElementType Element;
	EntryType Info;
};

typedef struct TblNode *HashTable;
struct TblNode
{
	int TableSize;
	Cell *Cells;
};

/* 返回大于N且不超过MAXTABLESIZE的最小素数 */
int Prime(int N)
{
	int i, p = (N % 2):N + 2: N + 1;
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
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = Prime(TableSize);
	H->Cells = (Cell)malloc(sizeof(Cell) * H->TableSize);
	for(i = 0; i < H->TableSize; i++)
		H->Cells[i].EntryType = Legitimate;
	return H;
}