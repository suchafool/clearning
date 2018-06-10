#include <stdio.h>

void butler(void);

int main(void)
{
  printf("I will summon the butler function.\n");
  butler();
  printf("Yes, bring me some tea and writable DVDs. \n");

  return 0;
}

void butler(void)
{
  printf("you rang, sir?\n");
}
