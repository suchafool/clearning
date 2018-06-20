#include <stdio.h>
#define PI 3.141593
int main()
{
  int number = 7 ;
  float pies = 12.75;
  int cost = 7800;

  printf("The %d contestants ate %f of berry pies. \n", number, pies);
  printf("The PI is %f \n", PI);
  printf("Fare well! thou art too dear for my possessing.\n");

  printf("%c%d\n", '$', 2* cost);

  return 0;  
}
