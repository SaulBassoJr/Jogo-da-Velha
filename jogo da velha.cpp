// (Jogo da Velha).

#include<stdio.h>
#include<stdlib.h>
#define N 3

int l, M;

void zeraTabuleiro(char Matriz[N][N]); // Zera e arruma o tabuleiro para o inicio do jogo
void Confere(char Matriz[N][N]);      // Confere o  vencedor
int Menu(int M);                    // Menu

int main(void) {
    char Matriz[N][N];  
    int j,i;   
    printf("  JOGO DA VELHA \n");
    printf("  JOGADOR 1 = O \n  JOGADOR 2 = X\n");
    
    zeraTabuleiro(Matriz);
   
    do{
	    l=0;
        while(l<=9){
            printf("\nINSIRA AS COORDENADAS: ");
            if(l%2)printf("JOGADOR 2\nLINHA: ");
            else printf("JOGADOR 1\nLINHA: ");
            
            scanf("%d",&i);
            printf("COLUNA: ");
            scanf("%d",&j);
            
		    if(Matriz[i-1][j-1]==' '){  // Arruma para que o usuario numere as linhas e colunas começando pelo numero 1
               if(l%2)Matriz[i-1][j-1]='x';
               else Matriz[i-1][j-1]='O';
               l++;
            }
  
           for(i = 0 ; i < N ; i++){   
                for(j = 0 ; j < N ; j++){
                    if(Matriz[i][j] ==' ')
                       printf("    ");
                    else
                        if(Matriz[i][j]=='x')
                            printf("  X ");				        
                        if(Matriz[i][j]=='O')
                        	printf("  O ");
                    if(j != (N-1))
                    printf("|");
                }
                printf("\n");
            }
        
		    Confere(Matriz);
		
		    if(l==9){ // Confere Empate 
               printf("\n\a\t\t PARTIDA EMPATADA\n");
               zeraTabuleiro(Matriz);
               M=Menu(M);
            }		  
        }
        system("cls");        
        printf("  JOGO DA VELHA \n");
        printf("  JOGADOR 1 = O \n  JOGADOR 2 = X\n");
    }while(M==1);
	system("cls");
	printf(" \n\a\t\t JOGO DA VELHA ENCERRADO \n\n");   
    system ("pause");
    return(0);
}

void zeraTabuleiro(char Matriz[N][N]){ // Zera e arruma o tabuleiro para o inicio do jogo
	int i, j;
	for(i=0;i<3;i++) 
        for(j=0;j<3;j++) 
            Matriz[i][j]=' ';
}

void Confere(char Matriz[N][N]){ // Confere o  vencedor
    int l=0;
	while(l<=9)  
        {
  
        if((Matriz[0][0]=='O' && Matriz[0][1]=='O' && Matriz[0][2]=='O')||
           (Matriz[1][0]=='O' && Matriz[1][1]=='O' && Matriz[1][2]=='O')||
           (Matriz[2][0]=='O' && Matriz[2][1]=='O' && Matriz[2][2]=='O')||
           (Matriz[0][0]=='O' && Matriz[1][0]=='O' && Matriz[2][0]=='O')||
           (Matriz[0][1]=='O' && Matriz[1][1]=='O' && Matriz[2][1]=='O')||
           (Matriz[0][2]=='O' && Matriz[1][2]=='O' && Matriz[2][2]=='O')||
           (Matriz[0][0]=='O' && Matriz[1][1]=='O' && Matriz[2][2]=='O')||
           (Matriz[0][2]=='O' && Matriz[1][1]=='O' && Matriz[2][0]=='O'))
        {
            printf("\n\a\t\tJogador 1, VOCE VENCEU!!!");
            M=Menu(l);
			l=10;
			zeraTabuleiro(Matriz);
        }
        if((Matriz[0][0]=='x' && Matriz[0][1]=='x' && Matriz[0][2]=='x')||
           (Matriz[1][0]=='x' && Matriz[1][1]=='x' && Matriz[1][2]=='x')||
           (Matriz[2][0]=='x' && Matriz[2][1]=='x' && Matriz[2][2]=='x')||
           (Matriz[0][0]=='x' && Matriz[1][0]=='x' && Matriz[2][0]=='x')||
           (Matriz[0][1]=='x' && Matriz[1][1]=='x' && Matriz[2][1]=='x')||
           (Matriz[0][2]=='x' && Matriz[1][2]=='x' && Matriz[2][2]=='x')||
           (Matriz[0][0]=='x' && Matriz[1][1]=='x' && Matriz[2][2]=='x')||
           (Matriz[0][2]=='x' && Matriz[1][1]=='x' && Matriz[2][0]=='x'))
        {
            printf("\n\a\t\tJogador 2, VOCE VENCEU!!!");
            M=Menu(l);
			l=10;
			zeraTabuleiro(Matriz);
        }
        l++;
    }	
}
int Menu(int M){ // Menu
	printf("\n  0 para sair\n  1 para continuar\n  :::");
	scanf ("%d", &M);
	if(M==1){
		l=10;
	    return(M);
    }
	else{
		l=10;
		return(M);
	}	
}
