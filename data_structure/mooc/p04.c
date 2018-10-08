#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int Addr;
  int Data;
  int NAddr;
  struct Node* Next;
}LNode;


typedef LNode * List;


LNode * Find(LNode* input, int addr, int n){
  if (addr == -1){
    return NULL;
  }

  for(int i = 0; i < n; i++){
    if(input[i].Addr == addr){
      return &input[i];
    }
  }

  return NULL;
}

List Organize(LNode* input, int addr, int n, int k){
  List head, rear, tmp;
  int last = addr;
  int idx = 0;
  head = (LNode *)malloc(sizeof(LNode));
  head -> Next = NULL;
  head -> NAddr = 0;
  rear = head;

  LNode* stack[k];
  int top = 0;

  while(idx < n){
    while(top < k){
      tmp = Find(input, last, n);
      if(tmp == NULL){
        idx = n;
	break;
      }
      last = tmp -> NAddr;
      //printf("find: %05d %d %05d\n", tmp->Addr, tmp->Data, tmp->NAddr);
      stack[top] = tmp;

      top++;
      idx++;
    }

    if(top == k){
      while(top > 0){
        top--;
        rear -> NAddr = stack[top] -> Addr;
	      rear -> Next = stack[top];
	      rear = stack[top];
      }
    }else{
      for(int i = 0; i < top; i++){
        rear -> NAddr = stack[i] -> Addr;
	      rear -> Next = stack[i];
	      rear = stack[i];
      }
    }
  }
  rear -> NAddr = -1;
  rear -> Next = NULL;

  return head;
}

void Print(LNode* tmp){
  if(tmp -> Next == NULL){
    printf("%05d %d %d\n", tmp -> Addr, tmp -> Data, tmp -> NAddr);
  }else{
    printf("%05d %d %05d\n", tmp -> Addr, tmp -> Data, tmp -> NAddr);
  }
}

int main(){
  int addr, n, k;
  scanf("%d %d %d", &addr, &n, &k);

  LNode * input = (LNode *)malloc(n * sizeof(LNode));

  for(int i = 0; i < n; i++){
    input[i].Next = NULL;
    scanf("%d %d %d", &input[i].Addr, &input[i].Data, &input[i].NAddr);
  }

  List list = Organize(input, addr, n, k);

  LNode * tmp = list -> Next;
  while(tmp){
    Print(tmp);
    tmp = tmp -> Next;
  }

  return 0;
}
