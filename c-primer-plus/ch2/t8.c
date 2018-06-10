#include <stdio.h>

int main(void)
{
  int a,b;
  
  a=5;
  b=2;
  printf("%d, %d \n",b, a);
  b=a;
  printf("%d, %d \n",b, a);
  a=b;
  printf("%d, %d \n",b, a);

  return 0;
}
