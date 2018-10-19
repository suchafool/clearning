#include <stdio.h>
#include <stdlib.h>

#define Max 10
#define Null -1
#define Tree int


struct TNode{
  int Data;
  int LChild;
  int RChild;
} T1[Max];

Tree BuildTree(struct TNode T[]){
  Tree root;
  int n, i;
  char cl, cr;
  int chk[Max] = {0};
 
  scanf("%d\n", &n);

  for(i = 0; i < n; i++){
    scanf("%c %c\n", &cl, &cr);
    
    T[i].Data = i;
    T[i].LChild = Null;
    T[i].RChild = Null;
    
    if(cl != '-'){
     T[i].LChild = cl - '0';
     chk[T[i].LChild] = 1;
    }
    if(cr != '-'){
     T[i].RChild = cr - '0';
     chk[T[i].RChild] = 1;
    }    
  }

  for(i = 0; i<n; i++){
    if (chk[i]==0){
      root = i;
      break;
    }
  }
  
  return root;
}

void ListLeaves(struct TNode T[], Tree root){
  int front, rear, tmp, count;
  int queue[Max];
  front = 0;
  rear = 0;
  count = 0;
  queue[rear] = root;
  rear++;
  
  while (front < rear){
    tmp = queue[front];
    front++;

    if(T[tmp].LChild == Null && T[tmp].RChild == Null){
      if(count > 0){
        printf(" ");
      }
      printf("%d", tmp);
      count++;
    }

    if(T[tmp].LChild != Null){
      queue[rear] = T[tmp].LChild;
      rear++;
    }
    if(T[tmp].RChild != Null){
      queue[rear] = T[tmp].RChild;
      rear++;
    } 
  }
}

int main(){

  Tree root = BuildTree(T1);

  ListLeaves(T1, root);

  return 0;
}














