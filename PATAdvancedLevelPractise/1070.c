#include <stdio.h>
// 测试点3 供 < 求
// 测试点2 库存也有可能是小数。
int main(int argc, char const *argv[])
{
	int N, D;
	scanf("%d %d", &N, &D);
	float inventory[N];
	float totalPrice[N];
	int i;
	for(i = 0; i < N; i++)
		scanf("%f", &inventory[i]);
	for(i = 0; i < N; i++)
		scanf("%f", &totalPrice[i]);
	float price[N];
	for(i = 0; i < N; i++)
		price[i] = totalPrice[i] / inventory[i];

	float tot = 0;
	while(D > 0)
	{
		float maxPrice = 0;
		float inv;
		int maxIndex = -1;
		for(i = 0; i < N; i++)
			if(price[i] > maxPrice && inventory[i] > 0)
			{
				maxPrice = price[i];
				inv = inventory[i];
				maxIndex = i;
			}
		//  供不应求
		if(maxIndex == -1) break;
		if(D >= inv){
			tot += totalPrice[maxIndex];
			D -= inv;
			inventory[maxIndex] = 0;
		}
		else{
			tot += maxPrice * D;
			D = 0;
		}
	}
	printf("%0.2f\n", tot);
	return 0;
}