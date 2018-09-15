#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Read(){
    int count, tmp;
    PtrToNode p, l, h;
    scanf("%d", &count);
    h = (PtrToNode)malloc(sizeof(struct Node));
    h -> Data = 0;
    h -> Next = NULL;
    l = h;

    for(int i=0;i<count;i++){
       scanf("%d", &tmp);
       p = (PtrToNode)malloc(sizeof(struct Node));
       p -> Data = tmp;
       p -> Next = NULL;

       l -> Next = p;
       l = p;
    }

    return h;
}

void Print(List L){
  PtrToNode p = L -> Next;
  if(p == NULL){
    printf("NULL\n");
    return;
  }
  while(p){
    printf("%d ", p -> Data);
    p = p->Next;
  }

  printf("\n");
}

List Merge(List L1, List L2){
  PtrToNode p, h, h1, h2;
  h1 = L1 -> Next;
  h2 = L2 -> Next;

  L1 -> Next = NULL ;
  L2 -> Next = NULL;

  h = (PtrToNode)malloc(sizeof(struct Node));
  h -> Data = 0;
  h -> Next = NULL;
  p = h;
  while(h1 && h2){
    if ( h1 -> Data <= h2 -> Data){
      p -> Next = h1;
      p = h1;
      h1 = h1 -> Next;
    }else{
      p -> Next = h2;
      p = h2;
      h2 = h2-> Next;
    }
  } 

  if(h1) p->Next = h1;
  if(h2) p->Next = h2;

  return h;
}
