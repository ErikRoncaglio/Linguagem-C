#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linhas, colunas;

int menu() {
  int n = 0;
  printf("\n\n\n----------BATALHA NAVAL----------");
  printf("\n\n\n\n\n          1- Novo Jogo ");
  printf("\n\n\n\n\n          2- Sair \n\n");
  scanf("%d", &n);
  return n;
}
void mostrar_tabuleiro(char tabuleiro[][colunas]){
    for (int i = 0; i < linhas; i++) {
      printf("\n");
      for (int j = 0; j < colunas; j++) {
        printf("| %c ", tabuleiro[i][j]);
      }
      }
}

void mostrar_tabuleiro_jogo(char tabuleiro_jogo[][colunas], int mun){
  int n=0, n1=0;
    printf("\n\n%d/30\n", mun);
    for (int i = 0; i < linhas; i++) {
      if(n1==0){   
           for (int k = 0; k < colunas; k++) {
             if(k==0){
          printf("     %d", n);
               }
             else{
              printf("   %d", n); 
             }
             n++;
             }
          printf("\n");
            n1++;
        }
      printf("\n");
         printf("%d- ", i);    
      for (int j = 0; j < colunas; j++) { 
        printf("| %c ", tabuleiro_jogo[i][j]);
}
      }
  }

int verificar(char tabuleiro[][colunas]){
  int n=0;
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if(tabuleiro[i][j]!='~'){
        n++;        
      }
    }
  }
  if(n==15){
      n=1;
    }
  return n;
}

void porta_av(char tabuleiro[][colunas]){
  int a1=0, x=0, n=0, n1 = 0, n2 = 0, n3 = 0, a = 0, n4=0;
  n=linhas*colunas;
  n2=rand()%n;
  x=n2;
  // 0-horizontal 1-vertical
  n3=rand()%2;
  // linha porta aviões
  if (n3 == 0) {
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        if (n1 == n2) {
          tabuleiro[i][j] = 'P';
          a=j;
          a1=j;
          for (int k = 0; k < 4; k++) {
            a++;
            if (a < colunas) {
              tabuleiro[i][a] = 'P';
            } 
            else {
              a1-=1;
              tabuleiro[i][a1] = 'P';
            }
          }
        }
        n1 += 1;
      }
    }
  }
  else {   // coluna porta aviões
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        if (n1 == n2) {
          tabuleiro[i][j] = 'P';
          a=i;
          a1=i;
          for (int k = 0; k < 4; k++) {
             a++;
            if (a < linhas) {
              tabuleiro[a][j] = 'P';
            } else {
              a1-=1;
              tabuleiro[a1][j] = 'P';
            }
          }
        }
         n1 += 1;
      }
    }
  }
  }
void cruzador(char tabuleiro[][colunas]){
 int a1=0, n=0, n1 = 0, n2 = 0, n3 = 0, a = 0, n4=0;
  while (n4!=1){
  n4=0;
   n1=0;
    n3=0;
    n=linhas*colunas;
  n2=rand()%n;
  n3=rand()%2; // 0-horizontal 1-vertical
  // linha cruzador
  if (n3 == 0) {
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=j+1;
          a1=j- 1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[i][a]=='~' && tabuleiro[i][a1]=='~' && a1>=0 && a<colunas) {
            tabuleiro[i][j] = 'C'; 
            tabuleiro[i][a1] = 'C';
            tabuleiro[i][a] = 'C';
              n4++;
                }
                n1 += 1;
                }
              }
            }
  else {   // coluna cruzador
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=i+1;
          a1=i- 1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[a][j]=='~' && tabuleiro[a1][j]=='~' && a1>=0 && a<=linhas) {
            tabuleiro[i][j] = 'C'; 
            tabuleiro[a1][j] = 'C';
             tabuleiro[a][j] = 'C';
            n4++;
          }
          n1 += 1;
        }
      }
    }
  }
}
void rebocador(char tabuleiro[][colunas]){
  int a1=0, n=0, n1 = 0, n2 = 0, n3 = 0, a = 0, n4=0;
   while (n4!=1){
  n4=0;
   n1=0;
    n3=0;
     n=linhas*colunas;
  n2=rand()%n;
  n3=rand()%2; // 0-horizontal 1-vertical
  // linha rebocador
  if (n3 == 0) {
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=j+1;
          a1=j- 1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[i][a]=='~' && tabuleiro[i][a1]=='~' && a1>=0 && a<colunas) {
            tabuleiro[i][j] = 'R'; 
            tabuleiro[i][a1] = 'R';
            tabuleiro[i][a] = 'R';
              n4++;
                }
                n1 += 1;
                }
              }
            }
  else {   // coluna rebocador
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=i+1;
          a1=i- 1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[a][j]=='~' && tabuleiro[a1][j]=='~' && a1>=0 && a<=linhas) {
            tabuleiro[i][j] = 'R'; 
            tabuleiro[a1][j] = 'R';
             tabuleiro[a][j] = 'R';
            n4++;
          }
          n1 += 1;
        }
      }
    }
  }
    n4=0;
}
void submarino(char tabuleiro[][colunas]) {
  int n=0, n1 = 0, n2 = 0, n3 = 0, a = 0, n4=0;
  while (n4!=1){
  n4=0;
   n1=0;
    n3=0;
    n=linhas*colunas;
  n2=rand()%n;
  n3=rand()%2; // 0-horizontal 1-vertical
  // linha submarino
  if (n3 == 0) {
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=j+1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[i][a]=='~' && a<colunas) {
            tabuleiro[i][j] = 'S'; 
            tabuleiro[i][a] = 'S';
              n4++;
                }
                n1 += 1;
                }
              }
            }
  else {   // coluna submarino
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=i+1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[a][j]=='~' && a<=linhas) {
            tabuleiro[i][j] = 'S'; 
             tabuleiro[a][j] = 'S';
            n4++;
          }
          n1 += 1;
        }
      }
    }
  }
 n4=0;
  }
void zubmarino(char tabuleiro[][colunas]) {
  int n=0, n1 = 0, n2 = 0, n3 = 0, a = 0, n4=0;
  while (n4!=1){
  n4=0;
   n1=0;
    n3=0;
    n=linhas*colunas;
  n2=rand()%n;
  n3=rand()%2; // 0-horizontal 1-vertical
  // linha submarino
  if (n3 == 0) {
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=j+1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[i][a]=='~' && a<colunas) {
            tabuleiro[i][j] = 'Z'; 
            tabuleiro[i][a] = 'Z';
              n4++;
                }
                n1 += 1;
                }
              }
            }
  else {   // coluna submarino
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         a=i+1;
        if (n1 == n2 && tabuleiro[i][j]=='~' && tabuleiro[a][j]=='~' && a<=linhas) {
            tabuleiro[i][j] = 'Z'; 
             tabuleiro[a][j] = 'Z';
            n4++;
          }
          n1 += 1;
        }
      }
    }
  }
 n4=0;
  }
  
void win(char tabuleiro_jogo[][colunas], int mun){
  int n=0;
   for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
          if (tabuleiro_jogo[i][j]=='P' || tabuleiro_jogo[i][j]=='C' || tabuleiro_jogo[i][j]=='Z' || tabuleiro_jogo[i][j]=='R' || tabuleiro_jogo[i][j]=='S')
            n++;
          }  
}
  if(n==15){
     printf("\n\n  ---------------------------YOU WIN---------------------------");
  }
  else if(mun==0 && n!=15){
    printf("\n\n  ---------------------------GAME OVER---------------------------");
  }
}

void atirar(char tabuleiro[][colunas], char tabuleiro_jogo[][colunas]){
  int tiro=0, lin, col, mun=30, s=0, p=0, z=0, c=0, r=0, n=0;
  while(mun!=0){
  printf("\n\n  Informe as coordenadas do tiro:");
    scanf("%d%d", &lin, &col);
    if(tabuleiro_jogo[lin][col]=='~'){
  if(tabuleiro[lin][col]=='~'){
    tabuleiro_jogo[lin][col]='O';
  }
  else{
    tabuleiro_jogo[lin][col]='X';
    if(tabuleiro[lin][col]=='P'){
      p++;
    }
   else if(tabuleiro[lin][col]=='C'){
      c++;
    }
    else if(tabuleiro[lin][col]=='R'){
      r++;
    }
    else if(tabuleiro[lin][col]=='S'){
      s++;
    }
    else if(tabuleiro[lin][col]=='Z'){
      z++;
    } 
    if(p==5){

      for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
          if (tabuleiro[i][j]=='P'){ 
            tabuleiro_jogo[i][j]='P';
        }
      }
    }
      }
    if(c==3){
      for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
          if (tabuleiro[i][j]=='C')
            tabuleiro_jogo[i][j]='C';
        }
      }
    }
    if(r==3){
      for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
          if (tabuleiro[i][j]=='R')
            tabuleiro_jogo[i][j]='R';
        }
      }
    }
    if(s==2){
      for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
          if (tabuleiro[i][j]=='S')
            tabuleiro_jogo[i][j]='S';
        }
      }
    }
    if(z==2){
      for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
          if (tabuleiro[i][j]=='Z')
            tabuleiro_jogo[i][j]='S';
        }
      }
    }
    }
      }
    else{
      printf("  Tiro repetido, digite novamente:");
    }    
    mun--;
     mostrar_tabuleiro_jogo(tabuleiro_jogo, mun);
   win(tabuleiro_jogo, mun);
    }
}
void organizar_barcos(int linhas, int colunas, char tabuleiro[][colunas]) {
  int n = 0, n1 = 0, n2 = 0, n3 = 0, a = 0, a1=0, x=0, n4=0, n5=0;  
while(n5!=1){

  n5=0;
  n4=0;
   
  porta_av(tabuleiro);
  cruzador(tabuleiro);
  rebocador(tabuleiro);
  submarino(tabuleiro);
  zubmarino(tabuleiro);
  
  if(verificar(tabuleiro)==1)
    n5++; 
}
  }

int main() {
    srand(time(NULL));
  int x = 0;

  while (menu() == 1) {
    printf("    Informe o tamanho do tabuleiro (7x7 - 15x15): ");
    scanf("%d%d", &linhas, &colunas);
    char tabuleiro[linhas][colunas];
     for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      tabuleiro[i][j] = '~';
    }
  }
    char tabuleiro_jogo[linhas][colunas];
     for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      tabuleiro_jogo[i][j] = '~';
    }
  }
    organizar_barcos(linhas, colunas, tabuleiro);
    atirar(tabuleiro, tabuleiro_jogo);
   
    }
  return 0;
  }