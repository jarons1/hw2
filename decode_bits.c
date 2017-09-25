#include "bits.h"

void decode_bits(int ch){
  static int buff = 0;
  static int bits = CHAR_BIT-1;
  buff = buff * 2;
  buff = buff + ch-48;
  bits--;
  if (bits == -1){
    printf("%c", buff);
    buff = 0;
    bits = CHAR_BIT-1;
  }
}
int main(){
  int c;
  while ((c = getchar()) != EOF){
    if (!isspace(c) && 48 <= c && c <= 49){
      decode_bits(c);
    }
   }
}
