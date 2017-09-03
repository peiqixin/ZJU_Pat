#include <stdio.h>
#include <string.h>

#define MAX 55
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int i, shuffle[MAX], card_index[MAX], pre_card_index[MAX];

	for(i = 0; i < MAX; i++)
		pre_card_index[i] = i;

	for(i = 1; i < MAX; i++)
		scanf("%d", &shuffle[i]);

	int j;
	for(j = 0; j < N; j++){
		for(i = 1; i < MAX; i++){
			card_index[shuffle[i]] = pre_card_index[i];
		}
		memcpy(pre_card_index, card_index, sizeof(card_index));
	}
	
	char card[55][4] = {" ", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};
	printf("%s", card[card_index[1]]);
	for(i = 2; i < 55; i++)
		printf(" %s", card[card_index[i]]);
	printf("\n");
	return 0;
}