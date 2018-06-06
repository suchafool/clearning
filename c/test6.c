#include <stdio.h>

int main()
{
  int x;
  printf("Please input x:\n");
  scanf("%d", &x);
  switch(x/10)
  {
    case 10:
    case 9:
       printf("x=%d -> A \n", x);
    break;
    case 8:
      printf("x=%d -> B \n", x);
      break;
    case 7:
    case 6:
      printf("x=%d -> C \n", x);
    break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
      printf("x=%d -> D\n", x);
    break;
    default:
      printf("x=%d -> data error! \n", x);
    break;
  }
    
}
