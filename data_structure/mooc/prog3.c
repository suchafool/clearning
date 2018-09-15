#include<stdio.h>
#include<stdlib.h>

typedef struct PNode {
  int Coef;
  int Expo;
  struct PNode* Link;
}PolyNode;

typedef PolyNode * Poly;


void Attach(int c, int e, Poly * rear){
  
  PolyNode* p = (PolyNode *)malloc(sizeof(PolyNode));
  p -> Link = NULL;
  p -> Coef = c;
  p -> Expo = e;

  (*rear) -> Link = p;
  *rear = p;
}

Poly Read(){
  int n, coef, expo;
  Poly poly, rear;
  poly = (PolyNode *)malloc(sizeof(PolyNode));
  poly -> Link = NULL;
  rear = poly;
  scanf("%d", &n);

  while(n>0){
    scanf("%d %d", &coef, &expo);
    Attach(coef, expo, &rear);
    --n;
  }

  rear = poly -> Link;
  free(poly);

  return rear;
}

void Print(Poly poly){
  int tag = 0;
  PolyNode* p = poly;

  if (p == NULL){
    printf("0 0\n");
    return;
  }


  while(p){
    if(tag) printf(" ");
    tag = 1;
    printf("%d %d", p -> Coef, p -> Expo);
    p = p -> Link;
  }
  printf("\n");
}

Poly Sum(Poly p1, Poly p2){
  Poly h, rear;
  int coef;
  
  h = (PolyNode *)malloc(sizeof(PolyNode));
  h -> Link = NULL;
  rear = h;
   
  while(p1 && p2){
    if(p1 -> Expo > p2 -> Expo){
      Attach(p1 -> Coef, p1 -> Expo, &rear);
      p1 = p1 -> Link;
    }else if(p1 -> Expo < p2 -> Expo){
      Attach(p2 -> Coef, p2 -> Expo, &rear);
      p2 = p2 -> Link;
    }else{
      coef = p1->Coef + p2->Coef;
      if(coef != 0){
        Attach(coef, p1->Expo, &rear);
      }
      p1 = p1 -> Link;
      p2 = p2 -> Link;
    }
  }

  while(p1){
    Attach(p1->Coef, p1->Expo, &rear);
    p1 = p1->Link;
  }
  while(p2){
    Attach(p2->Coef, p2->Expo, &rear);
    p2 = p2->Link;
  }

  rear = h->Link;
  free(h);

  return rear;
}

Poly Product(Poly p1, Poly p2){
  Poly p, tmp, c, tp1, tp2;
  p = NULL;
  tp1 = p1;
  while(tp1){
    tp2 = p2;
    while(tp2){
      c = (PolyNode *)malloc(sizeof(PolyNode));
      c -> Link = NULL;
      c -> Coef = tp1 -> Coef * tp2 -> Coef;
      c -> Expo = tp1 -> Expo + tp2 -> Expo;
      tmp = Sum(p, c);
      
      if(p != NULL) free(p);
      p = tmp;
      tp2 = tp2 -> Link;
    }
    tp1 = tp1 -> Link;
  }
  return p;
}


int main(){
  Poly p1  = Read();
  Poly p2 = Read();
  Poly prod = Product(p1,p2);
  Poly sum = Sum(p1, p2);
  Print(prod);
  Print(sum);
  return 0;
}
