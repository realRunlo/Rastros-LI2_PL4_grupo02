//
// Created by runlo on 09/03/20.
//

/**
@file camada_dados.h
Definição do estado e das funções que o manipulam
 */

#ifndef ___CAMADADEDADOS_H___
#define ___CAMADADEDADOS_H___

// conjunto de tipos utilizados para armazenamento e edicao dos dados do estado do jogo

/**
\brief Tipo de dados para a casa
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef JOGADA *POINTER;

/**
\brief Tipo de dados para o estado
*/
typedef struct{
    /** O tabuleiro*/
    CASA tab[8][8];
    /** Coordenada da ultima jogada*/
    COORDENADA ultima_jogada;
    /** Jogadas efetuadas*/
    JOGADAS jogadas;
    /** Número de jogadas*/
    int num_jogadas;
    /** Jogador atual*/
    int jogador_atual;
    /** Número de comandos excutados*/
    int num_comandos;

    POINTER pt;
} ESTADO;

// //////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Inicializa o estado*/
ESTADO *inicializar_estado(); // funcao que da o estado inicial do jogo

/** \brief Converte um número para a letra correspondente
 * @param x Número a converter*/
char converte_numero(int x); // funcao que torna um numero de uma coluna numa letra


/** \brief Converte uma letra no seu numero correspondente
 * @param x Letra a converter*/
int converte_letra(char x); // funcao que torna uma letra num numero

/** \brief Verifica se uma casa tem peca branca
 * @param e Apontador para o estado
 * @param l Linha da casa
 * @param c Coluna da casa*/
int e_branca(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca branca

/** \brief Verifica se uma casa é preta
 * @param e Apontador para o estado
 * @param l Linha da casa
 * @param c Coluna da casa*/
int e_preta(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca preta


/** \brief Verifica se uma casa é vazia
 * @param e Apontador para o estado
 * @param l Linha da casa
 * @param c Coluna da casa*/
int e_vazio(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca vazio

/** \brief Altera uma casa para branca
 * @param e Apontador para o estado
 * @param l Linha da casa
 * @param c Coluna da casa*/
void set_branca(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca branca

/** \brief Altera uma casa para preta
 * @param e Apontador para o estado
 * @param l Linha da casa
 * @param c Coluna da casa*/
void set_preta(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca preta

/** \brief Altera uma casa para vazia
 * @param e Apontador para o estado
 * @param l Linha da casa
 * @param c Coluna da casa*/
void set_vazio(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca vazio

/** \brief Retorna o jogador atual
 * @param e Apontador para o estado*/
int get_jogador(ESTADO *e); //funcao que retorna o numero do jogador atual

/** \brief Retorna o número de jogadas
 * @param e Apontador para o estado*/
int get_Njogadas(ESTADO *e);//retorna o número de jogadas



/** \brief Retorna o número de comandos
 * @param e Apontador para o estado*/
int get_Ncomandos(ESTADO *e);//retorna o número de comandos

/** \brief Retorna o número da coluna de uma coordenada
 * @param e Apontador para o estado*/
int get_coluna(COORDENADA c); // retorna o número da coluna de uma coordenada

/** \brief Retorna o número da linha de uma coordenada
 * @param e Apontador para o estado*/
int get_linha(COORDENADA c); // retorna o número da linha de uma coordenada

/** \brief Altera o numero do jogador atual
 * @param e Apontador para o estado
 * @param j Jogador anterior*/
int set_jogador(ESTADO *e, int j); //funcao que atualiza o numero do jogador atual

/** \brief Altera o número de jogadas
 * @param e Apontador para o estado
 * @param j Número de jogadas anterior*/
int set_nJogadas(ESTADO *e, int nJ);//atualiza o número de jogadas

/** \brief Altera o número de comandos
 * @param e Apontador para o estado
 * @param nj Número de comandos anterior*/
int set_nComandos(ESTADO *e, int nJ);//atualiza o número de comandos

/** \brief Altera as coordenadas da ultima jogada
 * @param e Apontador para o estado
 * @param l Linha da casa da jogada
 * @param c Coluna da casa da jogada*/
void set_ultima_jogada(ESTADO *e, int l, int c); //Funcao que modifica as coordenadas da ultima jogada


/** \brief Adiciona na lista de jogadas a ultima jogada feita
 * @param e Apontador para o estado
 * @param l Linha da jogada
 * @param c Coluna da jogada
 * @param jogador Jogador que efetuou a jogada*/
void adiciona_lista_jogadas(ESTADO *e, int l, int c, int jogador); // funcao que adiciona na lista de jogadas a ultima jogada feita


/** \brief Adiciona 1 ao numero de jogadas
 * @param e Apontador para o estado*/
void add_numjogadas(ESTADO *e); //Adiciona 1 ao numero de jogadas

/** \brief Adiciona 1 ao numero de comandos
 * @param e Apontador para o estado*/
void add_numcomandos(ESTADO *e); //Adiciona 1 ao numero de comandos

/** \brief Atualiza o tabuleiro no estado de acordo com o que esta gravado no ficheiro externo
 * @param e Apontador para o estado
 * @param l Linha da jogada
 * @param c Coluna da jogada
 * @param x Caracter nessa casa*/
void novo_tabuleiro(ESTADO *e, int l, int c, char x); // atualiza o tabuleiro no estado de acordo com o que esta gravado no ficheiro de texto


//funcao que modifica o estado da jogada efetuada numero j
void set_jogada_efetuada(ESTADO *e, int j, int jogada, char coluna, int linha);

#endif //___CAMADADEDADOS_H__
