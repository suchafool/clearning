#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

typedef struct dlnode{
  DataType data;
  struct dlnode * prior, *next;
} DLNode;

typedef DLNode * DLinkList;

void DLInsert(DLNode *p, DataType x){
  DLNode *s =(DLNode *) malloc(sizeof(DLNode));
  s->data = x;
  
  s->prior = p->prior;
  s->next = p;

  p->prior->next = s;
  p->prior = s; 
}

DataType DLDelete(DLNode *p){
  DataType x = p->data;

  p->next->prior = p->prior;
  p->prior->next = p->next;

  free(p);

  return x;
}

int main(){
  
  DLinkList head = (DLNode *)malloc(sizeof(DLNode));

  /*for(int i=0;i<5;i++){
    DLInsert(head,i);
  }

  DLNode* p = head->next;
  while(p->next != NULL){
    printf("%d \t", p->data);
    p = p->next;
  }*/


  return 0;
}


