#include<stdio.h>
#include<stdlib.h>


int check(int* pop, int N, int M){
  int stack[M];
  int i, j, top;
  j = 1;
  top = 0;
  
  for(i = 0; i < N;){
    //pop[i];
    for(; j <= pop[i] && top < M; j++){
      //printf("push %d", j);
      stack[top] = j;
      top++;
    }
    
    if(stack[top-1] != pop[i]){
      return 0;
    }

    while(top > 0 && stack[top - 1] == pop[i]){
      //printf("pop %d", stack[top - 1]);
      top--;
      i++;
    }
  }

  if(top == 0){
    return 1;
  }

  return 0;
}

int main(){
  int M, N, K;
  
  scanf("%d %d %d", &M, &N, &K);
  int pops[K][N];
  int i, j, result;

  for (i = 0; i < K; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &pops[i][j]);
    }   
  }

  for(i = 0; i < K; i++){
    
    //printf("\n------------------------------\n");  
    result = check(pops[i], N, M); 
    
    if(result){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }

  return 0;
}

