#include <stdio.h>
char GetChar(int i);
int GetMaxIndex(float A[], int length);
int main(int argc, char const *argv[])
{
	float A1[3], A2[3], A3[3];
	int i;
	for(i = 0; i < 3; i++)
		scanf("%f", &A1[i]);
	for(i = 0; i < 3; i++)
		scanf("%f", &A2[i]);
	for(i = 0; i < 3; i++)
		scanf("%f", &A3[i]);
	int i1, i2, i3;
	float sum;
	i1 = GetMaxIndex(A1, 3);
	i2 = GetMaxIndex(A2, 3);
	i3 = GetMaxIndex(A3, 3);
	sum = (A1[i1] * A2[i2] * A3[i3] * 0.65 - 1) * 2;
	printf("%c %c %c %.2f\n", GetChar(i1), GetChar(i2), GetChar(i3), sum);
	return 0;
}

int GetMaxIndex(float A[], int length)
{
	int i, max = 0;
	int maxIndex;
	for(i = 0; i < length; i++){
		if(max < A[i]){
			max = A[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}
char GetChar(int i)
{
	if(i == 0)
		return 'W';
	else if(i == 1)
		return 'T';
	else 
		return 'L';
}