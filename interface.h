//
// Created by runlo on 09/03/20.
//

#ifndef ___INTERPRETADOR_H___
#define ___INTERPRETADOR_H___

void desenha_tabuleiro(ESTADO *e); // funcao que desenha o tabuleiro com o estado atual do jogo
void grava_tabuleiro(ESTADO *e,FILE *filename);

//COMANDOS
void imprime_estado(ESTADO *e,COORDENADA c);
void lista_movimentos(ESTADO *e);
void gravar(ESTADO *e,const char *filename, const char *mode);
void ler(const char *filename, const char *mode);

// /////////////////////////////////////////////////////////////////////////////////////
//INTERPRETADOR

int interpretador(ESTADO *e); // funcao que interpretada o comando dado e atualiza o estado do jogo de acordo


#endif //___INTERPRETADOR_H__
