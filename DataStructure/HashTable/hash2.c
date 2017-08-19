// 
#define KEYLENGTH 15
typedef char ElementType[KEYLENGTH + 1];
typedef int Index;

typedef struct LNode * PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode List;
typedef PtrToLNode Position;

typedef struct TblNode *HashTable;
struct TblNode
{
	int TableSize;
	List Heads;
}
