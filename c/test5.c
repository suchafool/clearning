#include <stdio.h>

int main()
{
  int x, y;
  printf("Enter x and y: \n");
  scanf("%d %d",&x,&y);
  if(x>y)
    printf("max=%d \n", x);
  else
    printf("max=%d \n", y);
}
