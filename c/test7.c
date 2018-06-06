#include <stdio.h>

int main()
{
  int i, n;
  long s;
  s=1;
 
  i=1;
  printf("Please input n: ");
  scanf("%d", &n);
  
  do{
    s*=i;
    i++;
  }while(i<=n);

  printf("%d!=%ld\n",n,s);

}
