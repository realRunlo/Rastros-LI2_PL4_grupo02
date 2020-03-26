//
// Created by runlo on 09/03/20.
//
/**
@file interface.h
Funçoes que interpretam os comandos dados pelo jogador.
*/

#ifndef ___INTERPRETADOR_H___
#define ___INTERPRETADOR_H___

/**
 * \brief Funçao que desenha o tabuleiro de acordo com o estado dado.
 * @param e Apontador para o estado.
 */
void desenha_tabuleiro(ESTADO *e); // funcao que desenha o tabuleiro com o estado atual do jogo


/**
 * \brief Funçao que grava o tabuleiro, num ficheiro .txt especificado, de acordo com o estado atual do jogo.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro onde se guardara o tabuleiro.
 */
void grava_tabuleiro(ESTADO *e,FILE *filename);

//COMANDOS

/**
 * \brief Funçao que desenha o prompt do jogo de acordo com o estado atual
 * @param e Apontador para o estado.
 * @param c A coordenada.
 */
void imprime_estado(ESTADO *e,COORDENADA c);

void imprime_estadoI(ESTADO *e);




/**
 * \brief Funçao que grava num documento .txt especificado o tabuleiro do estado atual e o respetivo prompt.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro .txt onde se ira gravar tabuleiro e o prompt.
 * @param mode Modo de uso do ficheiro, dado ao fopen, por exemplo para escrever ou apenas para leitura.
 */
void gravar(ESTADO *e,const char *filename, const char *mode);


/**
 * \brief Funçao que le o tabuleiro e respetivo prompt de um ficheiro .txt especificado.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro .txt onde se ira ler tabuleiro e o prompt.
 * @param mode Modo de uso do ficheiro, neste caso, read.
 */
void ler(ESTADO *e, const char *filename, const char *mode);

// /////////////////////////////////////////////////////////////////////////////////////
//INTERPRETADOR

/**
 * \brief Funçao principal deste modulo, que recolhe o comando dado pelo jogador e o executa.
 * Comandos :
 * jogada (linha, coluna): executa a funçao jogar para, se possivel realizar a jogada desejada.
 * gr: grava o estado atual do jogo num ficheiro .txt aparte para futura continuaçao do jogo se desejado.
 * ler: altera o estado do jogo para o gravado num ficheiro .txt para continuar o jogo neste guardado.
 * q: termina o jogo.
 * @param e Apontador para o estado.
 * @return 1 Caso o jogo continue.
 * @return 0 Caso o jogo termine.
 */
int interpretador(ESTADO *e); // funcao que interpretada o comando dado e atualiza o estado do jogo de acordo




/**
 * \brief Funçao nao terminada que ira imprimir os movimentos ja realizados no jogo.
 * @param e Apontador para o estado.
 */
void flista_movimentos(ESTADO *e,FILE *filename);



void flista_ronda(ESTADO *e,int i,FILE *filename);//funcao que imprime a jogada efetuada numero i no ficheiro



void lista_movimentos(ESTADO *e);//funcao que imprime a lista de movimentos efetuados



void lista_ronda(ESTADO *e,int i);//funcao que imprime a jogada efetuada numero i

int pos (ESTADO *e, int nrJ);



#endif //___INTERPRETADOR_H__
