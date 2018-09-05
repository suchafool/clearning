#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node {
  DataType data;
  struct node * lchild, * rchild;
}BinTNode;

typedef BinTNode * BinTree;

