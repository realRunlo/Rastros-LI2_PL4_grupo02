//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <string.h>
#define BUF_SIZE 1024
#include "camada_dados.h"
#include "logica.h"

//directoria do ficheiro externo
//char db[]="/home/runlo/LI2/Rastros/db.txt";  // /home/runlo/LI2/Rastros/db.txt
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
void imprime_estadoI(ESTADO *e){ //prompt só para o estado inicial
    printf("#  %d Jog:%d N:%d \n",get_Ncomandos(e) ,get_jogador(e),get_Njogadas(e));

}
void imprime_estado(ESTADO *e,COORDENADA c){ //prompt
    printf("#  %d Jog:%d N:%d >>%c%d\n",get_Ncomandos(e) ,get_jogador(e),get_Njogadas(e),converte_numero(get_coluna(c)),get_linha(c)+1);

}

// //////////////////////// Listar movimentos //////////////////////////////////////////////

//Imprime a jogada efetuada numero i no ficheiro
void flista_ronda(ESTADO *e,int i,FILE *filename){
    if(i==get_Njogadas(e)-1)
        fprintf(filename,"%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha);
    else{
        fprintf(filename,"%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha);
        fprintf(filename,"%c%d",converte_numero(e->jogadas[i+1].jogador2.coluna),e->jogadas[i+1].jogador2.linha);
    }

}

//Imprime jogadas efetuadas no ficheiro
void flista_movimentos(ESTADO *e,FILE *filename){
    int j=1;
    fprintf(filename,"\n");
    for(int i=0;i<(get_Njogadas(e));i++){
        fprintf(filename,"%d%d:",0,j);
        flista_ronda(e,i,filename);
        i++;j++;
        fprintf(filename,"\n");
    }
}



//Imprime a jogada efetuada numero i
void lista_ronda(ESTADO *e,int i){
    if(i==get_Njogadas(e)-1)
        printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha);
    else{
        printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha);
        printf("%c%d",converte_numero(e->jogadas[i+1].jogador2.coluna),e->jogadas[i+1].jogador2.linha);
    }

}


//Imprime jogadas efetuadas
void lista_movimentos(ESTADO *e){
    int j=1;
    printf("\n");
    for(int i=0;i<(get_Njogadas(e));i++){
        printf("0%d:",j);
        lista_ronda(e,i);
        i++;j++;
        printf("\n");
    }
}





// FUNÇÔES DE MANUSEAMENTO DE FICHEIRO EXTERNO ///////////////////////////////////////////////////////////////

void grava_tabuleiro(ESTADO *e,FILE *filename){ // Função que grava o tabuleiro num dado ficheiro
    for(int l = 7; l >= 0; l--){
        for(int c = 0; c < 8; c++) {
            if (e_branca(e , l ,c)) fprintf(filename,"*");
            else if (c == 0 && l == 0) fprintf(filename,"1");
            else if (c == 7 && l == 7) fprintf(filename,"2");
            else if (e_preta(e , l ,c)) fprintf(filename,"#");
            else fprintf(filename,".");
        }
        fprintf(filename,"\n");
    }
}



//culminar da grava_tabuleiro e grava_estado
void gravar(ESTADO *e,const char *filename, const char *mode){
    FILE *fp;

    fp = fopen(filename,mode);
    grava_tabuleiro(e,fp);
    flista_movimentos(e,fp);

    fclose(fp);
}


void ler(ESTADO *e, const char *filename, const char *mode){
    FILE *fp;

    fp = fopen(filename,mode);

    char crt;
    int l,c,feitas = 0 ; //posição do canto superior esquerdo do tabuleiro
    for(l=7;l>=0;l--){ //lê cada linha do tabuleiro , a contagem das linhas vai de cima para baixo por uma questão de correspondência à imagem
        for(c=0;c<=8;c++){
            fscanf(fp,"%c",&crt);
            if (crt == '#') feitas++;
            novo_tabuleiro(e,l,c,crt);
        }
    }
    set_nJogadas(e, feitas);
    int jogadas_1,jogadas_2;
    if (feitas % 2 == 1) jogadas_1 = (feitas + 1) / 2;
    else jogadas_1 = feitas / 2;
    jogadas_2 = feitas - jogadas_1;

    fscanf(fp,"\n");
    int jogada = 0;
    int cl;
    char cc;
    int num_jogadas1 = 1 , num_jogadas2 = 1;
    fscanf(fp,"01:");
    for(int i = 0; i != 1;){
        if (num_jogadas1 < jogadas_1){
            fscanf(fp,"%c%d ",&cc,&cl);
            set_jogada_efetuada(e,1,jogada,cc,cl);
            jogada++;
            num_jogadas1++;
        }
        else {
            fscanf(fp,"%c%d\n",&cc,&cl);
            set_jogada_efetuada(e,1,jogada,cc,cl);
            i = 1;
        }
    }
    printf("\n\n");
    jogada = 0;
    fscanf(fp,"02:");
    for(int i = 0; i != 1;){
        if (num_jogadas2 < jogadas_2){
            fscanf(fp,"%c%d ",&cc,&cl);
            set_jogada_efetuada(e,2,jogada,cc,cl);
            jogada++;
            num_jogadas2++;
        }
        else {
            fscanf(fp,"%c%d\n",&cc,&cl);
            set_jogada_efetuada(e,2,jogada,cc,cl);
            i = 1;
        }
    }
    if (num_jogadas1 > num_jogadas2) set_jogador(e,2);
    else set_jogador(e,1);
    fclose(fp);
}
// //////////////////////////////////////////////////////////////////////////////////////////////////

// Função de interface,que permite a intereção com os jogadores
int interpretador(ESTADO *e) {

    char linha[BUF_SIZE];
    char col[2], lin[2],q,c1,c2,c3,c4;
    char filename[50];
    while (jogada_possivel(e) == 1) {
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if(jogada_valida(e, coord) == 1) {
                jogar(e, coord);
                desenha_tabuleiro(e);
                imprime_estado(e,coord);

            }else{
                printf("Faça uma jogada válida pf\n");       //se a jogada não for válida pede por uma jogada válida
                add_numcomandos(e);
                imprime_estado(e,coord);
                interpretador(e);
                return 1;
            }

        }
        else if(sscanf(linha,"%c%c%c%s", &c1, &c2, &c3, filename) == 4 && c1=='g' && c2=='r' && c3 == ' '){
            gravar(e,filename,"w");
            printf("O seu jogo foi salvo!\n");
        }
        else if (sscanf(linha,"%c%c%c%c%s",&c1,&c2,&c3,&c4,filename) == 5 && c1=='l' && c2=='e' && c3=='r' && c4 == ' '){
            ler(e,filename, "r");  //lê o novo tabuleiro atualizando o respetivo estado
            desenha_tabuleiro(e);   //desenha um novo tabuleiro
            imprime_estadoI(e);

        }
        else if (sscanf(linha,"%c%c%c%c",&c1,&c2,&c3,&c4) == 4 && c1=='m' && c2=='o' && c3=='v' && c4 == 's'){
            lista_movimentos(e);
        }

        else if(strlen(linha) == 2 && sscanf(linha, "%c",&q) == 1 && q=='q')      //comando de saída
            return 1;
        else
            printf("Digite um comando válido por favor!\n");

        if(jogada_possivel(e) == 1) printf("Digite um comando->");
        else return 1;  //este return é de forma a não haver a repetição do jogada_possivel na quebra do ciclo
        add_numcomandos(e);
    }

}






