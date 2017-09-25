#include "getnum.h"

long dec(int c, int f){
  static long count = 0;
  if (f == 1){
    count = 0;
    return 0;
  }
  count = count * 10;
  count = count + (c-48);
  return count;
}
long oct(int c, int f){
  static long count = 0;
  if (f == 1){
    count = 0;
    return 0;
  }
  count = count * 8;
  count = count + (c-48);
  return count;
}
long hex(int c, int f){
  static long count = 0;
  if (f == 1){
    count = 0;
    return 0;
  }
  count = count * 16;
  if (48 <= c && c <= 57){
  count = count + (c-48);
  }
  else if (65 <= c && c <= 70){
    count = count + (c-55);
  }
  else if (97 <= c && c <= 102){
    count = count + (c-87);
  }
    return count;
}
long bin(int c, int f){
  static long count= 0;
  if (f == 1){
    count = 0;
    return 0;
  }
  count = count * 2;
  count = count + (c-48);
  return count;
}     
   
long getnum(void){
  static int neg = 0;
  long ret;
  static int c = 45;
  while (c != EOF){
    c = getchar();
    if (c == 45){
      neg = 1;
      getnum();
    }
      if (c == 48){ //if first is 0
	c = getchar();
	if (c == 98){ //then b
	  c = getchar();
	  while (!isspace(c) && c != EOF){
	    ret = bin(c, 0);
	    c = getchar();
	  }
	  if (neg == 1){
	    printf("%s%ld%s\n", "-", ret, " bin");
	    bin(c, 1);
	    neg = 0;
	    getnum();
	  }
	  else {
	    printf("%ld%s\n", ret, " bin");
	    bin(c, 1);
	    neg = 0;
	    getnum();
	  }
	
	}//end binary
	else if (c == 120){ //hex
	  c = getchar();
	  while (!isspace(c) && c != EOF){
	    ret = hex(c, 0);
	    c = getchar();
	  }
	  if (neg == 1){
	    printf("%s%ld%s\n", "-", ret, " hex");
	    hex(c, 1);
	    neg = 0;
	    getnum();
	  }
	  else {
	    printf("%ld%s\n", ret, " hex");
	    hex(c, 1);
	    neg = 0;
	    getnum(); 
	  }
	}
	else if (48 <= c && c <= 55){ //oct
 	  while (!isspace(c) && c != EOF){
	    ret = oct(c, 0);
	    c = getchar();
	  }
	  if (neg == 1){
	    printf("%s%ld%s\n", "-", ret, " oct");
	    oct(c, 1);
	    neg = 0;
	    getnum();
	  }
	  else {
	    printf("%ld%s\n", ret, " oct");
	    oct(c, 1);
	    neg = 0;
	    getnum();
	  }
	}
	else if (isspace(c)){
	  printf("%d%s\n", 0, " dec");
	    return 0;
	}
      }	
      if (49 <= c && c <= 57){ //if first is dec
	while (!isspace(c) && c != EOF){
	  ret = dec(c, 0);
	  c = getchar();
	}
	if (neg == 1){
	  printf("%s%ld%s\n", "-", ret, " dec");
	  dec(c, 1);
	  neg = 0;
	  getnum();
	}
	else {
	  printf("%ld%s\n", ret, " dec");
	  dec(c, 1);
	  neg = 0;
	  getnum();
	}
      }
      /*  else{
	while (!isspace(c) && c != EOF){
	  c = getchar();
	}
	printf("%s", "ERROR");
	getnum();
      }
      */ }
  return 1; 
}
	 
int main(){
    getnum();
  return 1;
}
