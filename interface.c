//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#include "camada_dados.h"
#include "logica.h"
//directoria do ficheiro externo
char db[]="C:\\Users\\braza\\OneDrive\\Documentos\\GitHub\\Rastros\\db.txt";  // /home/runlo/LI2/Rastros/db.txt
                                             // C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\db.txt

// Funcao que desenha o tabuleiro
void desenha_tabuleiro(ESTADO *e){
    printf ("   A B C D E F G H \n");
    printf ("   _ _ _ _ _ _ _ _ \n");
    for(int l = 7; l >= 0; l--){
        printf("%d| ", l+1 );  //depois por (l+1)
        for(int c = 0; c < 8; c++) {
            if (e_branca(e , l ,c)) printf("* ");
            else if (c == 0 && l == 0) printf("1 ");
            else if (c == 7 && l == 7) printf("2 ");
            else if (e_preta(e , l ,c)) printf("# ");
            else printf(". ");
        }
        printf("\n");
    }
}

// ////////////////////////////////////////////////////////////////////////////
void imprime_estado(ESTADO *e,COORDENADA c){ //prompt pricipal
    printf("#  %d Jog:%d N:%d >>%c%d\n",get_Njogadas(e)+1 ,get_jogador(e),get_Njogadas(e),converte_numero(get_coluna(c)),get_linha(c)+1);

}
void imprime_estadoL(ESTADO *e){ //prompt do ler
    printf("#  %d Jog:%d N:%d \n",get_Njogadas(e)+1 ,get_jogador(e),get_Njogadas(e));

}
// FUNÇÔES DE MANUSEAMENTO DE FICHEIRO EXTERNO ///////////////////////////////////////////////////////////////

void grava_tabuleiro(ESTADO *e,FILE *filename){ // Função que grava o tabuleiro num dado ficheiro
    fprintf (filename,"   A B C D E F G H \n");
    fprintf (filename,"   _ _ _ _ _ _ _ _ \n");
    for(int l = 7; l >= 0; l--){
        fprintf(filename,"%d| ", l+1 );  //depois por (l+1)
        for(int c = 0; c < 8; c++) {
            if (e_branca(e , l ,c)) fprintf(filename,"* ");
            else if (c == 0 && l == 0) fprintf(filename,"1 ");
            else if (c == 7 && l == 7) fprintf(filename,"2 ");
            else if (e_preta(e , l ,c)) fprintf(filename,"# ");
            else fprintf(filename,". ");
        }
        fprintf(filename,"\n");
    }
}
void grava_estado(ESTADO *e,FILE *filename) {  // Função que grava o estado num dado ficheiro
    fprintf(filename,"#  %d Jog:%d N:%d\n",get_Njogadas(e)+1 ,get_jogador(e),get_Njogadas(e));
}

void gravar(ESTADO *e,const char *filename, const char *mode){
    FILE *fp;

    fp = fopen(filename,mode);
    grava_tabuleiro(e,fp);
    grava_estado(e,fp);

    fclose(fp);
}


/*OBJETIVOS DA FUNÇÂO LER:
 * dar scan linha a linha do ficheiro (inclui o tabuleiro e o prompt do estado) (done)
 * imprimir o mesmo simultânemanete                                   (done)
 * atualizar o estado para o estado do tabuleiro carregado        (done)
*/

void ler(ESTADO *e, const char *filename, const char *mode){
    FILE *fp;

    fp = fopen(filename,mode);

    char c;
    int l = 7, co = 0; //posição do canto superior esquerdo do tabuleiro
    for(int lTab=10;lTab>0;lTab--){ //lê cada linha do tabuleiro , acontagem das linhas vai de cima para baixo por uma questão de correspondência à imagem
        co = 0;
        for(int cTab=0;cTab<=19;cTab++){
            fscanf(fp,"%c",&c);
            if((c=='*' || c=='#' || c=='.' || c=='2' || c=='1') && cTab>3){
                novo_tabuleiro(e, l, co, c); // atualiza o estado do tabuleiro de acordo com o gravado no ficheiro
                co++;
            }
        }
        if (lTab <=8) l--;
    }

    int nComandos, jogador, nJogadas;
    fscanf(fp,"#  %d Jog:%d N:%d",&nComandos, &jogador, &nJogadas); //lê as informações do prompt
    novo_prompt(e, jogador, nJogadas); // atualiza o estado com a info do novo prompt

    fclose(fp);
}
// //////////////////////////////////////////////////////////////////////////////////////////////////
// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {

    char linha[BUF_SIZE];
    char col[2], lin[2],q,c1,c2,c3;
    while (jogada_possivel(e) == 1) {
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if(jogada_valida(e, coord) == 1) {
                jogar(e, coord);
                desenha_tabuleiro(e);
                imprime_estado(e,coord);
                printf("Digite um comando->");
            }else{
                printf("Faça uma jogada válida pf\n");       //se a jogada não for válida pede por uma jogada válida
                interpretador(e);
            }

        }
        else if(strlen(linha) == 3 && sscanf(linha,"%c%c",&c1,&c2) == 2 && c1=='g' && c2=='r'){
            gravar(e,db, "w");
            printf("Digite um comando->");
        }
        else if (strlen(linha) == 4 && sscanf(linha,"%c%c%c",&c1,&c2,&c3) == 3 && c1=='l' && c2=='e' && c3=='r'){
            ler(e, db, "r");  //lê o novo tabuleiro atualizando o respetivo estado
            desenha_tabuleiro(e);   //desenha um novo tabuleiro
            imprime_estadoL(e);
            printf("Digite um comando->");
        }

        else if(strlen(linha) == 2 && sscanf(linha, "%c",&q) == 1 && q=='q')      //comando de saída
            return 1;
        else
            printf("Digite um comando válido por favor!\n");

    }
    return 1;

}



// ////////////////////////  WORK IN PROGRESS //////////////////////////////////////////////


//Imprime jogadas efetuadas
void lista_movimentos(ESTADO *e){
    printf("\n");

    for(int i=01;i<=e->num_jogadas;i++){
        printf("%d:",i);
        for(int j=0;j<2;j++){

            printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha);
        }
        printf("\n");
    }
    printf("\n");
}





