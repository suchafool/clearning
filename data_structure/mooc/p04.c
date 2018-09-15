#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int Addr;
  int Data;
  int NAddr;
  struct Node* Next;
}LNode;


typedef LNode * List;

List Organize(LNode* input, int addr, int n){
  List head, rear;
  int idx = 0;
  head = (LNode *)malloc(sizeof(LNode));
  head -> Next = NULL;
  head -> NAddr = addr;
  rear = head;
  
  while(idx < n){
    for(int i = 0; i < n; i++){
      if(input[i].Addr == rear -> NAddr){
        rear -> Next = &input[i];
	rear = rear -> Next;
	break;
      }
    }

    idx++;
  }

  return head;  
}

void Print(LNode* tmp){
  if(tmp -> NAddr == -1){
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

  List list = Organize(input, addr, n);
  LNode* stack[k];

  int r = 0; 
  if (k > 0) 
    r = n / k * k;
  int c = 0;
  LNode * tmp = list -> Next;
  while(tmp){
    if(c >= r){
      Print(tmp);
      tmp = tmp -> Next;
      c++;
    }else{
      for(int j = 0; j < k; j++){
        stack[j] = tmp;
	tmp = tmp -> Next;
	c++;
      } 
      for(int j = k-1; j >= 0; j--){
        Print(stack[j]);
	stack[j] = NULL;
      } 
    }
  }

  return 0;
}
