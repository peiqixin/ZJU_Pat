#include "stack.h"
Stack CreateStack()
{
	Stack s = (PtrToSnode)malloc(sizeof(struct Snode));
	s->next = NULL;
	return s;
}
bool IsEmpty(Stack s)
{
	return (s->next == NULL);
}

bool Push(Stack s,ElementType x)
{
	PtrToSnode p;
	p=(PtrToSnode)malloc(sizeof(struct Snode));
	p->data = x;
	p->next = s->next;
	s->next = p;
	return true;
}
ElementType Pop(Stack s)
{
	if(IsEmpty(s)){
		printf("%s\n", "Stack is empty.");
		return -1;
	}
	PtrToSnode p = s->next;
	ElementType x;
	x = p->data;
	s->next = p->next;
	free(p);
	return x;
}