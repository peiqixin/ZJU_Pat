
typedef int DataType;
typedef struct LinkedListNode *PtrToLinkedListNode;
typedef PtrToLinkedListNode LinkedList;
struct LinkedListNode
{
	PtrToLinkedListNode next;
	DataType data;
};

void insert_front(LinkedList list, int data);
LinkedList create_linkedlist();