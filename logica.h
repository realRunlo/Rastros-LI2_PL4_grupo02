
#ifndef ___LOGICA_H___
#define ___LOGICA_H___

int jogar(ESTADO *e, COORDENADA c); // funcao que modifica o estado do jogo dependendo da jogada efetuada

// /////////////////////////////////////////////////////////////////////////////////////////////////
int espaco_vazio(ESTADO *e);

int espaco_vitoria(ESTADO *e);

int jogada_possivel(ESTADO *e); // funcao que verifica se o jogo continua ou ja acabou

int jogada_valida(ESTADO *e,COORDENADA c); //verifica se a jogada é válida
#endif //___LOGICA_H___
