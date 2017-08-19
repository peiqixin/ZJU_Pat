#include <stdio.h>
#include <stdlib.h>
int length_a, length_b;
typedef struct polynomial_node* PtrToPolyNode;
struct polynomial_node
{
	float coef;
	int expo;
	PtrToPolyNode next;
};

void insert(PtrToPolyNode poly, int expo, float coef);

PtrToPolyNode create_poly(int length)
{
	int i, expo;
	float coef;
	PtrToPolyNode poly = (PtrToPolyNode)malloc(sizeof(struct polynomial_node));
	poly->next = NULL;
	PtrToPolyNode ptr = poly;
	PtrToPolyNode new_node;
	for(i = 0; i < length; i++){
		scanf("%d %f", &expo, &coef);
		new_node = (PtrToPolyNode)malloc(sizeof(struct polynomial_node));
		new_node->expo = expo;
		new_node->coef = coef;
		new_node->next = NULL;
		ptr->next = new_node;
		ptr = ptr->next;
	}
	return poly;
}

PtrToPolyNode times(PtrToPolyNode poly_a, PtrToPolyNode poly_b)
{
	PtrToPolyNode poly_c = (PtrToPolyNode)malloc(sizeof(struct polynomial_node));
	poly_c->next = NULL;
	PtrToPolyNode ptr_poly_a = poly_a->next;
	PtrToPolyNode ptr_poly_b;
	int expo;
	float coef;
	while(ptr_poly_a != NULL){
		ptr_poly_b = poly_b->next;
		while(ptr_poly_b != NULL){
			coef = ptr_poly_a->coef * ptr_poly_b->coef;
			if(coef != 0){
				expo = ptr_poly_a->expo + ptr_poly_b->expo;
				insert(poly_c, expo, coef);
			}
			ptr_poly_b = ptr_poly_b->next;
		}
		ptr_poly_a = ptr_poly_a->next;
	}
	return poly_c;
}

void insert(PtrToPolyNode poly, int expo, float coef)
{
	PtrToPolyNode ptr = poly;
	PtrToPolyNode prev, new_node;
	if(ptr->next){
		// 指向链表头结点
		prev = ptr;
		// 指向链表第一个结点
		ptr = ptr->next;
		while(ptr && ptr->expo > expo){
			prev = ptr;
			ptr = ptr->next;
		}
		if(ptr == NULL){
			new_node = (PtrToPolyNode)malloc(sizeof(struct polynomial_node));
			new_node->expo = expo;
			new_node->coef = coef;
			new_node->next = NULL;
			prev->next = new_node;
		}// 插入结点的指数与当前结点指数不相等
		else if(ptr->expo != expo){
			new_node = (PtrToPolyNode)malloc(sizeof(struct polynomial_node));
			new_node->expo = expo;
			new_node->coef = coef;
			new_node->next = ptr;
			prev->next = new_node;
		}else{
			// 插入结点的指数与当前结点指数相等
			int new_coef = ptr->coef + coef;
			// 合并后系数为0
			if(new_coef == 0){
				prev->next = ptr->next;
			}else{
				// 合并后系数不为0
				ptr->coef = new_coef;
			}
		}
	}else{
		new_node = (PtrToPolyNode)malloc(sizeof(struct polynomial_node));
		new_node->expo = expo;
		new_node->coef = coef;
		new_node->next = NULL;
		ptr->next = new_node;
	}
}

int poly_length(PtrToPolyNode poly)
{
	int len = 0;
	PtrToPolyNode ptr = poly->next;
	while(ptr){
		len++;
		ptr = ptr->next;
	}
	return len;
}
void print_poly(PtrToPolyNode poly)
{
	int len = poly_length(poly);
	printf("%d", len);
	PtrToPolyNode ptr = poly->next;
	int i;
	for(i = 0; i < len; i++){
		printf(" %d %.1f", ptr->expo, ptr->coef);
		ptr = ptr->next;
	}
	printf("\n");
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/
int main(int argc, char const *argv[])
{
	scanf("%d", &length_a);
	PtrToPolyNode poly_a = create_poly(length_a);
	scanf("%d", &length_b);
	PtrToPolyNode poly_b = create_poly(length_b);
	PtrToPolyNode poly_c = times(poly_a, poly_b);
	print_poly(poly_c);
	return 0;
}