#include<stdio.h>

int main(void){
  int input_matrix[5][5]; 
  for(int i = 0;i<5;i++){
    for(int j = 0; j<5;j++){
      scanf("%d",&input_matrix[i][j]);
    }
  }
  
  int satır_toplam = 0;
  for (int a = 0; a<5; a++){
    int satır_toplam = 0;
    for (int b = 0; b<5; b++){
      satır_toplam += input_matrix[a][b];
    }
    for (int c = 0; c<5; c++){
      input_matrix[c][a] += satır_toplam;
    }
  }
 
 int sütun_toplam = 0 ;
 for (int a = 0; a<5; a++){
    int sütun_toplam  = 0;
    for (int b = 0; b<5; b++){
      sütun_toplam += input_matrix[b][a];
    }
    for (int c = 0; c<5; c++){
      input_matrix[a][c] += sütun_toplam ;
    }
  }
  
  //printing
  for(int i = 0;i<5;i++){
    for(int j = 0; j<5;j++){
      printf("%d ",input_matrix[i][j]);
    }
    puts("\n");
  }
}
