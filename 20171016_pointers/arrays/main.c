# include <stdio.h>
# include <stdlib.h>
# include "helper.h"

 
int main(void)
{
  int a = 1;
  int b = 2;
  printf("a = %d\n", a);
  printf("b = %d\n", b);
 
  swap(&a, &b);
 
  printf("a = %d\n", a);
  printf("b = %d\n", b);
 
  return 0;
}
