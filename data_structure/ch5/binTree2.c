#include "binTree.h"

extern void PreOrder(BinTree bt);
extern void InOrder(BinTree bt);
extern void PostOrder(BinTree bt);

BinTree CreateBinTree(BinTree bt){
  BinTNode * Q[100];
  BinTNode * s;
  int front, rear;
  char ch;
  ch = getchar();
  bt = NULL;
  front = 1;
  rear = 0;
  while(ch != '#'){
    s = NULL;
    if(ch != '@'){
      s = (BinTNode *)malloc(sizeof(BinTNode));
      s->data = ch;
      s->lchild = s->rchild = NULL;
    }
    rear++;
    Q[rear]=s;
    if(rear == 1){
      bt = s;
    }
    else{
      if (s != NULL && Q[front] != NULL)
        if (rear % 2 == 0)
	  Q[front]->lchild = s;
	else
	  Q[front]->rchild = s;

      if(rear % 2 != 0)
        front++;
    }
    ch = getchar();
  }

  return bt;
}

int main(){
  BinTree btree;

  btree = CreateBinTree(btree);

  printf("PreOrder: ");
  PreOrder(btree);

  printf("\nInOrder: ");
  InOrder(btree);

  printf("\nPostOrder: ");
  PostOrder(btree);

  printf("\ndone\n");

  return 0;
}
