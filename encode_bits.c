#include "bits.h"

void print_bits(int ch){
  int count=0;
  int bin[CHAR_BIT];
  while (count < CHAR_BIT) {
     bin[count]= ch%2;
    //printf("%d", ch%2);
    ch = ch/2;
    count++;
  }
  int dig;
  for (int i = CHAR_BIT-1; i > -1; i--){
    dig = bin[i];
    printf("%d", dig);
  }
  
}

int main(){
  int c;
  while ((c = getchar()) != EOF){
    print_bits(c);
  }
}
