#include <stdio.h>
#include <string.h>
int Np, Ng;
void print(int rank[])
{
	printf("%d", rank[0]);
	int i;
	for(i = 1; i < Np; ++i)
		printf(" %d", rank[i]);
	printf("\n");
}
void solve(int mouse[], int stack[], int rank[])
{
	int top = Np - 1;
	if(top == 0){
		rank[0] = 1;
		return;
	}
	int now_rank, base;
	while(top > 0){
		now_rank = (top + 1)/ Ng + ((top + 1) % Ng == 0 ? 0 : 1) + 1;
		int count, max_index, max;
		int stack2[Np], top2;
		top2 = -1;
		for(base = 0; base <= top; base += Ng){
			max_index = stack[base];
			max = mouse[stack[base]];
			for(count = 1; count < Ng && (base + count) <= top; count++){
				if(mouse[stack[base + count]] > max){
					rank[max_index] = now_rank;
					max_index = stack[base + count];
					max = mouse[stack[base + count]];
				}else{
					rank[stack[base + count]] = now_rank;
				}
			}
			stack2[++top2] = max_index;
		}
		if(top2 == 0){
			rank[stack2[0]] = 1;
			break;
		}
		memcpy(stack, stack2, sizeof(int) * (top2 + 1));
		top = top2;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &Np, &Ng);
	int mouse[Np], stack[Np];
	int i;
	for(i = 0; i < Np; ++i)
		scanf("%d", &mouse[i]);
	for(i = 0; i < Np; ++i)
		scanf("%d", &stack[i]);
	int rank[Np];
	solve(mouse, stack, rank);
	print(rank);
	return 0;
}
