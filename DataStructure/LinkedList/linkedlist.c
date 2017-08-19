#include "linkedlist.h"
void insert_front(LinkedList list, int data)
{
	PtrToLinkedListNode newNode;
	if (list != NULL)
	{
		newNode = (PtrToLinkedListNode)malloc(sizeof(struct ToLinkedListNode));
		newNode->data = data;
		newNode->next = list->next;
		list->next = newNode;
	}
}

LinkedList create_linkedlist()
{
	PtrToLinkedListNode head;
	head = (PtrToLinkedListNode)malloc(sizeof(struct ToLinkedListNode));
	head->next = NULL;
	return head;
}