// 1002 
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* PtrToPolyNode;
struct PolyNode{
	int expo;
	float coef;
	PtrToPolyNode Next;
};

PtrToPolyNode CreatePolynomial();
PtrToPolyNode NewNode(int expo, float coef);
PtrToPolyNode Add(PtrToPolyNode Head_a, PtrToPolyNode Head_b);
int Length(PtrToPolyNode Head);
void Print(PtrToPolyNode Head);

int main(int argc, char const *argv[])
{
	PtrToPolyNode Head_a, Head_b, Head_c;
	Head_a = CreatePolynomial();
	Head_b = CreatePolynomial();
	Head_c = Add(Head_a, Head_b);
	Print(Head_c);
	return 0;
}

PtrToPolyNode CreatePolynomial()
{
	int N;
	scanf("%d", &N);
	int i;
	PtrToPolyNode Head, newNode;
	Head = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
	Head->Next = NULL;
	PtrToPolyNode p = Head;
	int expo;
	float coef;
	for(i = 0; i < N; i++){
		scanf("%d %f", &expo, &coef);
		newNode = NewNode(expo, coef);
		p->Next = newNode;
		p = newNode;
	}
	return Head;
}
PtrToPolyNode NewNode(int expo, float coef)
{
	PtrToPolyNode newNode = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
	newNode->expo = expo;
	newNode->coef = coef;
	newNode->Next = NULL;
	return newNode;
}

PtrToPolyNode Add(PtrToPolyNode Head_a, PtrToPolyNode Head_b)
{
	PtrToPolyNode ha, hb, Head_c, p, newNode;
	ha = Head_a->Next;
	hb = Head_b->Next;
	Head_c = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
	Head_c->Next = NULL;
	p = Head_c;
	while(ha && hb){
		if(ha->expo > hb->expo){
			newNode = NewNode(ha->expo, ha->coef);
			ha = ha->Next;
			p->Next = newNode;
			p = newNode;
		}else if(ha->expo < hb->expo){
			newNode = NewNode(hb->expo, hb->coef);
			hb = hb->Next;
			p->Next = newNode;
			p = newNode;
		}else{
			// 当指数相同时，并且系数相加不为0时，才连接到链表后面
			if((ha->coef + hb->coef) != 0){
				newNode = NewNode(ha->expo, ha->coef + hb->coef);
				p->Next = newNode;
				p = newNode;
			}
			ha = ha->Next;
			hb = hb->Next;
		}
	}
	if(ha){
		p->Next = ha;
	}
	if(hb){
		p->Next = hb;
	}
	return Head_c;
}

int Length(PtrToPolyNode Head)
{
	PtrToPolyNode p = Head->Next;
	int length = 0;
	while(p){
		length++;
		p = p->Next;
	}
	return length;
}

void Print(PtrToPolyNode Head)
{
	PtrToPolyNode p = Head->Next;
	int length = Length(Head);
	printf("%d", length);
	while(p){
		printf(" %d %.1f", p->expo, p->coef);
		p = p->Next;
	}
	printf("\n");
}