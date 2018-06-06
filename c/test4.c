#include <stdio.h>

int main()
{
  int x, y, t;

  printf("Enter x and y: \n");
  scanf("%d %d", &x, &y);
  t = x;
  x = y;
  y = t;

  printf("x=%d, y=%d \n", x, y);
}
