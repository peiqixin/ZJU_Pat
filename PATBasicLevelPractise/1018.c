#include <stdio.h>
void count(char c, int a[])
{
  if(c == 'B'){
    a[0]++;
  }else if(c == 'C'){
    a[1]++;
  }else{
    a[2]++;
  }
}
char most(int a[])
{
  int most_win_a = a[0], i;
  char most_a = 'B';
  for(i = 1; i < 3; i++){
    if(a[i] > most_win_a){
      most_win_a = a[i];
      most_a = (i == 1) ? 'C' : 'J';
    }
  }
  return most_a;
}

int main(int argc, char const *argv[]) {
  int N, i, win_count, lose_count, tie_count, a[3] = {0}, b[3] = {0};
  win_count = lose_count = tie_count = 0;
  char x1, x2;
  scanf("%d\n", &N);
  for(i = 0; i < N; ++i){
    scanf("%c %c\n", &x1, &x2);
    if((x1 == 'C' && x2 == 'J') || (x1 == 'J' && x2 == 'B') || (x1 == 'B' && x2 == 'C')){
      win_count++;
      count(x1, a);
    }else if((x1 == 'C' && x2 == 'C') || (x1 == 'J' && x2 == 'J') || (x1 == 'B' && x2 == 'B')){
      tie_count++;
    }else{
      lose_count++;
      count(x2, b);
    }
  }
  printf("%d %d %d\n", win_count, tie_count, lose_count);
  printf("%d %d %d\n", lose_count, tie_count, win_count);
  char most_a = most(a), most_b = most(b);
  printf("%c %c\n", most_a, most_b);
  return 0;
}
