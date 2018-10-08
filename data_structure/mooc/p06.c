#include<stdio.h>

#define ElementType char
#define MaxTree 10
#define Null -1
#define Tree int

struct TreeNode{
  ElementType Data;
  Tree Left;
  Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]){
  int i, N, Root = Null;
  char cl, cr, cd;
  int check[MaxTree];

  scanf("%d\n", &N);
  printf("N = %d\n", N);
  if(N){
    for(i = 0; i < N; i++) 
    	check[i] = 0;

    for(i = 0; i < N; i++){
      scanf("%c %c %c\n", &cd, &cl, &cr);
      printf("data %d: %c \t %c \t %c\n", i, cd, cl, cr);
      T[i].Data = cd;
      if (cl != '-'){
        T[i].Left = cl - '0';
	check[T[i].Left] = 1;
      }
      else{
      	T[i].Left = Null;
      }

      if (cr != '-'){
        T[i].Right = cr - '0';
	check[T[i].Right] = 1;
      }
      else{
        T[i].Right = Null;
      }
    }

    for(i = 0; i < N; i++){
      if(check[i] == 0){
        break;
      }
    }
    Root = i;
  }

  return Root;
}

int Isomorphic(Tree R1, Tree R2){
  //printf("comparing: %d --- %d\n", R1, R2);
  if (R1 == Null && R2 == Null)
    return 1;
  
  if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
    return 0;

  if (T1[R1].Data != T2[R2].Data)
    return 0;

  if (T1[R1].Left == Null && T2[R2].Left == Null)
    return Isomorphic(T1[R1].Right, T2[R2].Right);

  if ((T1[R1].Left != Null) && (T2[R2].Left != Null) &&
       T1[T1[R1].Left].Data == T2[T2[R2].Left].Data)
    return (Isomorphic(T1[R1].Left, T2[R2].Left) &&
            Isomorphic(T1[R1].Right, T2[R2].Right));
  else
    return (Isomorphic(T1[R1].Left, T2[R2].Right) &&
            Isomorphic(T1[R1].Right, T2[R2].Left));
}


int main(){
  Tree R1, R2;
  
  R1 = BuildTree(T1);
  R2 = BuildTree(T2);

  if (Isomorphic(R1, R2))
    printf("Yes");
  else
    printf("No");

  /*
  printf("\n------------\n");
  for (int i=0;i<8;i++){
    printf("%c %d %d\n", T1[i].Data, T1[i].Left, T1[i].Right);
  }
  printf("\n------------\n");

  printf("\n------------\n");
  for (int i=0;i<8;i++){
    printf("%c %d %d\n", T2[i].Data, T2[i].Left, T2[i].Right);
  }
  printf("\n------------\n");
  */
  return 0;
}



