//
// Created by runlo on 09/03/20.
//

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

int jogar(ESTADO *e, COORDENADA c); // funcao que modifica o estado do jogo dependendo da jogada efetuada

int jogada_possivel(ESTADO *e); // funcao que verifica se o jogo continua ou ja acabou

int jogada_valida(ESTADO *e,COORDENADA coor); //verifica se a jogada é válida
#endif //___LOGICA_H___
