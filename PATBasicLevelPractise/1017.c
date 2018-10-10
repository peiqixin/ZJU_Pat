#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  char str[1010], str2[1010];
  int b, i, count = 0, r = 0;
  scanf("%s %d", str, &b);
  for(i = 0; i < strlen(str); ++i){
    r = r * 10 + (str[i] - '0');
    str2[count++] = r / b + '0';
    r %= b;
  }
  str2[count] = '\0';
  i = 0;
  if(strlen(str2) > 1)
    for(i = 0; str2[i] == '0'; i++);
  printf("%s %d\n", str2 + i, r);
  return 0;
}
