#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraordinary being."
int main()
{
  char name[40];
  printf("what is your name? \n");
  scanf("%s", name);
  printf("Hello, %s, %s\n", name, PRAISE);
  printf("Your name has %zd letters, and occupies %zd memory cells.\n", strlen(name), sizeof name);

  printf("The phrase of  praise has %zd letters, ", strlen(PRAISE));

  printf("and occupies %zd memory cells.", sizeof PRAISE);

  return 0;
}
