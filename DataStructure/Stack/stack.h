#ifndef __STACK_H_
#define __STACK_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
typedef struct Snode * PtrToSnode;
typedef BinTree ElementType;
struct Snode
{
	ElementType data;
	PtrToSnode next;
};
typedef PtrToSnode Stack;
Stack CreateStack();
bool IsEmpty(Stack s);
bool Push(Stack s,ElementType x);
ElementType Pop(Stack s);
#endif
