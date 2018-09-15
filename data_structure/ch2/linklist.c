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

void InsertList(LinkList head, int i, DataType x){
  ListNode *p,*s;
  int j;
  p=head;
  j=0;
  while(p!=NULL && j<i-1){
   p=p->next;
   ++j;
  }

  if(p==NULL){
    printf("Error\n");
    return;
  }
  else{
    s=(ListNode *)malloc(sizeof(ListNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
  }
}

DataType DeleteList(LinkList head, int i){
  ListNode *p, *s;
  DataType x;
  int j;
  p=head;
  j=0;
  while(p!=NULL&& j<i-1){
    p=p->next;
    ++j;
  }
  if(p==NULL){
    printf("error\n");
    exit(0);
  }
  else{
    s=p->next;
    p->next=s->next;
    x=s->data;
    free(s);
    return x;
  }
}

void Split(LinkList a, LinkList b){
  ListNode *p,*r,*s;
  p=a->next;
  r=a;
  s=b;
  while(p!=NULL){
    r->next=p;
    r=p;
    p=p->next;
    if(p!=NULL){
      s->next=p;
      s=p;
      p=p->next;
    }
  }

  r->next=NULL;
  s->next=NULL;
}


LinkList InsertListC(LinkList L, DataType x){
  ListNode *s, *p, *q;
  s=(ListNode*)malloc(sizeof(ListNode));
  s->data = x;
  p=L;
  q=p->next;
  while(q->data>x && q!=L){
    p=p->next;
    q=p->next;
  }

  p->next = s;
  s->next = q;

  return L;
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

  
  printf("\n------------------------\n");
  
  InsertList(list, 2, 'A');

  p = list->next;  //list with head, so...
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }
  
  printf("\n------------------------\n");
  
  DataType d=DeleteList(list, 2);
  printf("deleted:%c\n", d);

  p = list->next;  //list with head, so...
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }
  
  printf("\n------------------------\n");
  LinkList list2=(ListNode*)malloc(sizeof(ListNode));  
  Split(list, list2);
  
  printf("After split, list1:\n");
  p = list->next;  //list with head, so...
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }

  printf("\nlist2:\n");
  p = list2->next;  //list with head, so...
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }
  printf("\n------------------------\n");

  printf("please enter: 4321\n");

  list = CreateListR1();
  
  p = list->next;
  while(p != NULL){
    printf("%c\t", p->data);
    p = p->next;
  }
  printf("\n------------------------\n");
  
  p = GetNodei(list, 4);
  
  if (p != NULL){
    printf("node 4 = %c\n", p->data);
  }else{
    printf("node 4 not exists.");
    return 0;
  }
  
  p->next = list;

  list = InsertListC(list, '6');
  list = InsertListC(list, '8');
  list = InsertListC(list, '5');
  list = InsertListC(list, '7');

  
  p = list->next;
  while(p != list){
    printf("%c\t", p->data);
    p = p->next;
  }
  printf("\n------------------------\n");


  return 0;
}










