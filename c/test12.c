#include <stdio.h>

int max(int a, int b);

int main()
{
  int a,b;
  printf("Enter a b:");
  scanf("%d %d", &a, &b);

  printf("max = %d \n", max(a,b));
}

int max(int a,int b)
{
  int p;
  p=a>b?a:b;
  return p;
}
