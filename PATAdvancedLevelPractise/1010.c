#include <stdio.h>
#include <math.h>
#include <string.h>
// https://github.com/wlh320/shuaOJ/blob/master/PAT/advanced/1010.cpp
int tag, radix;
char str1[11], str2[11];

long long int GetNumber(char str[], int radix)
{
  int len = strlen(str);
  int i;
  long long int num = 0;
  for(i = 0; i < len; i++){
    if(str[i] >= '0' && str[i] <= '9')
      num += pow(radix, len - i - 1) * (str[i] - '0');
    else
      num += pow(radix, len - i - 1) * (str[i] - 'a' + 10);
  	if(num < 0)
  		return -1;
  }
  return num;
}

int main(int argc, char const *argv[])
{
  scanf("%s %s %d %d", str1, str2, &tag, &radix);
  if(tag == 2){
    char Temp[11];
    strcpy(Temp, str2);
    strcpy(str2, str1);
    strcpy(str1, Temp);
  }
  long long int N1 = GetNumber(str1, radix);
  int radixNotKnow;
  int i, len;
  len = strlen(str2);
  char Max = '0';
  for(i = 0; i < len; i++)
    if(str2[i] > Max)
      Max = str2[i];
  if(Max <= '9')
    radixNotKnow = Max - '0' + 1;
  else
    radixNotKnow = Max - 'a' + 11;
  long long int MaxR = N1 + 1;
  while(radixNotKnow <= MaxR)
  {
    long long int MidR = (MaxR + radixNotKnow) / 2;
    long long int N2 = GetNumber(str2, MidR);
    if(N2 == -1 || N1 < N2)
      MaxR = MidR - 1;
    else if(N1 > N2)
      radixNotKnow = MidR + 1;
    else if(N1 == N2)
    {
      printf("%lld\n", MidR);
      return 0;
    }
  }
  printf("Impossible\n");
  return 0;
}