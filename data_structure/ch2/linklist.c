#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node{
  DataType data;
  struct node * next;
}ListNode;

typedef ListNode * LinkList;


LinkList CreateListF(){
  LinkList head;
  ListNode * p;
  char ch;
  head = NULL;
  ch = getchar();
  while(ch!='\n'){
    p=(ListNode *)malloc(sizeof(ListNode));
    p->data = ch;
    p->next = head;
    head = p;
    ch = getchar();
  }

  return head;
}

LinkList CreateListR(){
  LinkList head,rear;
  ListNode *p;
  char ch;
  head = NULL;
  rear = NULL;
  ch = getchar();
  while( ch != '\n'){
    p = (ListNode *) malloc(sizeof(ListNode));
    p->data = ch;
    if(head == NULL)
      head = p;
    else
      rear->next = p;
    rear = p;
    ch = getchar();
  }

  if(rear != NULL)
    rear->next = NULL;
  return head;
}

LinkList CreateListR1(){
  LinkList head = (ListNode *) malloc(sizeof(ListNode));
  ListNode *p, *r;
  r = head;
  char ch=getchar();
  while(ch != '\n'){
    p = (ListNode*) malloc(sizeof(ListNode));
    p->data = ch;
    r->next = p;
    r = p;
    ch = getchar();
  }

  r->next = NULL;
  return head;
}

ListNode * GetNodei(LinkList head, int i){
  ListNode *p;
  int j;

  p=head->next; 
  j=1;
  while(p!=NULL && j<i){
    p=p->next;
    ++j;
  }

  if(j==i){
    return p;
  }

  return NULL;
}

ListNode * LocateNodek(LinkList head, DataType k){
  ListNode *p=head->next;
  while(p != NULL && p->data != k){
    printf("[%c  %c]\n", p->data, k);
    p=p->next;
  }

  return p;
}

int main(){
 
  LinkList list = CreateListF();
  
  ListNode* p = list;
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }
  printf("\n------------------------\n");
  
  list = CreateListR();
  p = list;
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }

  printf("\n------------------------\n");

 
  list = CreateListR1();
  p = list->next;  //list with head, so...
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }
  
  printf("\n------------------------\n");

  p = GetNodei(list, 3);
  if(p != NULL){
    printf("%c\n", p->data);
  }
  else {
    printf("not found!\n");
  }
  
  printf("\n------------------------\n");

  p = LocateNodek(list, '3');
  if(p != NULL){
    printf("%c\n", p->data);
  }
  else {
    printf("not found!\n");
  }

  return 0;
}
