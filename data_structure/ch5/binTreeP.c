#include "binTree.h"

void PreOrder(BinTree bt){
  if(bt != NULL){
    printf("%c", bt->data);
    PreOrder(bt->lchild);
    PreOrder(bt->rchild);
  }
}

void InOrder(BinTree bt){
  if(bt != NULL){
    InOrder(bt->lchild);
    printf("%c", bt->data);
    InOrder(bt->rchild);
  }
}

void PostOrder(BinTree bt){
  if(bt != NULL){
    PostOrder(bt->lchild);
    PostOrder(bt->rchild);
    printf("%c", bt->data);
  }
}
